#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[200001];
int used[200001] = {0, };

vector< vector<int> > Pcycle() {
    vector< vector<int> > ans;
    for(int i=1; i<=N; ++i) {
        if(used[i]) continue;
        vector<int> v;
        int idx = i;
        while(!used[idx]) {
            used[idx] = 1;
            idx = arr[idx];
            v.push_back(idx);
        }
        if(v.size()>1) ans.push_back(v);
    }

    return ans;
}

int solve() {
    vector< vector<int> > vec = Pcycle();

//    for(auto &v : vec) {
//        for(auto it = v.begin(); it != v.end(); ++it) {
//            cout << *it << ' ';
//        }
//        cout << '\n';
//    }

    int ans = 0;
    int dnum = 0;
    int unum = 0;
    for(auto &v : vec) {
        bool isDown = 0;
        bool isUp = 0;
        for(int i=0; i<v.size(); ++i) {
            if(v[i] > N/2) isUp = 1;
            else isDown = 1;
        }
        if(isDown && isUp) ans += v.size()-1;
        else {
            if(isDown) dnum++;
            if(isUp) unum++;
            ans += v.size()-1;
        }
    }
    ans += 2*(unum+dnum-min(unum, dnum));
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=1; i<=N; ++i) {
        cin >> arr[i];
    }

    if(N%2 && arr[N/2+1] != N/2+1) { cout << -1; return 0; }

    cout << solve();

    return 0;
}
