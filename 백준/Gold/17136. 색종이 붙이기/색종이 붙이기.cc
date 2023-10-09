#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int,int>;

const int INF = 987654321;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int arr[10][10];
int num[6] = {0, };

bool InBoard(int y, int x) {
    return y>=0 && y<10 && x>=0 && x<10;
}

int f(int y, int x) {
    if(y==10) return 0;
    if(x==10) return f(y+1, 0);

    if(!arr[y][x]) return f(y, x+1);

    int ret = INF;
    int MaxSize = 5;
    for(int i=0; i<5; ++i) {
        for(int j=0; j<5; ++j) {
            int ny = y+i;
            int nx = x+j;
            if(!InBoard(ny, nx) || !arr[ny][nx]) {
                MaxSize = max(i,j);
            }
            if(j>=MaxSize) break;
        }
        if(i>=MaxSize) break;
    }

    for(int sz=1; sz<=MaxSize; ++sz) {
        if(num[sz] == 5) continue;
        for(int i=0; i<sz; ++i) {
            for(int j=0; j<sz; ++j) {
                arr[y+i][x+j] = 0;
            }
        }
        num[sz]++;
        ret = min(ret, 1+f(y,x+sz));
        num[sz]--;
        for(int i=0; i<sz; ++i) {
            for(int j=0; j<sz; ++j) {
                arr[y+i][x+j] = 1;
            }
        }
    }

    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for(int i=0; i<10; ++i) {
        for(int j=0; j<10; ++j) {
            cin >> arr[i][j];
        }
    }

    int ans = f(0,0);
    if(ans >= INF) cout << -1;
    else cout << ans;

    return 0;
}
