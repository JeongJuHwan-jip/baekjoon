#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;
const int RNG = 1e+5;

int N, M;
struct vert {
    int x, y1, y2, val;

    vert(int x, int y1, int y2=0, int val=0) : x(x), y1(y1), y2(y2), val(val) {}

    bool operator < (const vert &other) {
        if(x == other.x)
            return val > other.val;
        return x < other.x;
    }
};

vector<vert> verts;
vector<int> sgt;

int tree[RNG+2] = {0, };

int sum(int pos) {
    ++pos;
    int ret = 0;
    while(pos > 0) {
        ret += tree[pos];
        pos &= (pos-1);
    }
    return ret;
}

void add(int pos, int val) {
    ++pos;
    while(pos < RNG+2) {
        tree[pos] += val;
        pos += (pos & -pos);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--) {
        verts.clear();
        cin >> N >> M;
        int x1, x2, y1, y2;
        for(int i=0; i<N; ++i) {
            cin >> x1 >> y1;
            verts.push_back(vert(x1,y1));
        }
        for(int i=0; i<M; ++i) {
            cin >> x1 >> x2 >> y1 >> y2;
            verts.push_back(vert(x1,y1,y2,1));
            verts.push_back(vert(x2,y1,y2,-1));
        }

        int ans = 0;
        sort(all(verts));
        for(int i=0; i<verts.size(); ++i) {
            if(verts[i].val == 0) {
                ans += sum(verts[i].y1);
            }
            else {
                add(verts[i].y1, verts[i].val);
                add(verts[i].y2+1, -verts[i].val);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
