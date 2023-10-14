#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9];
vector<int> find7() {
    int prm[9] = {0, 0, 1, 1, 1, 1, 1, 1, 1};

    do {
        int sum = 0;
        for(int i=0; i<9; ++i) {
            sum += arr[i]*prm[i];
        }
        if(sum != 100) continue;
        vector<int> ret;
        for(int i=0; i<9; ++i) {
            if(prm[i]) ret.push_back(arr[i]);
        }
        sort(ret.begin(), ret.end());
        return ret;
    } while(next_permutation(prm, prm+9));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for(int i=0; i<9; ++i) {
        cin >> arr[i];
    }

    vector<int> ans = find7();
    for(auto &v : ans) {
        cout << v << '\n';
    }

    return 0;
}
