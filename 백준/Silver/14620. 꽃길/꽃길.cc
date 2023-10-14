#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int,int>;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
const int dy2[] = {0, 1, 2, 1, 0, -1, -2, -1};
const int dx2[] = {2, 1, 0, -1, -2, -1, 0, 1};
const int INF = 987654321;

int N;
int arr[10][10];

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<N;
}

int backtrack(vector<vector<int>> &used, int y, int x, int num) {
    if(y==N-1) {
        if(num == 3) return 0;
        else return INF;
    }
    if(x==N-1) return backtrack(used, y+1, 1, num);

    int ret = backtrack(used, y, x+1, num);
    if(used[y][x]) return ret;
    if(num == 3) return ret;

    vector<vector<int>> new_used = used;

    int val = arr[y][x];
    new_used[y][x] = 1;
    for(int d=0; d<4; ++d) {
        int ny = y+dy[d];
        int nx = x+dx[d];
        val += arr[ny][nx];
        new_used[ny][nx] = 1;
    }
    for(int d=0; d<8; ++d) {
        int ny = y+dy2[d];
        int nx = x+dx2[d];
        if(!InBoard(ny, nx)) continue;
        new_used[ny][nx] = 1;
    }

    return min(ret, val+backtrack(new_used, y, x+1, num+1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> used(N, vector<int>(N));
    cout << backtrack(used, 1, 1, 0);

    return 0;
}
