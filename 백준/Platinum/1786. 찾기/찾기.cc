#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;
const int INF = 987654321;
const double PI = 2.0 * acos(0);

vector<int> getPartialMatch(const string& S) {
    int m = S.size();
    vector<int> ret(m, 0);
    int begin = 1, matched = 0;
    while(begin+matched < m) {
        if(S[begin+matched] == S[matched]) {
            ++matched;
            ret[begin+matched-1] = matched;
        }
        else {
            if(matched==0)
                ++begin;
            else {
                begin += matched - ret[matched-1];
                matched = ret[matched-1];
            }
        }
    }
    return ret;
}

vector<int> KMP(const string& S1, const string& S2) {
    int n = S1.size(), m = S2.size();
    vector<int> ret, pi = getPartialMatch(S2);
    int begin = 0, matched = 0;
    while(begin <= n-m) {
        if(matched<m && S1[begin+matched] == S2[matched]) {
            ++matched;
            if(matched == m) ret.push_back(begin);
        }
        else {
            if(matched == 0) ++begin;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string S1, S2;
    getline(cin,S1);
    getline(cin,S2);

    vector<int> ans = KMP(S1, S2);
    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); ++i)
        cout << ans[i]+1 << ' ';

    return 0;
}
