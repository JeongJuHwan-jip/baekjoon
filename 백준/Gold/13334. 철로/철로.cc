#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using pii = pair<int,int>;

int N, D;

pii arr[100000];

int solve() {
    int ans = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i=0; i<N; ++i) {
        while(!pq.empty() && pq.top().first < arr[i].second - D) pq.pop();
        if(arr[i].second - D <= arr[i].first) pq.push(arr[i]);
        ans = max(ans, (int)pq.size());
    }

    return ans;
}

bool comp(pii a, pii b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; ++i) {
        int a, b;
        cin >> a >> b;
        if(a>b) swap(a,b);
        arr[i] = pii(a,b);
    }
    cin >> D;

    sort(arr, arr+N, comp);

    cout << solve();

    return 0;
}
