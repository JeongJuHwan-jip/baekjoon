#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll K;

int mobius[50000] = {0, };
void setup() {
    mobius[1] = 1;
    for(int i=1; i<50000; ++i) {
        for(int j=2*i; j<50000; j+=i) {
            mobius[j] -= mobius[i];
        }
    }
}

int f(ll n) {
    int ret = 0;
    for(int i=1; i*i<=n; ++i) {
        ret += mobius[i] * (n / (i*i));
    }
    return ret;
}

int solve() {
    ll l = 1;
    ll r = 2000000000;
    while(l<r) {
        //cout << l << ' ' << r << '\n';
        ll m = (l+r)/2;
        if(f(m)>=K) r = m;
        else l = m+1;
    }

    return l;
}

int main() {

    cin >> K;

    setup();

    cout << solve();

    return 0;
}
