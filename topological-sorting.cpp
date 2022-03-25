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



//kahn's algorithm

class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int> inDegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<inDegree.size(); i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int tp = q.front();
            q.pop();
            ans.push_back(tp);
            for(int i=0; i<adj[tp].size(); i++){
                inDegree[adj[tp][i]]--;
                if(inDegree[adj[tp][i]] == 0){
                    q.push(adj[tp][i]);
                }
            }
        }
        return ans;
	}
};
