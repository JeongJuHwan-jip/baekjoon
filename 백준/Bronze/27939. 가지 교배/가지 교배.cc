#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;

int N;
char arr[1001];
int m, k;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=1; i<=N; ++i) {
        cin >> arr[i];
    }
    cin >> m >> k;
    int tmp;
    int Wnum = 0;
    for(int i=0; i<m; ++i) {
        bool isP = 0;
        for(int j=0; j<k; ++j) {
            cin >> tmp;
            if(arr[tmp] == 'P') isP = 1;
        }
        if(!isP) ++Wnum;
    }

    if(Wnum >= 1) cout << 'W';
    else cout << 'P';

    return 0;
}
