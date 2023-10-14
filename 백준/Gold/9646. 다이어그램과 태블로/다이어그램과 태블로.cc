#include <iostream>
#include <cstring>

using namespace std;

int N;
int M[7];
int K;
int arr[7][7];

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<M[y];
}

int cache[823543];
int dp(int y, int x) {
    if(y==N) return 1;
    if(x==M[y]) return dp(y+1, 0);

    int key = 0;
    if(y==2 && x==0) {
        for(int i=0; i<M[y]; ++i) {
            key = key*7 + arr[y-1][i];
        }
        if(cache[key] != -1) return cache[key];
    }

    int ret = 0;
    int s = 0;
    if(x>0) s = max(s, arr[y][x-1]);
    if(y>0) s = max(s, arr[y-1][x]+1);
    for(int v=s; v<K; ++v) {
        arr[y][x] = v;
        ret += dp(y, x+1);
    }

    if(y==2 && x==0) cache[key] = ret;
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while(1) {
        cin >> N;
        if(cin.eof()) break;
        for(int i=0; i<N; ++i) {
            cin >> M[i];
        }
        cin >> K;

        memset(cache, -1, sizeof(cache));

        cout << dp(0, 0) << '\n';
    }

    return 0;
}
