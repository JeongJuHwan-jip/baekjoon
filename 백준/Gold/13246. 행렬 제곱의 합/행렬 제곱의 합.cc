#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vv = vector< vector<int> >;

int N;
ll B;
vv arr;

vv mul(vv a, vv b) {
    vv ret = vv (N, vector<int>(N));
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            for(int k=0; k<N; ++k) {
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= 1000;
            }
        }
    }
    return ret;
}

vv sum(vv a, vv b) {
    vv ret = vv (N, vector<int>(N));
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            ret[i][j] = a[i][j] + b[i][j];
            ret[i][j] %= 1000;
        }
    }
    return ret;
}

vv exp(vv a, ll n) {
    if(n==1) return a;
    if(n%2) return mul(exp(a, n-1), a);
    vv tmp = exp(a, n/2);
    return mul(tmp, tmp);
}

vv solve(vv a, ll n) {
    if(n==1) return a;
    if(n%2) return sum(solve(a, n-1), exp(a, n));
    vv tmp = solve(a, n/2);
    return sum(tmp, mul(tmp, exp(a, n/2)));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> B;
    arr = vv (N, vector<int>(N));

    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> arr[i][j];
            arr[i][j] %= 1000;
        }
    }

    vv ans = solve(arr, B);

    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
