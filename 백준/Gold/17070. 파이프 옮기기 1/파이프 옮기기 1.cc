#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using pii = pair<int,int>;

const int dy[] = {0, 1, 1};
const int dx[] = {1, 1, 0};

int N;
int arr[16][16];

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<N;
}

int cache[16][16][3];
int dp(int y, int x, int d) {
    if(y==N-1 && x==N-1) return 1;

    int &ret = cache[y][x][d];
    if(ret != -1) return ret;
    ret = 0;

    bool not_next[3] = {0, };
    for(int i=0; i<3; ++i) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(!InBoard(ny, nx)) {
            not_next[i] = 1;
            not_next[1] = 1;
            continue;
        }
        if(arr[ny][nx] == 1) {
            not_next[i] = 1;
            not_next[1] = 1;
        }
        if(abs(d-i)>=2) {
            not_next[i] = 1;
        }
    }

    for(int nd=0; nd<3; ++nd) {
        if(!not_next[nd]) ret += dp(y+dy[nd], x+dx[nd], nd);
    }

    return ret;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    memset(cache, -1, sizeof(cache));
    cin >> N;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> arr[i][j];
        }
    }

    cout << dp(0, 1, 0);

    return 0;
}
