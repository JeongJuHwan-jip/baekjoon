#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;
const int MAXN = 100000;
const int LOGMAXN = int(log2(MAXN));

int N, M, LOGN;
vector<int> adj[MAXN+1];
int depth[MAXN+1];
int sparse[MAXN+1][LOGMAXN+1];

void dfs(int here, int parent, int dp) {
    sparse[here][0] = parent;
    depth[here] = dp;
    for(const auto &there : adj[here]) {
        if(there == parent) continue;
        dfs(there, here, dp+1);
    }
}

void make_sparse() {
    for(int k=0; k<LOGN; ++k)
        for(int i=1; i<=N; ++i)
            sparse[i][k+1] = sparse[sparse[i][k]][k];
}

int LCA(int u, int v) {
    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u] - depth[v];
    for(int j=0; j<int(log2(diff))+1; ++j)
        if(diff & (1<<j))
            u = sparse[u][j];

    if(u==v) return u;
    for(int i=int(log2(depth[u])); i>=0; --i)
        if(sparse[u][i] != sparse[v][i]) {
            u = sparse[u][i];
            v = sparse[v][i];
        }

    return sparse[u][0];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    LOGN = int(log2(N));
    int a, b;
    for(int i=0; i<N-1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    mem(sparse, 0);
    dfs(1, 0, 0);
    make_sparse();

    cin >> M;
    for(int i=0; i<M; ++i) {
        cin >> a >> b;
        cout << LCA(a,b) << '\n';
    }

    return 0;
}
