#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
using pi2 = pair<pii,pii>;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};
const int INF = 54321;

int N, M;
string arr[100];
vector<pii> pr;
int dist[100][100][4];

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<M;
}

int dijkstra() {
    priority_queue<pi2> pq;
    for(int d=0; d<4; ++d) {
        dist[pr[0].first][pr[0].second][d] = 0;
        pq.push(pi2(pii(0,d),pr[0]));
    }

    while(!pq.empty()) {
        int v = -pq.top().first.first;
        int d = pq.top().first.second;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        int ny = y+dy[d];
        int nx = x+dx[d];
        if(!InBoard(ny, nx)) continue;
        if(arr[ny][nx]=='*') continue;
        if(pii(ny,nx)==pr[1]) return v;

        int nd = d;
        int nv = v;
        if(dist[ny][nx][nd]<=nv) continue;
        pq.push(pi2(pii(-nv,nd),pii(ny,nx)));
        dist[ny][nx][nd] = nv;

        nd = (d+1)%4;
        nv = v+1;
        if(dist[ny][nx][nd]<=nv) continue;
        pq.push(pi2(pii(-nv,nd),pii(ny,nx)));
        dist[ny][nx][nd] = nv;

        nd = (d+3)%4;
        nv = v+1;
        if(dist[ny][nx][nd]<=nv) continue;
        pq.push(pi2(pii(-nv,nd),pii(ny,nx)));
        dist[ny][nx][nd] = nv;
    }
    return -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    fill(dist[0][0], dist[99][100], INF);

    cin >> M >> N;
    for(int i=0; i<N; ++i) {
        cin >> arr[i];
        for(int j=0; j<M; ++j) {
            if(arr[i][j]=='C') {
                pr.push_back(pii(i,j));
            }
        }
    }

    cout << dijkstra();

    return 0;
}
