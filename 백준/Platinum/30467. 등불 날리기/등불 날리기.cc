#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int,int>;
using ll = long long;

int N, S;
int arr[100000];

int minnum;
int maxnum;

vector<int> sgt;

void setup() {
    vector<pii> v;
    for(int i=0; i<N; ++i) {
        v.push_back(pii(arr[i],i));
    }

    sort(v.begin(), v.end());

    int num = 1;

    for(int i=0; i<N; ++i) {
        if(i>0 && v[i-1].first < v[i].first) num++;
        arr[v[i].second] = num;
    }

    minnum = 1;
    maxnum = num;

    sgt = vector<int>(maxnum*4);
}

int query(int n, int s, int e, int l, int r) {
    if(r<s || e<l) return 0;
    if(l<=s && e<=r) return sgt[n];
    int m = (s+e)/2;
    return query(n*2, s, m, l, r) + query(n*2+1, m+1, e, l, r);
}

int query(int l, int r) {
    return query(1, minnum, maxnum, l, r);
}

void update(int n, int s, int e, int val, int diff) {
    if(val<s || e<val) return;
    if(s==e) {sgt[n] += diff; return;}
    int m = (s+e)/2;
    update(n*2, s, m, val, diff);
    update(n*2+1, m+1, e, val, diff);
    sgt[n] = sgt[n*2] + sgt[n*2+1];
}

void update(int val, int diff) {
    update(1, minnum, maxnum, val, diff);
}

ll solve() {
    ll ans = 0;
    ll sum = 0;
    for(int i=0; i<N; ++i) {
        if(i-S>=0) {
            sum -= query(arr[i-S]+1, maxnum);
            update(arr[i-S], -1);
        }
        sum += query(minnum, arr[i]-1);
        update(arr[i], 1);

        if(i-S+1>=0) {
            ans = max(ans, sum);
            //cout << "sum: " << sum << '\n';
        }
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> S;
    for(int i=0; i<N; ++i) {
        cin >> arr[i];
    }

    setup();

//    for(int i=0; i<N; ++i) {
//        cout << arr[i] << ' ';
//    }

    cout << solve();

    return 0;
}
