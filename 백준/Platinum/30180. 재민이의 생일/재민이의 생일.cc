#include <iostream>
#include <deque>
#include <vector>

using namespace std;
using pii = pair<int,int>;

int n, m, k;
vector< vector<int> > arr;

int solve() {
    int ret = -1;

    for(int x=1; x<=k; ++x) {
        if(k%x) continue;
        int y = k/x;
        if(x>m) continue;
        if(y>n) continue;
        //cout << "y: " << y << " x: " << x << '\n';

        vector< deque<pii> > min_dqs(m);
        vector< deque<pii> > max_dqs(m);

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                deque<pii> &min_dq = min_dqs[j];
                deque<pii> &max_dq = max_dqs[j];
                int val = arr[i][j];
                if(!min_dq.empty() && min_dq.front().second <= i-y)
                    min_dq.pop_front();
                while(!min_dq.empty() && min_dq.back().first >= val)
                    min_dq.pop_back();
                min_dq.push_back(pii(val, i));

                if(!max_dq.empty() && max_dq.front().second <= i-y)
                    max_dq.pop_front();
                while(!max_dq.empty() && max_dq.back().first <= val)
                    max_dq.pop_back();
                max_dq.push_back(pii(val, i));
            }
//            cout << i << '\n';
//            for(auto &v: min_dqs) cout << v.front().first << ' ';
//            cout << '\n';
//            for(auto &v: max_dqs) cout << v.front().first << ' ';
//            cout << "\n\n";

            deque<pii> minvals;
            deque<pii> maxvals;
            for(int j=0; j<m; ++j) {
                deque<pii> &min_dq = min_dqs[j];
                deque<pii> &max_dq = max_dqs[j];
                int val = min_dq.front().first;
                if(!minvals.empty() && minvals.front().second <= j-x)
                    minvals.pop_front();
                while(!minvals.empty() && minvals.back().first >= val)
                    minvals.pop_back();
                minvals.push_back(pii(val, j));

                val = max_dq.front().first;
                if(!maxvals.empty() && maxvals.front().second <= j-x)
                    maxvals.pop_front();
                while(!maxvals.empty() && maxvals.back().first <= val)
                    maxvals.pop_back();
                maxvals.push_back(pii(val, j));

                if(i>=y-1 && j>=x-1) {
                    ret = max(ret, maxvals.front().first - minvals.front().first);
                }
            }
        }
    }

    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> k;
    arr = vector< vector<int> > (n, vector<int>(m));

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> arr[i][j];
        }
    }

    cout << solve();

    return 0;
}
