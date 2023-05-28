#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string S;
    cin >> S;
    int UC = 0, DP = 0;
    for(int i=0; i<S.size(); ++i) {
        if(S[i] == 'U' || S[i] == 'C') {
            ++UC;
        }
        else {
            ++DP;
        }
    }

    if(DP>0) {
        if(UC>(DP+1)/2) {
            cout << "UDP";
        }
        else {
            cout << "DP";
        }
    }
    else {
        cout << "U";
    }

    return 0;
}
