#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int N, M, P;

ll solve() {
    ll ans = 0;
    P = (P+1)/2 - 2;
    for(ll s=N+M-2; s>=P; --s) {
        for(ll a=0; a<=s; ++a) {
            ll b = s-a;
            if(N-a>=1 && M-b>=1) ans += (N-a)*(M-b);
        }
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> P;

    cout << solve();

    return 0;
}
