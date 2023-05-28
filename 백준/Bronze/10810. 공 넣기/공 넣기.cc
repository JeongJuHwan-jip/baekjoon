#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;

int arr[100] = {0, };
int N, M;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        for(int j=a; j<=b; ++j) {
            arr[j-1] = c;
        }
    }
    for(int i=0; i<N; ++i) {
        cout << arr[i] << ' ';
    }


    return 0;
}
