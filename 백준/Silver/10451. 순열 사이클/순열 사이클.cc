#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[1001];
int used[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i=1; i<=N; ++i) {
            cin >> arr[i];
        }
        memset(used, 0, sizeof(used));
        int ans = 0;
        for(int i=1; i<=N; ++i) {
            if(used[i]) continue;
            int idx = i;
            ans++;
            while(!used[idx]) {
                used[idx] = 1;
                idx = arr[idx];
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
