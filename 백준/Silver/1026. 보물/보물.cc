#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr1[50], arr2[50];

int main() {
    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> arr1[i];
    }
    for(int i=0; i<N; ++i) {
        cin >> arr2[i];
    }
    
    sort(arr1, arr1+N);
    sort(arr2, arr2+N);
    reverse(arr2, arr2+N);
    
    int ans = 0;
    for(int i=0; i<N; ++i) {
        ans += arr1[i] * arr2[i];
    }
    // for(int i=0; i<N; ++i) {
    //     cout << arr1[i] << ' ';
    // }
    // cout << '\n';
    // for(int i=0; i<N; ++i) {
    //     cout << arr2[i] << ' ';
    // }
    // cout << '\n';
    
    cout << ans;
}