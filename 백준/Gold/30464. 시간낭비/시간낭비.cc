#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int N;
int arr[200000];

int cache[200000][3];
int dp(int idx, int changed) {
	if(idx<0 || idx>=N) return -1;
	if(changed > 2) return -1;
	if(idx == N-1) return 0;
	if(arr[idx] == 0) return -1;
	
	int &ret = cache[idx][changed];
	if(ret != -INF) return ret;
	ret = -1;
	
	int dir = 1 - ( changed%2 ) * 2;
	ret = max(ret, dp(idx+dir*arr[idx], changed));
	ret = max(ret, dp(idx-dir*arr[idx], changed+1));
	if(ret != -1) ret++;
	return ret;
}

int solve() {
	fill(&cache[0][0], &cache[199999][3], -INF);
	return dp(0, 0);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	for(int i=0; i<N; ++i) {
		cin >> arr[i];
	}
	
	cout << solve();
	
	return 0;
}