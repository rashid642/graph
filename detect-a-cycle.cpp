class Solution {
  public:
    bool helper(vector<int> adj[], vector<int> &vis, int v, int node){
        queue<pair<int, int>> q;
        q.push({node, -1});
        vis[node] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int i=0; i<adj[node].size(); i++){
                if(vis[adj[node][i]] == 1 && adj[node][i] != parent){
                    return true;
                }
                if(vis[adj[node][i]] == 1){
                    continue;
                }
                vis[adj[node][i]] = 1;
                q.push({adj[node][i], node});
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V+1, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(helper(adj, vis, V, i)){
                    return true;
                }
            }
        }
        return false;
    }
};