
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
