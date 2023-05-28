#include <iostream>

using namespace std;

int C(int N, int K) {
    if( K == 0 || K == N ) return 1;
    return C(N-1,K) + C(N-1,K-1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    cout << C(N,K);

    return 0;
}
