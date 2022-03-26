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
vector<int> shortestPath(int src, int n, vector<pair<int, int>> adj[]){
    vector<int> dis(n+1, INT_MAX);
    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, src});
    while(!pq.empty()){
        pair<int, int> temp = pq.top();
        pq.pop();
        int node = temp.second, d = temp.first;
        for(auto it: adj[node]){
            if(dis[it.first] > dis[node] + it.second){
                dis[it.first] = dis[node] + it.second;
                pq.push({dis[node]+it.second, it.first});
            }
        }
    }
    return dis;
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
        adj[v].push_back({u, weight});
    }
    vector<int> sp = shortestPath(1, n, adj);
    traverseVector(sp);
    return 0;
}
