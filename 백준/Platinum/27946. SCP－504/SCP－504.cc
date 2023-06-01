#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;

int c2i(char c) { // 62
	if(c>='a' && c<='z') return c-'a';
	if(c>='A' && c<='Z') return c-'A'+26;
	if(c>='0' && c<='9') return c-'0'+52;
	return -1;
}

struct node {
	map<pii, node*> m;
	int val = 0;
	
	node(){}
	~node(){}
};

int N, M;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;
	string S;
	node* start = new node();
	while(N--) {
		cin >> S;
		bool used[62] = {0, };
		node* np = start;
		for(int i=0; i<S.size(); ++i) {
			int ci = c2i(S[i]);
			if(!used[ci]) {
				if(!np->m.count(pii(i,ci))) {
					np->m[pii(i,ci)] = new node();
				}
				np = np->m[pii(i,ci)];
				used[ci] = 1;
			}
		}
		++(np->val);
	}
	
	while(M--) {
		cin >> S;
		bool used[62] = {0, };
		node* np = start;
		int ans = 0;
		for(int i=0; i<S.size(); ++i) {
			int ci = c2i(S[i]);
			if(!used[ci]) {
				if(!np->m.count(pii(i,ci))) {
					break;
				}
				np = np->m[pii(i,ci)];
				used[ci] = 1;
				ans += np->val;
			}
		}
		cout << ans << '\n';
	}
	delete start;
	
    return 0;
}