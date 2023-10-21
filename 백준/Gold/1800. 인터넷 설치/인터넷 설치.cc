#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

const int INF = 987654321;

int N, P, K;
int p[1001];
vector<pii> adj[1001];

int bfs(int limit_num) {
    priority_queue<pii> pq;
    vector<int> used(N+1, INF);
    pq.push(pii(0, 1));
    used[1] = 0;
    while(!pq.empty()) {
        int val = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(val > K) break;
        if(val > used[here]) continue;

        for(auto &v : adj[here]) {
            int there = v.first;
            int cost = v.second;
            int nextval = val + (limit_num<cost);
            if(nextval < used[there]) {
                used[there] = nextval;
                pq.push(pii(-nextval, there));
            }
        }
    }
//    cout << limit_num << '\n';
//    for(int i=1; i<=N; ++i) {
//        cout << used[i] << ' ';
//    }
//    cout << '\n';

    if(used[N] <= K) return 1;
    else return 0;
}

int solve() {
    int l = -1;
    int r = 1000001;
    while(l+1 < r) {
        int m = (l+r)/2;
        if(bfs(m)) r=m;
        else l=m;
    }

    return r;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> P >> K;
    for(int i=0; i<P; ++i) {
        int u, v, price;
        cin >> u >> v >> price;
        adj[u].push_back(pii(v, price));
        adj[v].push_back(pii(u, price));
    }

    int ans = solve();
    if(ans == 1000001) cout << -1;
    else cout << ans;

    return 0;
}
