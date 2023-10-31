#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
using pii = pair<int,int>;

int N, M;
pii arr[50000];
pii querys[10000];

int solve(int a, int b) { // 0 false 1 maybe 2 true
    int ai = lower_bound(arr, arr+N, pii(a,INT_MIN)) - arr;
    int bi = lower_bound(arr, arr+N, pii(b,INT_MIN)) - arr;
    //cout << ai << ' ' << bi << '\n';

    if(ai == N) return 1;
    bool is_A_Unknown = (arr[ai].first != a);
    bool is_B_Unknown = (bi == N) ? 1 : (arr[bi].first != b);
    //cout << is_A_Unknown << ' ' << is_B_Unknown << '\n';
    
    if(is_A_Unknown && is_B_Unknown) {
        return 1;
    }
    if(!is_A_Unknown && !is_B_Unknown) {
        if(arr[ai].second < arr[bi].second) return 0;
    }
    int X = is_B_Unknown ? arr[ai].second : arr[bi].second;
    if(X==0) return 0;

    for(int i = is_A_Unknown ? ai : ai+1 ; i < bi; ++i) {
        if(arr[i].second >= X) return 0;
    }

    if(!is_A_Unknown && !is_B_Unknown) {
        if(arr[bi].first - arr[ai].first == bi - ai) {
            return 2;
        }
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; ++i) {
        int a, b;
        cin >> a >> b;
        arr[i] = pii(a,b);
    }

    cin >> M;
    for(int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        querys[i] = pii(a,b);

        int ans = solve(a, b);
        if(ans == 0) cout << "false\n";
        else if(ans == 1) cout << "maybe\n";
        else cout << "true\n";
    }

    return 0;
}