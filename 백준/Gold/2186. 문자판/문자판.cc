#include <iostream>
#include <cstring>

using namespace std;

int N, M, K;
string arr[100];
string S;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int cache[100][100][80];
int dp(int y, int x, int idx) {
    if(arr[y][x] != S[idx]) return 0;
    if(idx+1 == S.length()) return 1;
    int &ret = cache[y][x][idx];
    if(ret != -1) return ret;
    ret = 0;

    for(int d=0; d<4; d++) {
        for(int k=1; k<=K; k++) {
            int ny = y+dy[d]*k;
            int nx = x+dx[d]*k;

            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;

            ret += dp(ny, nx, idx+1);
        }
    }
    return ret;
}

int solve() {
    memset(cache, -1, sizeof(cache));
    int ans = 0;
    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++) {
            ans += dp(y, x, 0);
        }
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K;
    for(int i=0; i<N; i++) cin >> arr[i];
    cin >> S;

    cout << solve();

    return 0;
}
