#include <iostream>

using namespace std;

int N, M;

int sgt[400000] = {0, };
int lazy[400000] = {0, };

void propagation(int n, int l, int r) {
    if(lazy[n]==0) return;

    sgt[n] = r-l+1 - sgt[n];
    if(l != r) {
        lazy[n*2] ^= 1;
        lazy[n*2+1] ^= 1;
    }
    lazy[n] = 0;
}

void update(int n, int l, int r, int a, int b) {
    propagation(n, l, r);
    if(r<a || b<l) return;
    if(a<=l && r<=b) {
        lazy[n] ^= 1;
        propagation(n, l, r);
        return;
    }

    int m = (l+r)/2;
    update(2*n, l, m, a, b);
    update(2*n+1, m+1, r, a, b);
    sgt[n] = sgt[n*2] + sgt[n*2+1];
}

int query(int n, int l, int r, int a, int b) {
    propagation(n, l, r);
    if(r<a || b<l) return 0;
    if(a<=l && r<=b) return sgt[n];
    int m = (l+r)/2;
    return query(2*n, l, m, a, b) + query(2*n+1, m+1, r, a, b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<M; ++i) {
        int O, S, T;
        cin >> O >> S >> T;
        if(O==0) update(1, 1, N, S, T);
        else cout << query(1, 1, N, S, T) << '\n';
    }

    return 0;
}
