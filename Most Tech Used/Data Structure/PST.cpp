struct node {
    ll sum = 0;
    const node *left , *right;
    node(){}
    node(ll _sum) : sum(_sum) , left(nullptr) , right(nullptr){}
};
 
struct persistentSegTree {
 
private:
 
    node* versions[M];
    node D = node (0); // for default values
    int N, ID = 0;
 
    void merge(node* res , const node* l , const node* r){
        res->sum = l->sum + r->sum;
        res->left = l;
        res->right = r;
    }
 
    void build(const vector<ll>& arr , node* curNode , int left , int right){
        if(left == right){
            *curNode = left <= arr.size() ? node(arr[left-1]) : D;
        }else{
            node *leftNode = new node();
            node *rightNode = new node();
            int mid = (left + right) >> 1;
            build(arr , leftNode , left , mid);
            build(arr , rightNode , mid +1 , right);
            merge(curNode , leftNode , rightNode);
        }
    }
 
    void build(node* curNode , int left , int right){
        if(left == right){
            *curNode = D;
        }else{
            node *leftNode = new node();
            node *rightNode = new node();
            int mid = (left + right) >> 1;
            build(leftNode , left , mid);
            build(rightNode , mid +1 , right);
            merge(curNode , leftNode , rightNode);
        }
    }
 
    node query(const node* curNode , int l , int r , int ql , int qr){
        if(l > qr || r < ql) return D;
        if(l >= ql && r <= qr) return *curNode;
        int mid = (l + r) >> 1;
        node leftAns = query(curNode->left , l , mid , ql , qr);
        node rightAns = query(curNode->right , mid +1 , r , ql , qr);
        node res (0);
        merge(&res , &leftAns , &rightAns);
        return res;
    }
 
    void update(node* newNode , const node* oldNode , int l , int r , int i , ll v , bool t){
        if(l == r){
            newNode->sum = oldNode->sum * t + v;
        }
        else{
            int mid = (l + r) >> 1;
            if(i <= mid){ // go left
                node* newLeft = new node();
                update(newLeft , oldNode->left , l , mid , i , v , t);
                merge(newNode , newLeft , oldNode->right);
            }
            else{ // go right
                node* newRight = new node();
                update(newRight , oldNode->right , mid +1 , r , i , v , t);
                merge(newNode , oldNode->left , newRight);
            }
        }
    }
 
public:
    persistentSegTree (int n){
        N = 1;
        while(N < n) N <<= 1;
        node* root = new node();
        build(root , 0 , N - 1);
        versions[ID++] = root;
    }
    persistentSegTree (const vector<ll>& arr){
        int n = arr.size();
        N = 1;
        while(N < n) N <<= 1;
        node* root = new node();
        build(arr , root , 0 , N - 1);
        versions[ID++] = root;
    }
 
    ll query (int versionID , int left , int right){
        node res = query(versions[versionID] , 0 , N - 1 , left , right);
        return res.sum;
    }
 
    void update (int versionID , int idx , ll val , bool type = 0){ // type 0 => assign , 1 => increament
        node* newRoot = new node();
        update(newRoot , versions[versionID] , 0 , N - 1 , idx , val , type);
        versions[ID++] = newRoot;
    }
 
    void updateInPlace (int versionID , int idx , ll val , bool type = 0){ // type 0 => assign , 1 => increament
        node* newRoot = new node();
        update(newRoot , versions[versionID] , 0 , N - 1 , idx , val , type);
        versions[versionID] = newRoot;
    }
 
    void update (int idx , ll val , bool type = 0){ // update last version
        update(ID - 1 , idx , val , type);
    }
};