#include <iostream>
#include <climits>

using namespace std;
using ll = long long;

int N, M, K;
ll sgt[4000000] = {0, };
ll lazy[4000000] = {0, };

void update(int n, int l, int r, int a, int b, ll diff) {
    if(lazy[n] != 0) {
        sgt[n] += lazy[n] * (r-l+1);
        if(l!=r) {
            lazy[n*2] += lazy[n];
            lazy[n*2+1] += lazy[n];
        }
        lazy[n] = 0;
    }

    if(r<a || b<l) return;
    if(a<=l && r<=b) {
        sgt[n] += (r-l+1)*diff;
        if(l!=r) {
            lazy[n*2] += diff;
            lazy[n*2+1] += diff;
        }
        return;
    }

    int m = (l+r)/2;
    update(n*2, l, m, a, b, diff);
    update(n*2+1, m+1, r, a, b, diff);
    sgt[n] = sgt[n*2] + sgt[n*2+1];
}

ll query(int n, int l, int r, int a, int b) {
    if(lazy[n] != 0) {
        sgt[n] += lazy[n] * (r-l+1);
        if(l!=r) {
            lazy[n*2] += lazy[n];
            lazy[n*2+1] += lazy[n];
        }
        lazy[n] = 0;
    }

    if(r<a || b<l) return 0;
    if(a<=l && r<=b) return sgt[n];

    int m = (l+r)/2;
    ll v1 = query(n*2, l, m, a, b);
    ll v2 = query(n*2+1, m+1, r, a, b);
    return v1+v2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K;
    for(int i=0; i<N; ++i) {
        ll tmp;
        cin >> tmp;
        update(1, 0, N-1, i, i, tmp);
    }

    for(int i=0; i<M+K; ++i) {
        int q;
        cin >> q;
        if(q==1) {
            int a, b;
            ll diff;
            cin >> a >> b >> diff;
            update(1, 0, N-1, a-1, b-1, diff);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << query(1, 0, N-1, a-1, b-1) << '\n';
        }
    }

    return 0;
}
