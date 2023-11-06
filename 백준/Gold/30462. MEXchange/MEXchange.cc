#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=1; i<=N; ++i) {
        cin >> arr[i];
    }

    for(int i=1; i<=N; ++i) {
        if(arr[i] > i+1 || (i>1 && arr[i-1]>arr[i])) { cout << "No"; return 0; }
    }
    if(arr[N] != N+1) { cout << "No"; return 0; }

    vector<int> ans(N+1);
    vector<int> num_used(N+1);
    if(arr[1] == 2) {
        ans[1] = 1;
        num_used[1] = 1;
    }
    for(int i=2; i<=N; ++i) {
        if(arr[i-1] < arr[i]) {
            ans[i] = arr[i-1];
            num_used[arr[i-1]] = 1;
        }
    }

    int num = 1;
    for(int i=1; i<=N; ++i) {
        while(num_used[num]) num++;
        if(ans[i] == 0) ans[i] = num++;
    }

    cout << "Yes\n";
    for(int i=1; i<=N; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}
