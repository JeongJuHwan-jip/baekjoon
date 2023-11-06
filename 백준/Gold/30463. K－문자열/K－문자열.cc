#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>
#include <bitset>

using namespace std;
using ll = long long;

int N, K;
ll arr[1<<10] = {0, };

int f(int idx) {
    int ret=0;
    while(idx) {
        if(idx & 1) ret++;
        idx >>= 1;
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    ll ans = 0;
    for(int i=0; i<N; ++i) {
        string S;
        cin >> S;
        int idx = 0;
        for(int j=0; j<10; ++j) {
            idx |= 1<<(S[j]-'0');
        }
        arr[idx]++;
    }

    for(int i=0; i<(1<<10); ++i) {
        for(int j=i+1; j<(1<<10); ++j) {
            if(f(i|j) == K) {
                ans += arr[i]*arr[j];
            }
        }
    }

    for(int i=0; i<(1<<10); ++i) {
        if(f(i) == K) {
            ans += arr[i]*(arr[i]-1)/2;
        }
    }

    cout << ans;

    return 0;
}
