#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;

ll gcd(ll a, ll b) {
	if(a<b) swap(a,b);
	while(b) {
		a = a%b;
		swap(a,b);
	}
	return a;
}

int main()
{
	int N;
 	cin >> N;
	set<ll> s[2];
	ll tmp;
	cin >> tmp;
	bool d = 0;
	s[d].insert(tmp);
	s[d].insert(tmp+1);
	
 	while(--N) {
 		cin >> tmp;
 		for(auto &v : s[d]) {
 			//cout << v << ' ';
 			s[!d].insert(gcd(v, tmp));
			s[!d].insert(gcd(v, tmp+1));	
		}
		//cout << '\n';
		s[d].clear();
		d = !d;
	}
	
	cout << *(--s[d].end());
    return 0;
}