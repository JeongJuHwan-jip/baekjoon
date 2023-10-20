#include <bits/stdc++.h>

using namespace std;

string S1, S2, S3;

int cache[201][201];
int f(int idx1, int idx2, int idx3) {
    if(idx3 == S3.size()) return 1;
    int &ret = cache[idx1][idx2];
    if(ret != -1) return ret;
    ret = 0;
    if(idx1 < S1.size())
        if(S1[idx1] == S3[idx3])
            if(f(idx1+1, idx2, idx3+1)) ret = 1;
    if(idx2 < S2.size())
        if(S2[idx2] == S3[idx3])
            if(f(idx1, idx2+1, idx3+1)) ret = 1;

    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    for(int t=1; t<=T; ++t) {
        cin >> S1 >> S2 >> S3;
        memset(cache, -1, sizeof(cache));
        string ans = f(0, 0, 0)>0 ? "yes" : "no";
        cout << "Data set " << t << ": " << ans << "\n";
    }

    return 0;
}
