#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int N;
pll arr[100000];

ll solve() {
    ll ans = 0;
    ll val = max(arr[0].first, arr[0].second);
    ll next_val = val;
    ll a = arr[0].first;
    for(int i=0; i<N; ++i) {
        if(a < arr[i].first) {
            a = arr[i].first;
            val = next_val;
        }
        val = max(val, arr[i].first);
        ll tmp = val - arr[i].second;
        if(tmp > 0) {
            ll add_val = (tmp+29)/30;
            ans += add_val;
            arr[i].second += add_val*30;
        }
        next_val = max(next_val, arr[i].second);
        next_val = max(next_val, val);
        //cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> arr[i].second;
    }
    for(int i=0; i<N; ++i) {
        cin >> arr[i].first;
    }
    sort(arr, arr+N);
//    for(int i=0; i<N; ++i) {
//        cout << arr[i].first << ' ';
//    }
//    cout << '\n';
//    for(int i=0; i<N; ++i) {
//        cout << arr[i].second << ' ';
//    }
    cout << solve();

    return 0;
}
