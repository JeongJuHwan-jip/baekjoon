#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
using pii = pair<int,int>;

int n, d, c;
vector< vector<pii> > adj;

pii bfs() {
    vector<int> dist(n+1, INT_MAX);
    priority_queue<pii> pq;
    pq.push(pii(0, c));
    dist[c] = 0;

    int cnt = 1;
    int max_dist = 0;
    while(!pq.empty()) {
        int here = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        if(d > dist[here]) continue;
        max_dist = max(max_dist, d);

        for(auto &v : adj[here]) {
            int there = v.first;
            int nd = v.second+d;

            if(dist[there] == INT_MAX) cnt++;
            if(dist[there] > nd) {
                dist[there] = nd;
                pq.push(pii(-nd, there));
            }
        }
    }

    return pii(cnt, max_dist);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    for(int t=0; t<T; t++) {
        cin >> n >> d >> c;
        adj = vector< vector<pii> >(n+1);
        while(d--) {
            int a, b, s;
            cin >> a >> b >> s;
            adj[b].push_back(pii(a, s));
        }

        pii ans = bfs();
        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}

