#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
const char dc[4] = {'R', 'D', 'L', 'U'};
const int p[4] = {3, 1, 2, 0};

int N;
int arr[3000][3000];

bool InBoard(int x) {
	return x>=0 && x<N;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N;
    for(int i=0; i<N; ++i) {
    	for(int j=0; j<N; ++j) {
    		cin >> arr[i][j];
		}
	}
	
	int idx[4] = {N/2+1, N/2+1, N/2-2, N/2-2};
    int val[4] = 	{arr[N/2-1][N/2+1] + arr[N/2][N/2+1],
					 arr[N/2+1][N/2-1] + arr[N/2+1][N/2],
					 arr[N/2-1][N/2-2] + arr[N/2][N/2-2],
					 arr[N/2-2][N/2-1] + arr[N/2-2][N/2]};
    
    int ans = 0;
    string Moved;
    while(true) {
    	int mval = 0;
    	int mi = -1;
    	for(const int &i : p) {
    		if(val[i] > mval) {
    			mi = i;
    			mval = val[i];
			}
		}
		if(mi==-1) break;
		ans += mval;
		Moved += dc[mi];
		
		int li = (mi+3)%4;
		int ri = (mi+1)%4;
		if(InBoard(idx[li])) {
			val[li] += mi%2 ? arr[idx[mi]][idx[li]] : arr[idx[li]][idx[mi]];
		}
		if(InBoard(idx[ri])) {
			val[ri] += mi%2 ? arr[idx[mi]][idx[ri]] : arr[idx[ri]][idx[mi]];
		}
		if(mi<2) ++idx[mi];
		else --idx[mi];
		
		val[mi] = 0;
		if(InBoard(idx[mi])) {
			for(int i=min(idx[li],idx[ri])+1; i<max(idx[li],idx[ri]); ++i) {
				val[mi] += mi%2 ? arr[idx[mi]][i] : arr[i][idx[mi]];
			}
		}
	}
	cout << ans << '\n' << Moved;
    
    return 0;
}