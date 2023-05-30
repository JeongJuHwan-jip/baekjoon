#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;

const int INF = 987654321;
bool arr[2047] = {0, };
int L[11], R[11];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T = 2047;
    fill(L, L+11, INF);
    fill(R, R+11, INF);
    while(T--) {
        int tmp;
        int val = 0;
        for(int i=0; i<11; ++i) {
            cin >> tmp;
            if(L[i] == INF) L[i] = tmp;
            else if(L[i] != tmp && R[i] == INF) R[i] = tmp;

            if(R[i] == tmp) {
                val += 1<<i;
            }
        }
        arr[val] = 1;
    }

    for(int i=0; i<2048; ++i) {
        if(!arr[i]) {
            for(int j=0; j<11; ++j) {
                if(i & (1<<j)) cout << R[j] << ' ';
                else cout << L[j] << ' ';
            }
            break;
        }
    }

    return 0;
}
