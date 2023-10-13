#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pii = pair<int,int>;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
const int INF = 987654321;

int N, M;
pii a1, a2, b1, b2;

bool InBoard(int y, int x) {
    return y>=0 && y<=N && x>=0 && x<=M;
}

bool visited[101][101];
pii bef[101][101];

void set_up() {
    memset(visited, 0, sizeof(visited));
    visited[a1.first][a1.second] = 1;
    visited[a2.first][a2.second] = 1;
    visited[b1.first][b1.second] = 1;
    visited[b2.first][b2.second] = 1;
}

int bfs(pii a1, pii a2, pii b1, pii b2) {
    int ret = 0;

    set_up();
    queue<pii> q;
    q.push(a1);
    visited[a2.first][a2.second] = 0;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(pii(y,x) == a2) break;
        for(int d=0; d<4; ++d) {
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(!InBoard(ny, nx)) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            bef[ny][nx] = pii(y,x);
            q.push(pii(ny,nx));
        }
    }
    if(!visited[a2.first][a2.second]) return INF;

    q = queue<pii>();
    set_up();
    q.push(b1);
    visited[b2.first][b2.second] = 0;
    for(pii pos=a2; pos!=a1; ) {
        //cout << pos.first << ' ' << pos.second << '\n';
        pos = bef[pos.first][pos.second];
        visited[pos.first][pos.second] = 1;
        ret++;
    }

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(pii(y,x) == a2) break;
        for(int d=0; d<4; ++d) {
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(!InBoard(ny, nx)) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            bef[ny][nx] = pii(y,x);
            q.push(pii(ny,nx));
        }
    }
    if(!visited[b2.first][b2.second]) return INF;
    for(pii pos=b2; pos!=b1; ) {
        pos = bef[pos.first][pos.second];
        visited[pos.first][pos.second] = 1;
        ret++;
    }
    return ret;
}

int main() {
    //cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    cin >> a1.first >> a1.second;
    cin >> a2.first >> a2.second;
    cin >> b1.first >> b1.second;
    cin >> b2.first >> b2.second;

    int ans = min(bfs(a1, a2, b1, b2), bfs(b1, b2, a1, a2));
    if(ans == INF) cout << "IMPOSSIBLE";
    else cout << ans;

    return 0;
}
