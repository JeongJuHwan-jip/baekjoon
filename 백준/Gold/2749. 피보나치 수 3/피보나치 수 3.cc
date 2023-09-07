#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

const ll MOD = 1000000;

ll N;

pll f(ll a) {
    if(a==0) return pll(0,1);
    if(a==1) return pll(1,1);

    if(a%2) {
        pll tmp = f(a-1);
        return pll(tmp.second, (tmp.second+tmp.first)%MOD);
    }

    pll tmp = f(a/2);
    ll ans1 = tmp.first*(tmp.second-tmp.first+tmp.second+MOD);
    ll ans2 = tmp.first*tmp.first%MOD + tmp.second*tmp.second%MOD;

    return pll(ans1%MOD, ans2%MOD);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    cout << f(N).first;

    return 0;
}
