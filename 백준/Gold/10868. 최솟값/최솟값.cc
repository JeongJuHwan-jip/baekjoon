#include <iostream>
#include <climits>

using namespace std;

int N, M;
int arr[100000];
int sgt[400000];

void init(int n, int l, int r) {
    if(l==r) {
        sgt[n] = arr[l];
        return;
    }
    int m = (l+r)/2;
    init(n*2, l, m);
    init(n*2+1, m+1, r);
    sgt[n] = min(sgt[n*2], sgt[n*2+1]);
}

int query(int n, int l, int r, int a, int b) {
    if(r<a || b<l) return INT_MAX;
    if(a<=l && r<=b) return sgt[n];

    int m = (l+r)/2;
    int v1 = query(n*2, l, m, a, b);
    int v2 = query(n*2+1, m+1, r, a, b);
    return min(v1, v2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<N; ++i) {
        cin >> arr[i];
    }

    init(1, 0, N-1);
    for(int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        cout << query(1, 0, N-1, a-1, b-1) << '\n';
    }

    return 0;
}
