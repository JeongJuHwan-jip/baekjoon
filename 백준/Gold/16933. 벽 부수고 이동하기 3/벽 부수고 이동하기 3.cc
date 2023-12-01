#include <iostream>
#include <tuple>
#include <queue>

using namespace std;
using ti4 = tuple<int, int, int, int>;

int N, M, K;
string arr[1000];

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<M;
}

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int dist[1000][1000][2][11] = {0, };
int solve() {
    queue<ti4> q;
    q.push({0, 0, 0, 0});
    dist[0][0][0][0] = 1;

    while(!q.empty()) {
        int y, x, t, k;
        tie(y, x, t, k) = q.front();
        q.pop();

        if(y==N-1 && x==M-1) return dist[y][x][t][k];

        if(dist[y][x][!t][k] == 0) {
            q.push({y, x, !t, k});
            dist[y][x][!t][k] = dist[y][x][t][k] + 1;
        }

        for(int d=0; d<4; d++) {
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(!InBoard(ny, nx)) continue;
            if(arr[ny][nx] == '1' && t==1) continue;

            int nt = !t;
            int nk = k + (arr[ny][nx] == '1');
            if(nk > K) continue;
            if(dist[ny][nx][nt][nk]) continue;

            q.push({ny, nx, nt, nk});
            dist[ny][nx][nt][nk] = dist[y][x][t][k] + 1;
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K;
    for(int i=0; i<N; i++) cin >> arr[i];

    cout << solve();

    return 0;
}

