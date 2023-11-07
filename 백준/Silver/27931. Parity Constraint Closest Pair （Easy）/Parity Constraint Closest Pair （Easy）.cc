#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    vector<int> v1, v2;
    int tmp;
    for(int i=0; i<N; ++i) {
        cin >> tmp;
        if(tmp%2) v1.push_back(tmp);
        else v2.push_back(tmp);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int ans1 = INT_MAX;
    int ans2 = INT_MAX;

    for(int i=1; i<v1.size(); ++i) {
        ans1 = min(ans1, v1[i] - v1[i-1]);
    }
    for(int i=1; i<v2.size(); ++i) {
        ans1 = min(ans1, v2[i] - v2[i-1]);
    }

    if(ans1 == INT_MAX) ans1 = -1;

    if(v1.empty() || v2.empty()) {
        ans2 = -1;
        cout << ans1 << ' ' << ans2;
        return 0;
    }

    int i1 = 0;
    int i2 = 0;
    while(i1 < v1.size() && i2 < v2.size()) {
        int t1 = v1[i1];
        int t2 = v2[i2];
        if(t1 > t2) {
            i2++;
        }
        else {
            ans2 = min(ans2, t2 - t1);
            i1++;
        }
    }

    i1 = 0;
    i2 = 0;
    while(i1 < v1.size() && i2 < v2.size()) {
        int t1 = v1[i1];
        int t2 = v2[i2];
        if(t1 < t2) {
            i1++;
        }
        else {
            ans2 = min(ans2, t1 - t2);
            i2++;
        }
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}
