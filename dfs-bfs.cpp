#include <bits/stdc++.h>
using namespace std;
void traverseVector(vector<int> v){
    int n = v.size();
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
vector<int> bfsTraversal(int v, vector<int> adj[]){
    vector<int> vis(v+1, 0);
    vector<int> bfs;
    for(int i=1; i<=v; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(int j=0; j<adj[node].size(); j++){
                    if(vis[adj[node][j]] == 1){
                        continue;
                    }
                    q.push(adj[node][j]);
                    vis[adj[node][j]] = 1;
                }
            }
        }
    }
    return bfs;
}
void helper(vector<int> adj[], int node, vector<int> &dfs, vector<int> &vis){
    if(vis[node]){
        return;
    }
    dfs.push_back(node);
    vis[node] = 1;
    for(int i=0; i<adj[node].size(); i++){
        helper(adj, adj[node][i], dfs, vis);
    }
}
vector<int> dfsTraversal(int v, vector<int> adj[]){
    vector<int> vis(v+1, 0);
    vector<int> dfs;
    for(int i=1; i<=v; i++){
        if(vis[i]){
            continue;
        }
        helper(adj, i, dfs, vis);
    }
    return dfs;
}
int main()
{
    int n, m; // mumber of nodes, number of vertex
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> bfs = bfsTraversal(n, adj);
    traverseVector(bfs);
    vector<int> dfs = dfsTraversal(n, adj);
    traverseVector(dfs);
    return 0;
}
