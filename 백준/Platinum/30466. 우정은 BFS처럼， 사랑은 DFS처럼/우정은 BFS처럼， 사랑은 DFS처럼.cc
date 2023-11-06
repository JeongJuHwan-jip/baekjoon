#include <iostream>

using namespace std;
using ll = long long;

ll N;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    ll M = (N-2) / 2;
    cout << 2*M*(M+N%2) << '\n';

    cout << "1 2\n";
    for(ll i=0; i<M; ++i) {
        cout << "1 " << i+3 << "\n";
    }
    cout << "2 " << 3+M << "\n";
    for(ll i=1; i<M+N%2; ++i) {
        cout << i+2+M << " " << i+3+M << "\n";
    }

    return 0;
}
