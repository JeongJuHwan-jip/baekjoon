#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;

ll N, A;
pll arr[100005];
vector<int> pg;

ll ccw(int a, int b, int c) {
	return (arr[b].first-arr[a].first)*(arr[c].second-arr[a].second)
		-(arr[c].first-arr[a].first)*(arr[b].second-arr[a].second);
}

bool comp1(int a, int b) {
	return arr[a]<arr[b];
}

bool comp2(int a, int b) {
	return ccw(pg[0],a,b)>0;
}

void convex_hull(int last) {
	pg.clear();
	for(int i=0; i<=last; ++i) {
		pg.push_back(i);
	}
	nth_element(pg.begin(),pg.begin(),pg.end(),comp1);
	sort(pg.begin()+1,pg.end(),comp2);
	
	vector<int> tmp;
	tmp.push_back(pg[0]);
	tmp.push_back(pg[1]);
	for(int i=2; i<pg.size(); ++i) {
		while(tmp.size()>=2) {
			int a=tmp[tmp.size()-2];
			int b=tmp[tmp.size()-1];
			if(ccw(a,b,pg[i])<=0) {
				tmp.pop_back();
			} else {
				break;
			}
		}
		tmp.push_back(pg[i]);
	}
	pg = tmp;
}

ll area2() {
	ll ret=0;
	for(int i=0; i<pg.size(); ++i) {
		int a = pg[i];
		int b = pg[(i+1)%pg.size()];
		ret += (arr[a].first+arr[b].first)*(arr[b].second-arr[a].second);
	}
	return ret;
}

string solve() {
	int l=2;
	int r=N+3;
	int m;
	while(l+1<r) {
		m=(l+r)/2;
		convex_hull(m);
		if(area2()<A*2) {
			l=m;
		} else {
			r=m;
		}
	}
	if(r==N+3) 
		return "draw";
	else if(r%2) 
		return "wapas";
	else 
		return "wider";
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> A;
	for(int i=0; i<N+3; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}
	
	cout << solve();
	
	return 0;
}