#include <iostream>
#include <cstring>

using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int N, M;

string arr[50];

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<M;
}

int visited[50][50];
int cache[50][50];
int dfs(int y, int x) {
    visited[y][x] = 1;

    int ret = 1;
    int num = arr[y][x] - '0';
    for(int d=0; d<4; ++d) {
        int ny = y+dy[d]*num;
        int nx = x+dx[d]*num;

        if(!InBoard(ny, nx)) continue;
        if(arr[ny][nx] == 'H') continue;
        if(visited[ny][nx]) {
            if(cache[ny][nx] == -1) return -1;
            ret = max(ret, cache[ny][nx]+1);
        } else {
            int nv = dfs(ny, nx);
            if(nv == -1) return -1;
            ret = max(ret, nv+1);
        }
    }

    return cache[y][x] = ret;
}

int solve() {
    memset(visited, 0, sizeof(visited));
    memset(cache, -1, sizeof(cache));
    return dfs(0, 0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<N; ++i) {
        cin >> arr[i];
    }

    cout << solve();

    return 0;
}
