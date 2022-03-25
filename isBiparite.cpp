//using bfs
class Solution {
public:
    bool helper(int v, vector<int> adj[], vector<int> &color, int node){
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while(!q.empty()){
            int n = q.front();
            int c = color[n];
            q.pop();
            for(int i=0; i<adj[n].size(); i++){
                if(color[adj[n][i]] == -1){
                    color[adj[n][i]] = c == 1 ? 0 : 1;
                    q.push(adj[n][i]);
                }
                else if(color[adj[n][i]] == c){
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V+1, -1);
	    for(int i=0; i<V; i++){
	        if(color[i] == -1){
	            if(!helper(V, adj, color, i)){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};


//using dfs
class Solution {
public:
    bool helper(int v, vector<int> adj[], vector<int> &color, int node, int c){
        color[node] = c == 1 ? 0 : 1;
        for(int it : adj[node]){
            if(color[it] == color[node]){
                return false;
            }
            else if(color[it] == -1){
                if(!helper(v, adj, color, it, color[node])){
                    return false;
                } 
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V+1, -1);
	    for(int i=0; i<V; i++){
	        if(color[i] == -1){
	            if(!helper(V, adj, color, i, 0)){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};