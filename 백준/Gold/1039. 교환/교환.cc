#include <bits/stdc++.h>

using namespace std;

string N;
int K;
string ans;
set<string> s[11];

void f(int num) {
    if(num == K) {
        ans = max(ans, N);
        return;
    }
    if(s[num].count(N)) {
        return;
    }
    else {
        s[num].insert(N);
    }
    for(int i=0; i<N.size(); ++i) {
        for(int j=i+1; j<N.size(); ++j) {
            if(i==0 && N[j]=='0') continue;
            swap(N[i], N[j]);
            f(num+1);
            swap(N[i], N[j]);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    ans = "-1";
    f(0);
    cout << ans;

    return 0;
}
