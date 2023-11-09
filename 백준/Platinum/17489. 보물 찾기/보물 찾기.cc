#include <iostream>

using namespace std;
using pii = pair<int,int>;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int N, M, L;
string S;
string arr[100];

pii daum[100][100];
bool visited[100][100] = {0, };

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<M;
}

const int INF = 987654321;

int dfs(int y, int x, int idx) {
    if(arr[y][x] != S[idx]) return -1;
    if(visited[y][x]) return INF;
    visited[y][x] = 1;
    int ret = (idx+1 == L);
    int val = 0;
    for(int d=0; d<4; ++d) {
        int ny = y+dy[d];
        int nx = x+dx[d];
        
        if(!InBoard(ny, nx)) continue;
        int tmp = dfs(ny, nx, (idx+1)%L);
        if(val < tmp) {
            val = tmp;
            daum[y][x] = pii(ny, nx); 
        }
    }
    return ret = ret+val;
}

int solve() {
    for(int y=0; y<N; ++y) {
        for(int x=0; x<M; ++x) {
            daum[y][x] = pii(y,x);
        }
    }
    
    int ans = dfs(0, 0, 0);
    if(ans >= INF) return -1;
    return ans;
}



int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N >> M >> L;
    cin >> S;
    for(int i=0; i<N; ++i) {
        cin >> arr[i];
    }
    
    int ans = solve();
    cout << ans << '\n';
    if(ans != -1) {
        int y = 0;
        int x = 0;
        while(daum[y][x] != pii(y,x)) {
            y = daum[y][x].first;
            x = daum[y][x].second;
        }
        cout << y+1 << ' ' << x+1 << '\n';
    }
    
    return 0;
}