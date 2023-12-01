#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pii = pair<int,int>;

int N, M;
string arr[1000];
string ans[1000];

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

bool visited[1000][1000] = {0, };
bool visited1[1000][1000] = {0, };
void solve() {
    for(int i=0; i<N; i++) ans[i] = arr[i];

    queue<pii> q;
    queue<pii> q1;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(visited[i][j] || arr[i][j] == '1') continue;

            q.push(pii(i,j));
            visited[i][j] = 1;
            int cnt = 0;

            memset(visited1, 0, sizeof(visited1));
            while(!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                cnt++;

                for(int d=0; d<4; d++) {
                    int ny = y+dy[d];
                    int nx = x+dx[d];

                    if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
                    if(visited[ny][nx]) continue;
                    if(visited1[ny][nx]) continue;

                    if(arr[ny][nx] == '1') {
                        q1.push(pii(ny, nx));
                        visited1[ny][nx] = 1;
                    } else {
                        q.push(pii(ny, nx));
                        visited[ny][nx] = 1;
                    }
                }
            }

            while(!q1.empty()) {
                int y = q1.front().first;
                int x = q1.front().second;
                q1.pop();

                ans[y][x] = (ans[y][x]-'0'+cnt)%10 +'0';
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];

    solve();

    for(int i=0; i<N; i++) cout << ans[i] << '\n';

    return 0;
}

