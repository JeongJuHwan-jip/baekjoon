#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
using pii = pair<int,int>;

int N;
int arr[500][500][2];

const int dy[2][6] = {{ 0,-1, 1, 0, 1,-1} , { 1, 0, -1,-1, 1, 0}};
const int dx[2][6] = {{-1,-1,-1, 1, 0, 0} , { 0, -1, 0, 1, 1, 1}};

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<N-y%2;
}

bool visited[500][500];
pii passed[500][500];
void bfs() {
    memset(passed, 0, sizeof(passed));
    memset(visited, 0, sizeof(visited));
    queue<pii> q;
    visited[0][0] = 1;
    q.push(pii(0,0));
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int d=0; d<3; ++d) {
            int ny = y+dy[y%2][d];
            int nx = x+dx[y%2][d];
            if(!InBoard(ny, nx)) continue;
            if(visited[ny][nx]) continue;
            if(arr[y][x][0] != arr[ny][nx][1]) continue;
            visited[ny][nx] = 1;
            passed[ny][nx] = pii(y,x);
            q.push(pii(ny, nx));
        }

        for(int d=3; d<6; ++d) {
            int ny = y+dy[y%2][d];
            int nx = x+dx[y%2][d];
            if(!InBoard(ny, nx)) continue;
            if(visited[ny][nx]) continue;
            if(arr[y][x][1] != arr[ny][nx][0]) continue;
            visited[ny][nx] = 1;
            passed[ny][nx] = pii(y,x);
            q.push(pii(ny, nx));
        }
    }

//    for(int i=0; i<N; ++i) {
//        for(int j=0; j<N; ++j) {
//            cout << visited[i][j] << ' ';
//        }
//        cout << '\n';
//    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N-i%2; ++j) {
            cin >> arr[i][j][0] >> arr[i][j][1];
        }
    }

    bfs();

    vector<int> path;
    for(int i=N-1; i>=0; --i) {
        for(int j=N-i%2-1; j>=0; --j) {
            if(visited[i][j]) {
                path.push_back(i*N+j-i/2+1);
                int ni = passed[i][j].first;
                int nj = passed[i][j].second;

                while(ni != 0 || nj != 0) {
                    i = ni;
                    j = nj;
                    path.push_back(i*N+j-i/2+1);
                    ni = passed[i][j].first;
                    nj = passed[i][j].second;
                }

                i = ni;
                j = nj;
                path.push_back(i*N+j-i/2+1);

                break;
            }
        }
    }

    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for(auto &v : path) {
        cout << v << ' ';
    }

    return 0;
}
