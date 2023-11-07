#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

int N;
int arr[500000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for(int i=0; i<N; ++i) {
        cin >> arr[i];
    }

    int ans[2] = {INT_MAX, INT_MAX};

    for(int i=0; i<N; ++i) {
        for(int j=i+1; j<N; ++j) {
            int k = abs(arr[i]-arr[j]);
            ans[k%2] = min(ans[k%2], k);
        }
    }

    for(int i=0; i<2; ++i) {
        if(ans[i] == INT_MAX) ans[i] = -1;
        cout << ans[i] << ' ';
    }

    return 0;
}
