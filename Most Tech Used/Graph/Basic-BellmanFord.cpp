const int N = 2e7 + 5;
int n , m , u , v , dis[N] , w;
vector<vector<int>> adj;
bool belman(){
    for(int i = 1 ; i <= n ; i++) dis[i] = 0;
    for(int i = 0 ; i < n ; i++){
        bool flag = 0 ;
        for(int j = 0 ; j < m ; j++){
            u = adj[j][0] ; v = adj[j][1]; w = adj[j][2];
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                flag = 1;
            }
        }   
        if(i == n - 1 && flag) return 1;
    }
    return 0;
}