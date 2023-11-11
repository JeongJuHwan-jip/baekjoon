#include <iostream>
#include <cstring>

using namespace std;

long long N;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    if(N%7 == 0 || N%7 == 2) cout << "CY\n";
    else cout << "SK\n";

    return 0;
}
