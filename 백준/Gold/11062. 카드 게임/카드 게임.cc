#include <iostream>

using namespace std;
using pii = pair<int,int>;

int N;
int arr[1000];

pii operator + (pii a, pii b) {
    return pii(a.first + b.first , a.second + b.second);
}

pii cache[1001][1001];
pii dp(int l, int r) {
    if(l+r == N) return pii(0,0);
    bool isK = !( (l+r)%2 );
    pii &ret = cache[l][r];
    if(ret != pii(-1,-1)) return ret;

    pii tmp1 = dp(l+1, r);
    pii tmp2 = dp(l, r+1);

    if(isK) {
        if( tmp1.first + arr[l] > tmp2.first + arr[N-1-r] ) {
            ret = tmp1 + pii(arr[l], 0);
        } else {
            ret = tmp2 + pii(arr[N-1-r], 0);
        }
    } else {
        if( tmp1.second + arr[l] > tmp2.second + arr[N-1-r] ) {
            ret = tmp1 + pii(0, arr[l]);
        } else {
            ret = tmp2 + pii(0, arr[N-1-r]);
        }
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i=0; i<N; i++) cin >> arr[i];

        fill(&cache[0][0], &cache[1000][1001], pii(-1, -1));
        cout << dp(0, 0).first << '\n';
    }

    return 0;
}
