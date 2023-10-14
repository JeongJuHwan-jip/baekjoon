#include <iostream>
#include <vector>

using namespace std;

int p[1001] = {0, };
int find(int u) {
    if(p[u] == 0) return u;
    return p[u] = find(p[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;
    p[u] = v;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    int used[1001] = {0, };
    int ans = 0;
    for(int i=1; i<=N; ++i) {
        int u = find(i);
        if(used[u]) continue;
        ans++;
        used[u] = 1;
    }
    cout << ans;

    return 0;
}
