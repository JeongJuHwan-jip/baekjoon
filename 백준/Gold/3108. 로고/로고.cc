#include <iostream>
#include <cstring>

using namespace std;

struct rect {
    int x1, y1, x2, y2;
};

int N;
rect arr[1001];

bool isInside(int x, int y, rect r) {
    return r.x1 < x && x < r.x2 && r.y1 < y && y < r.y2;
}

bool isOverlap(rect r1, rect r2) {
    if(r1.x2 < r2.x1) return 0;
    if(r2.x2 < r1.x1) return 0;
    if(r1.y2 < r2.y1) return 0;
    if(r2.y2 < r1.y1) return 0;

    if(isInside(r1.x1, r1.y1, r2) && isInside(r1.x2, r1.y2, r2)) return 0;
    if(isInside(r2.x1, r2.y1, r1) && isInside(r2.x2, r2.y2, r1)) return 0;

    return 1;
}

int p[1001];

int find(int u) {
    if(p[u] == -1) return u;
    return p[u] = find(p[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u==v) return;
    p[u] = v;
}

int solve() {
    memset(p, -1, sizeof(p));
    int ans = N;
    for(int i=0; i<N+1; i++) {
        for(int j=i+1; j<N+1; j++) {
            if(isOverlap(arr[i], arr[j]) && find(i)!=find(j)) {
                ans--;
                merge(i, j);
            }
        }
    }

    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i].x1 >> arr[i].y1 >> arr[i].x2 >> arr[i].y2;
    }
    arr[N].x1 = 0;
    arr[N].y1 = 0;
    arr[N].x2 = 0;
    arr[N].y2 = 0;

    cout << solve();

    return 0;
}
