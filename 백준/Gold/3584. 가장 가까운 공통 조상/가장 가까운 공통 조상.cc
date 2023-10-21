#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;
const int INF = 987654321;
const double PI = 2.0 * acos(0);
const int MAXN = 10000;

int N;
int parent[MAXN+1];

void f(int u, vector<int>& v) {
    while(u != -1) {
        v.push_back(u);
        u = parent[u];
    }
    reverse(all(v));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> N;

        mem(parent, -1);
        int a, b;
        for(int i=0; i<N-1; ++i) {
            cin >> a >> b;
            parent[b] = a;
        }

        cin >> a >> b;
        vector<int> v1, v2;

        f(a, v1); f(b, v2);

        int size = min(v1.size(), v2.size());
        for(int i=0; i<size; ++i) {
            if(v1[i+1] != v2[i+1]) {
                cout << v1[i] << '\n';
                break;
            }
        }
    }

    return 0;
}
