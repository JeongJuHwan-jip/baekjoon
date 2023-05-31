#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;

ll N, l, r, m;
string gaji, S;

int main()
{
    cin >> N;
	cout << "? " << (1+N)/2 << endl;
	cin >> gaji;
	
	l=1;
	r=(1+N)/2;
	ll a, b;
	
	while(l<r) {
		m=(l+r)/2;
		cout << "? " << m << endl;
		cin >> S;
		if(S==gaji) {
			r=m;
		}
		else {
			l=m+1;
		}
	}
	a=l;
	
	r=N;
	l=(1+N)/2;
	while(l<r) {
		m=(l+r+1)/2;
		cout << "? " << m << endl;
		cin >> S;
		if(S==gaji) {
			l=m;
		}
		else {
			r=m-1;
		}
	}
	b=r;
	cout << "! " << a << ' ' << b << endl;
    
    return 0;
}//99 49 99