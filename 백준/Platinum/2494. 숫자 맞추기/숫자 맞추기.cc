#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;
const int MAXN = 10000;

int N;
string S1, S2;

int cache[MAXN][10];
int dp(int idx, int cnt) {
    if(idx == N) return 0;
    int &ret = cache[idx][cnt];
    if(ret != -1) return ret;

    int diff = (S2[idx] - S1[idx] + 20 - cnt)%10;
    return ret = min(10-diff+dp(idx+1, cnt), diff+dp(idx+1, (cnt+diff)%10));
}

void reconstruct(int idx, int cnt) {
    if(idx == N) return;

    int diff = (S2[idx] - S1[idx] + 20 - cnt)%10;
    if( 10-diff+dp(idx+1, cnt) < diff+dp(idx+1, (cnt+diff)%10) ) {
        cout << idx+1 << ' ' << diff-10 << '\n';
        reconstruct(idx+1, cnt);
    }
    else {
        cout << idx+1 << ' ' << diff << '\n';
        reconstruct(idx+1, (cnt+diff)%10);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    cin >> S1 >> S2;

    mem(cache, -1);
    cout << dp(0, 0) << '\n';
    reconstruct(0, 0);

    return 0;
}
