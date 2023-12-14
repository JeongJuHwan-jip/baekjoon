#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int,int>;

string arr[8];

const int dy[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool isValid(int y, int x) {
    if(y<0 || y>=8 || x<0 || x>=8) return 0;
    return arr[y][x] == '.';
}

bool visited[8][8] = {0, };
int bfs() {
    queue<pii> q;
    q.push({7, 0});
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int d=0; d<9; d++) {
            int ny = y+dy[d];
            int nx = x+dx[d];

            if(!isValid(ny, nx)) continue;

            if(ny == 0) return 1;

            if(visited[ny][nx]) continue;
            if(!isValid(ny-1, nx)) continue;

            visited[ny][nx] = 1;
            q.push({ny-1, nx});
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for(int i=0; i<8; i++) cin >> arr[i];

    cout << bfs();

    return 0;
}
