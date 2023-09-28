#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

const int dy[4] = {0,1,0,-1};
const int dx[4] = {1,0,-1,0};

const int id[7][4] =
{
{1, 1, 0, 0}, // 1 3
{1, 0, 0, 1}, // 2 9
{0, 0, 1, 1}, // 3 12
{0, 1, 1, 0}, // 4 6
{0, 1, 0, 1}, // | 10
{1, 0, 1, 0}, // - 5
{1, 1, 1, 1}  // + 15
};

const char i2c[16] =
{'0','0','0','1',
 '0','-','4','0',
 '0','2','|','0',
 '3','0','0','+'};

int R, C;
string arr[25];
pii M, Z;

bool InBoard(int y, int x) {
    return y>=0 && y<R && x>=0 && x<C;
}

int c2i(char a) {
    if(a=='|') return 4;
    if(a=='-') return 5;
    if(a>='1' && a<='4') return a-'1';
    return 6;
}

int ey, ex;
bool visited[25][25] = {0, };
bool dfs(int y, int x) {
    if(arr[y][x]=='.') {
        ey = y;
        ex = x;
        return 1;
    }

    int c = c2i(arr[y][x]);
    for(int d=0; d<4; ++d) {
        if(!id[c][d]) continue;
        int ny = y+dy[d];
        int nx = x+dx[d];
        if(!InBoard(ny,nx)) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        if(dfs(ny, nx)) return 1;
    }
    return 0;
}

void start_dfs() {
    visited[M.first][M.second] = 1;
    visited[Z.first][Z.second] = 1;
    int y = M.first;
    int x = M.second;
    for(int d=0; d<4; ++d) {
        int ny = y+dy[d];
        int nx = x+dx[d];
        if(!InBoard(ny,nx)) continue;
        if(arr[ny][nx] == '.') continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
        return;
    }
}

char sol(int y, int x) {
    int ans = 0;
    for(int d=0; d<4; ++d) {
        int ny = y+dy[d];
        int nx = x+dx[d];
        if(!InBoard(ny, nx)) continue;
        if(arr[ny][nx] == '.') continue;
        if(arr[ny][nx] == 'M') continue;
        if(arr[ny][nx] == 'Z') continue;
        int c = c2i(arr[ny][nx]);
        if(!id[c][(d+2)%4]) continue;
        ans += 1<<d;
    }
    return i2c[ans];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;
    for(int i=0; i<R; ++i) {
        cin >> arr[i];
        for(int j=0; j<C; ++j) {
            if(arr[i][j] == 'M') M = pii(i,j);
            if(arr[i][j] == 'Z') Z = pii(i,j);
        }
    }

    start_dfs();
    cout << ey+1 << " " << ex+1 << " " << sol(ey, ex);

    return 0;
}
