#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
using pi2 = pair<pii,pii>;

const int dy[4] = {0,1,0,-1};
const int dx[4] = {1,0,-1,0};

int N;
int arr[100][100];

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<N;
}

bool visited[100][100] = {0, };
bool dfs(int y, int x, int a, int b) {
    if(arr[y][x] < a || arr[y][x] > b) return 0;
    visited[y][x] = 1;
    if(y==N-1 && x==N-1) return 1;
    for(int d=0; d<4; ++d) {
        int ny=y+dy[d];
        int nx=x+dx[d];
        if(!InBoard(ny, nx)) continue;
        if(visited[ny][nx]) continue;
        if(dfs(ny,nx,a,b)) return 1;
    }
    return 0;
}

bool IsmPossible(int m) {
    for(int i=0; i+m<=200; ++i) {
        memset(visited, 0, sizeof(visited));
        if(dfs(0,0,i,i+m)) return 1;
    }
    return 0;
}

int solve() {
    int l = 0;
    int r = 200;
    while(l<r) {
        int m = (l+r)/2;
        if(IsmPossible(m)) r=m;
        else l=m+1;
    }
    return l;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> arr[i][j];
        }
    }

    cout << solve();

    return 0;
}
