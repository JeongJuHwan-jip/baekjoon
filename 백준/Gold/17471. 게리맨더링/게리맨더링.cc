#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int arr[11];
vector<int> adj[11];
const int INF = 987654321;

int zone[11] = {0, };

bool visited[11] = {0, };
void dfs(int cur, int z) {
    if(zone[cur] != z) return;
    visited[cur] = 1;
    for(auto &next : adj[cur]) {
        if(visited[next]) continue;
        dfs(next, z);
    }
}

int f() {
    vector<int> z[3];
    for(int i=1; i<=N; ++i) {
        z[zone[i]].push_back(i);
    }
    if(z[1].empty() || z[2].empty()) return INF;

    memset(visited, 0, sizeof(visited));
    dfs(z[1][0], 1);
    dfs(z[2][0], 2);

    for(int i=1; i<=N; ++i) {
        if(!visited[i]) return INF;
    }

    int val[3] = {0, };
    for(int i=1; i<=N; ++i) {
        val[zone[i]] += arr[i];
    }

    return abs(val[1]-val[2]);
}

int ans = INF;
void backtrack(int idx) {
    if(idx == 11) {
        ans = min(ans, f());
        return;
    }
    zone[idx] = 1;
    backtrack(idx+1);
    zone[idx] = 2;
    backtrack(idx+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=1; i<=N; ++i) {
        cin >> arr[i];
    }
    for(int i=1; i<=N; ++i) {
        int n;
        cin >> n;
        for(int j=0; j<n; ++j) {
            int tmp;
            cin >> tmp;
            adj[i].push_back(tmp);
        }
    }

    backtrack(1);
    if(ans == INF) cout << -1;
    else cout << ans;

    return 0;
}
