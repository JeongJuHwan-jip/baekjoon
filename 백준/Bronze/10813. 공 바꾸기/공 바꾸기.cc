#include <iostream>

using namespace std;

int N, M;
int arr[101];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for(int i=1; i<=N; ++i) arr[i] = i;
    while(M--) {
        int a, b;
        cin >> a >> b;
        swap(arr[a],arr[b]);
    }

    for(int i=1; i<=N; ++i) cout << arr[i] << ' ';

    return 0;
}
