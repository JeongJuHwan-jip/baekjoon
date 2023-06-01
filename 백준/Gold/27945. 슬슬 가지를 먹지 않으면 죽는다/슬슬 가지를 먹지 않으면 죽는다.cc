#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;

int p[100001];

int find(int u) {
	if(p[u] == -1) return u;
	return p[u] = find(p[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	p[u] = v;
}

bool IsSame(int u, int v) {
	return find(u)!=-1 && find(u)==find(v);
}

int N, M;
using piii = pair<int,pii>;
vector<piii> arr;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;
	int a, b, c;
	for(int i=0; i<M; ++i) {
		cin >> a >> b >> c;
		arr.push_back(piii(c,pii(a,b)));
	}
	
	sort(all(arr));
	mem(p, -1);
	
	for(int d=0; d<N-1; ++d) {
		if(arr[d].first != d+1) {
			cout << d+1;
			return 0;
		}
		if(IsSame(arr[d].second.first, arr[d].second.second)) {
			cout << d+1;
			return 0;
		}
		merge(arr[d].second.first, arr[d].second.second);
	}
	cout << N;
	
    return 0;
}