#include <iostream>

using namespace std;

string KOR = "KOREA";

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string S;
    cin >> S;
    int idx = 0;
    int ans = 0;
    for(int i=0; i<S.size(); i++) {
        if(S[i] == KOR[idx]) {
            ans++;
            idx = (idx+1)%5;
        }
    }

    cout << ans;

    return 0;
}
