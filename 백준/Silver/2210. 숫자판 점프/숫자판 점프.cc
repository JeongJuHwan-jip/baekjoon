#include <iostream>
#include <algorithm>

using namespace std;

int arr[5][5];
int used[10][10][10][10][10][10] = {0, };
int num[6];

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

bool InBoard(int y, int x) {
    return y>=0 && y<5 && x>=0 && x<5;
}

int ans = 0;
void make_num(int y, int x, int n) {
    num[n] = arr[y][x];
    if(n==5) {
        int &tmp = used[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]];
        if(tmp == 1) return;

        tmp = 1;
        ans++;
        return;
    }
    for(int d=0; d<4; ++d) {
        int ny=y+dy[d];
        int nx=x+dx[d];
        if(!InBoard(ny, nx)) continue;
        make_num(ny, nx, n+1);
    }
}

int main() {
    //cin.tie(0)->sync_with_stdio(0);

    for(int i=0; i<5; ++i) {
        for(int j=0; j<5; ++j) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<5; ++i) {
        for(int j=0; j<5; ++j) {
            make_num(i,j,0);
        }
    }

    cout << ans;

    return 0;
}
