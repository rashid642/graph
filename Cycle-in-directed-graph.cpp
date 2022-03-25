class Solution {
  public:
    bool helper(vector<int> adj[], vector<int> &vis, vector<int> &dfsVis, int node){
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it: adj[node]){
            if(dfsVis[it] == 1){
                return true;
            }
            if(!vis[it]){
                if(helper(adj, vis, dfsVis, it)){
                    return true;
                }
            }
        }
        dfsVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V+1, 0), dfsVis(V+1, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(helper(adj, vis, dfsVis, i)){
                    return true;
                }
            }
        }
        return false;
    }
};