#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPi(const string &S) {
    int n = S.size();
    vector<int> pi(n);
    int j=0;
    for(int i=1; i<n; ++i) {
        while(j>0 && S[i] != S[j])
            j = pi[j-1];
        if(S[i] == S[j])
            pi[i] = ++j;
    }
    return pi;
}

int solve(const string &S) {
    int n = S.size();
    int ans = 0;
    for(int i=0; i<n; ++i) {
        vector<int> pi = getPi(S.substr(i));
        ans = max(ans, *max_element(pi.begin(), pi.end()));
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string S;
    cin >> S;

    cout << solve(S);

    return 0;
}
