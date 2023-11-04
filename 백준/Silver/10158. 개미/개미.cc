#include <iostream>

using namespace std;

int N, M;

int y, x;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    cin >> y >> x;

    int t;
    cin >> t;

    y += t;
    x += t;

    y %= 2*N;
    x %= 2*M;
    if(y>N) y = 2*N - y;
    if(x>M) x = 2*M - x;

    cout << y << ' ' << x;

    return 0;
}
