struct BIT{
    int N;
    vector<int>tree;
    void init(int x){
        N=1ll<<x;
        tree.resize(1ll<<x);
    }
    void add(int pos,int value){
        for(++pos;pos<=N;pos+=pos&-pos){
            tree[pos-1]+=value;
        }
    }
    int get(int pos){
        int sum=0;
        for(++pos;pos;pos-=pos&-pos){
            sum+=tree[pos-1];
        }
        return sum;
    }
    int find(int t){
        int st=0;
        for(int sz=N>>1;sz;sz>>=1){
            if(tree[st+sz-1]<t){
                t-=tree[(st+=sz)-1];
            }
        }
        return st;
    }
};
struct MultiSet{
    BIT bit;
    MultiSet(int x){
        bit.init(x);
        bit.add(0,-1);
    }
    void insert(int value){
        bit.add(value,1);
    }
    void erase(int value){
        bit.add(value,-1);
    }
    int count(int value){
        return bit.get(value)-bit.get(value-1);
    }
    int at(int index){
        return bit.find(index);
    }
    int size(){
        return bit.get(bit.N-1)+1;
    }
};