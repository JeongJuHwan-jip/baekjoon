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
 	set<ll> s1;
 	set<ll> s2;
	ll tmp;
	cin >> tmp;
	s1.insert(tmp);
	s1.insert(tmp+1);
	
 	while(--N) {
 		cin >> tmp;
 		for(auto &v : s1) {
 			//cout << v << ' ';
 			s2.insert(gcd(v, tmp));
			s2.insert(gcd(v, tmp+1));	
		}
		//cout << '\n';
		s1 = s2;
		s2.clear();
	}
	
	cout << *(--s1.end());
    return 0;
}