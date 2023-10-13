#include <iostream>
#include <tuple>
#include <queue>

using namespace std;
using tii = tuple<int,int,int,int>;

int K;
int N, M;
int arr[200][200];

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
const int dy2[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dx2[] = {2, 1, -1, -2, 2, 1, -1, -2};

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<M;
}

bool visited[200][200][31] = {0, };
int bfs() {
    queue<tii> q; // y x k v
    q.push({0, 0, 0, 0});
    visited[0][0][0] = 1;

    while(!q.empty()) {
        int y, x, k, v;
        tie(y, x, k, v) = q.front();
        q.pop();

        if(y==N-1 && x==M-1) return v;
        for(int d=0; d<4; ++d) {
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(!InBoard(ny, nx)) continue;
            if(arr[ny][nx] == 1) continue;
            if(visited[ny][nx][k] == 1) continue;

            visited[ny][nx][k] = 1;
            q.push({ny, nx, k, v+1});
        }

        if(k==K) continue;
        for(int d=0; d<8; ++d) {
            int ny = y+dy2[d];
            int nx = x+dx2[d];
            if(!InBoard(ny, nx)) continue;
            if(arr[ny][nx] == 1) continue;
            if(visited[ny][nx][k+1] == 1) continue;

            visited[ny][nx][k+1] = 1;
            q.push({ny, nx, k+1, v+1});
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> K >> M >> N;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            cin >> arr[i][j];
        }
    }

    cout << bfs();

    return 0;
}
