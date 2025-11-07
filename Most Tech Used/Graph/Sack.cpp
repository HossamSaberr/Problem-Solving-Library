int a[N] , sz[N] , heavy[N] , freq[N] , ans[N] , dep[N] , n , m;
vector<vector<int>> adj;
vector<vector<pair<int , int>>> query;

void sack(int u , int par) {
    sz[u] = 1;
    heavy[u] = 0;
    for(auto v : adj[u]) {
        if(v != par) {
            dep[v] = dep[u] + 1;
            sack(v , u);
            sz[u] += sz[v];
            if(heavy[u] == 0 || sz[v] > sz[heavy[u]])
                heavy[u] = v;
        }
    }
}

void apply(int u , int op) { // just change this function
    freq[dep[u]] ^= (1ll << a[u]); 
}

void update(int u , int par , int op) {
    apply(u , op);
    for(auto v : adj[u]) {
        if(v != par)
            update(v , u , op);
    }
}

void dfs(int u , int par , bool keep) {
    // go to light child first
    for(auto v : adj[u]) {
        if(v != par && v != heavy[u])
            dfs(v , u , 0);
    }
    // add heavy now
    if(heavy[u])
        dfs(heavy[u] , u , 1);
    // add the node
    apply(u , 1ll);
    // add the light child to the DS
    for(auto v : adj[u]) {
        if(v != par && v != heavy[u])
            update(v , u , 1);
    }
    // answer query
    for(auto [i , depth] : query[u]) {
        ans[i] = ((freq[depth] & (freq[depth] - 1)) == 0);
    }
    // remove the node if it's not the heavy child
    if(!keep)
        update(u , par , -1);
}

void solve() {
    cin >> n >> m;
    adj.resize(n + 1);
    query.resize(n + 1);
    // take input 
    dep[1] = 1;
    sack(1 , 0);
    dfs(1 , 0 , 1);
    // ans query
}