#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[2][100000];

int cache[100000][3];
int dp(int idx, int used) {
    if(idx == N) return 0;
    int &ret = cache[idx][used];
    if(ret != -1) return ret;
    ret = dp(idx+1, 0);
    if(used == 0 || used == 1) ret = max(ret, arr[1][idx] + dp(idx+1, 2));
    if(used == 0 || used == 2) ret = max(ret, arr[0][idx] + dp(idx+1, 1));
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    cin >> T;
    for(int t=0; t<T; ++t) {
        cin >> N;
        for(int i=0; i<N; ++i)
            cin >> arr[0][i];
        for(int i=0; i<N; ++i)
            cin >> arr[1][i];
            
        memset(cache, -1, sizeof(cache));
        cout << dp(0, 0) << '\n';
    }
    
    return 0;
}