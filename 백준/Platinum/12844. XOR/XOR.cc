#include <iostream>

using namespace std;

int N, M;

int sgt[2000000] = {0,};
int lazy[2000000] = {0, };

void propagation(int n, int s, int e) {
    if(!lazy[n]) return;
    sgt[n] ^= ((e-s+1)%2) * lazy[n];
    if(s < e) {
        lazy[n*2] ^= lazy[n];
        lazy[n*2+1] ^= lazy[n];
    }
    lazy[n] = 0;
}

int query(int n, int s, int e, int l, int r) {
    propagation(n, s, e);
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) {
        return sgt[n];
    }
    int m = (s+e)/2;
    return query(n*2, s, m, l, r) ^ query(n*2+1, m+1, e, l, r);
}

void update(int n, int s, int e, int l, int r, int val) {
	//cout << n << ' ' << s << ' ' << e << '\n';
    propagation(n, s, e);
    if(r < s || e < l) return;
    if(l <= s && e <= r) {
        lazy[n] ^= val;
        propagation(n, s, e);
        return;
    }
    int m = (s+e)/2;
    update(n*2, s, m, l, r, val);
    update(n*2+1, m+1, e, l, r, val);
    sgt[n] = sgt[n*2] ^ sgt[n*2+1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N;
    for(int i=0; i<N; ++i) {
        int tmp;
        cin >> tmp;
        update(1, 0, 499999, i, i, tmp);
    }
    
    cin >> M;
    while(M--) {
        int a, i, j;
        cin >> a >> i >> j;
        if(a==1) {
            int k;
            cin >> k;
            update(1, 0, 499999, i, j, k);
        }
        else {
            cout << query(1, 0, 499999, i, j) << '\n';
        }
    }
    
    return 0;
}