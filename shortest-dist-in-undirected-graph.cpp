#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, vector<int> adj[]){
    vector<int> len(n, INT_MAX);
    vector<int> vis(n, 0);
    len[0] = 0;
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto it : adj[temp]){
            len[it] = min(len[it], len[temp]+1);
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);    
            }
        }
    }
    return len;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i=0; i<m; i++){
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	vector<int> sp = shortestPath(n, adj);
	for(auto it: sp){
	    cout << it << " ";
	}
}

// 9 11
// 0 1
// 0 3
// 1 3
// 1 2
// 3 4
// 4 5
// 5 6
// 2 6
// 6 7
// 6 8
// 7 8