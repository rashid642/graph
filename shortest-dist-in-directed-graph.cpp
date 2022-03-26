#include <bits/stdc++.h>
using namespace std;
void traverseVector(vector<int> v){
    int n = v.size();
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void topoSort(vector<pair<int, int>> adj[], stack<int> &st, int node, vector<int> &vis){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it.first]){
            topoSort(adj, st, it.first, vis);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int n, vector<pair<int, int>> adj[]){
    vector<int> vis(n, 0);
    stack<int> st;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            topoSort(adj, st, 0, vis);
        }    
    }
    
    vector<int> len(n, INT_MAX);
    len[st.top()] = 0;
    while(!st.empty()){
        int tp = st.top();
        st.pop();
        if(len[tp] == INT_MAX){
            continue;
        }
        for(auto it: adj[tp]){
            len[it.first] = min(len[it.first], len[tp] + it.second);
            cout << it.first << " len=" << len[it.first] << endl;
        }
    }
}
int main()
{
    int n, m; // mumber of nodes, number of vertex
    cin >> n >> m;
    vector<pair<int, int>> adj[n]; // node, weight
    for(int i=0; i<m; i++){
        int u, v;
        int weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
    }
    vector<int> sp = shortestPath(n, adj);
    traverseVector(sp);
    return 0;
}
