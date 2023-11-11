#include <iostream>
#include <cstring>

using namespace std;

long long N;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    if(N%2) cout << "SK";
    else cout << "CY";

    return 0;
}
