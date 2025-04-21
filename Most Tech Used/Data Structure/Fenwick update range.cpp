struct FenwickRange{
    int n;
    vector<int>m,c;
    FenwickRange(int _n): n(_n), m(n+1,0) , c(n+1,0) {}
    void update(int pos,int mVal,int cVal){for(++pos;pos<=n;pos+=pos&-pos){m[pos-1]+=mVal;c[pos-1]+=cVal; }}
    int query(int pos){ int x=pos,ret = 0; for(pos++;pos;pos-=pos&-pos){ ret+=m[pos-1]*x+c[pos-1];} return ret; }
    void addRange(int l,int r,int value) { update(l,value,-value*(l-1)); update(r+1,-value,value*r); }
    int rangeQuery(int l, int r){ return query(r) - query(l-1); }
};