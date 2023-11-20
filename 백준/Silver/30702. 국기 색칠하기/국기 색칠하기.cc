#include <iostream>

using namespace std;

int N, M;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

string arr1[50];
string arr2[50];

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<M;
}

bool visited[50][50] = {0, };
bool dfs(int y, int x, char c1, char c2) {
    visited[y][x] = 1;

    for(int d=0; d<4; d++) {
        int ny = y+dy[d];
        int nx = x+dx[d];

        if(!InBoard(ny, nx)) continue;
        if(visited[ny][nx]) continue;
        if(arr1[ny][nx] != c1) continue;

        if(arr2[ny][nx] != c2) return 0;
        if(!dfs(ny, nx, c1, c2)) return 0;
    }
    return 1;
}

string solve() {
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(!visited[i][j])
                if(!dfs(i,j, arr1[i][j], arr2[i][j]))
                    return "NO";

    return "YES";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for(int i=0; i<N; i++) cin >> arr1[i];
    for(int i=0; i<N; i++) cin >> arr2[i];

    cout << solve();

    return 0;
}
