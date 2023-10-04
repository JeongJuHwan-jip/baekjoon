#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int N;
string arr[50];

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<N;
}

int ans = INT_MAX;
int sy = -1, sx = -1, ey = -1, ex = -1;

bool used[50][50] = {0, };
void solve(int y, int x, int d, int v) {
    if(v >= ans) return;

    while(1) {
        y += dy[d];
        x += dx[d];
        if(y == ey && x == ex) {
            ans = min(ans, v);
            return;
        }

        if(!InBoard(y, x)) return;
        if(arr[y][x] == '*') return;

        if(arr[y][x] == '!' && !used[y][x]) {
            used[y][x] = 1;
            solve(y, x, (d+1)%4, v+1);
            solve(y, x, (d+3)%4, v+1);
            used[y][x] = 0;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for(int i=0; i<N; ++i) {
        cin >> arr[i];
        for(int j=0; j<N; ++j) {
            if(arr[i][j] == '#') {
                if(sy == -1) { sy = i; sx = j; }
                else { ey = i; ex = j; }
            }
        }
    }

    for(int d=0; d<4; ++d) {
        solve(sy, sx, d, 0);
    }
    cout << ans;

    return 0;
}
