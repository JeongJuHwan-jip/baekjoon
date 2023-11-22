#include <iostream>

using namespace std;

int N, M;

int sgt[2000000] = {0, };
int lazy[2000000] = {0, };

void propagation(int n, int s, int e) {
    if(lazy[n] == 0) return;
    sgt[n] = e-s+1;
    if(s<e) {
        lazy[n*2] = 1;
        lazy[n*2+1] = 1;
    }
    lazy[n] = 0;
}

int query(int n, int s, int e, int l, int r) {
    propagation(n, s, e);
    if(r<s || e<l) return 0;
    if(l<=s && e<=r) return sgt[n];

    int m = (s+e)/2;
    return query(n*2, s, m, l, r) + query(n*2+1, m+1, e, l, r);
}

int query(int l, int r) {
    return query(1, 1, N-1, l, r);
}

void update(int n, int s, int e, int l, int r) {
    propagation(n, s, e);
    if(r<s || e<l) return;
    if(l<=s && e<=r) {
        lazy[n] = 1;
        propagation(n, s, e);
        return;
    }

    int m = (s+e)/2;
    update(n*2, s, m, l, r);
    update(n*2+1, m+1, e, l, r);
    sgt[n] = sgt[n*2] + sgt[n*2+1];
}

void update(int l, int r) {
    update(1, 1, N-1, l, r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    int cnt = 0;
    int ans = 0;
    while(M--) {
        int a, b;
        cin >> a >> b;
        cnt++;

        if(a==b) continue;
        int num = b-a - query(a, b-1);
        update(a, b-1);

        if(num > cnt) {
            ans += num - cnt;
            cnt = 0;
        } else {
            cnt -= num;
        }
        if(sgt[1] + cnt >= N) break;
    }

    cout << ans;

    return 0;
}
