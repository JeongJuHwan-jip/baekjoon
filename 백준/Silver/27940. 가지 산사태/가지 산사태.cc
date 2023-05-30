#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;

int N, M, K;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K;
    int a, b;
    for(int i=1; i<=M; ++i) {
        cin >> a >> b;
        K -= b;
        if(K<0) {
            cout << i << " 1";
            return 0;
        }
    }
    cout << -1;

    return 0;
}
