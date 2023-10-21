#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
using ll = long long;
const int INF = 987654321;
const int MAXV = 100000;

int V;
vector<pii> adj[MAXV+1];

void dfs(int here, vector<int>& dist) {
    for(int i=0; i<adj[here].size(); ++i) {
        int there = adj[here][i].first;
        if(dist[there] != -1) continue;
        int cost = adj[here][i].second;
        dist[there] = dist[here] + cost;
        dfs(there, dist);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> V;
    int a, b, c;
    for(int i=0; i<V-1; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back(pii(b,c));
        adj[b].push_back(pii(a,c));
    }

    vector<int> dist(V+1, -1);
    dist[1] = 0;
    dfs(1, dist);
    int idx = max_element(dist.begin(), dist.end()) - dist.begin();

    dist.assign(V+1, -1);
    dist[idx] = 0;
    dfs(idx, dist);
    cout << *max_element(dist.begin(), dist.end());

    return 0;
}
