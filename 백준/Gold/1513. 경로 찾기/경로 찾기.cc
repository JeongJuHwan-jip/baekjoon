#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000007;
const int dy[] = {0, 1};
const int dx[] = {1, 0};

int N, M, C;
int arr[51][51] = {0, };

bool InBoard(int y, int x) {
    return y>=1 && y<=N && x>=1 && x<=M;
}

int cache[51][51][51][51];
int dp(int y, int x, int prev, int vis_num) {
    if(y==N && x==M) {
        if(vis_num != 0) return 0;
        return 1;
    }
    int &ret = cache[y][x][prev][vis_num];
    if(ret != -1) return ret;
    ret = 0;
    for(int d=0; d<2; ++d) {
        int ny = y+dy[d];
        int nx = x+dx[d];

        if(!InBoard(ny, nx)) continue;
        if(arr[ny][nx] != 0) {
            if(vis_num == 0) continue;
            if(arr[ny][nx] < prev) continue;
            ret += dp(ny, nx, arr[ny][nx], vis_num-1);
            ret %= MOD;
        }
        else {
            ret += dp(ny, nx, prev, vis_num);
            ret %= MOD;
        }
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> C;
    for(int i=1; i<=C; ++i) {
        int y, x;
        cin >> y >> x;
        arr[y][x] = i;
    }
    memset(cache, -1, sizeof(cache));
    for(int c=0; c<=C; ++c) {
        int v = c-(arr[1][1]>0);
        if(v < 0) cout << "0 ";
        else cout << dp(1, 1, arr[1][1], v) << ' ';
    }

    return 0;
}
