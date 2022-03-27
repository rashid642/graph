#include <bits/stdc++.h>
using namespace std;
void primsAlgo(int src, int n, vector<pair<int, int>> adj[]){
    int parent[n];
    int key[n];
    bool mst[n];
    for(int i=0; i<n; i++){
        parent[i] = -1;
        key[i] = INT_MAX;
        mst[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int j=0; j<n-1; j++){
        int mini = INT_MAX, ind;
        for(int i=0; i<n; i++){
            if(mst[i] == false && mini > key[i]){
                mini = key[i];
                ind = i;
            }
        }
        mst[ind] = true;
        for(auto it: adj[ind]){
            if(mst[it.first] == false && key[it.first] > it.second){
                key[it.first] = it.second;
                parent[it.first] = ind;
            }
        }
    }
    vector<pair<int, int>> mstt[n];
    for(int i=1; i<n; i++){
        mstt[i].push_back({parent[i], key[i]});
        cout << i << " " << parent[i] << " " << key[i] << endl;
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
        adj[v].push_back({u, weight});
    }
    primsAlgo(0, n, adj);
    return 0;
}
