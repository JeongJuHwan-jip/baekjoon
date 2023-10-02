#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int N, Q;
vector<pii> adj[5001];
bool visited[5001] = {0, };

int bfs(int a, int b) {
    int ans = 0;
    queue<pii> q;
    q.push(pii(a, INT_MAX));
    visited[a] = 1;
    while(!q.empty()) {
        int node = q.front().first;
        int val = q.front().second;
        q.pop();

        for(int i=0; i<adj[node].size(); ++i) {
            int nextnode = adj[node][i].first;
            if(visited[nextnode]) continue;
            visited[nextnode] = 1;
            int nextval = min(val, adj[node][i].second);
            if(nextval >= b) ++ans;
            q.push(pii(nextnode, nextval));
        }
    }
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;
    int p, q, r;
    for(int i=0; i<N-1; ++i) {
        cin >> p >> q >> r;
        adj[p].push_back(pii(q,r));
        adj[q].push_back(pii(p,r));
    }

    for(int i=0; i<Q; ++i) {
        cin >> p >> q;
        memset(visited, 0, sizeof(visited));
        cout << bfs(q, p) << '\n';
    }

    return 0;
}
