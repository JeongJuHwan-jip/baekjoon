#include <iostream>

using namespace std;

long long N;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    if(N%5 == 0 || N%5 == 2) cout << "CY";
    else cout << "SK";

//    int dp[1000];
//    dp[0] = 0;
//    for(int n = 1; n < 1000; n++) {
//        dp[n] = !dp[n-1];
//        if(n-4 >= 0) dp[n] |= !dp[n-4];
//        if(n-16 >= 0) dp[n] |= !dp[n-16];
//        if(n-64 >= 0) dp[n] |= !dp[n-64];
//        if(n-256 >= 0) dp[n] |= !dp[n-256];
//        cout << n << ": " << dp[n] << '\n';
//    }

    return 0;
}
