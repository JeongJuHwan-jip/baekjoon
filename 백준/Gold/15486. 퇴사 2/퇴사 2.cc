#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int arr1[1500000], arr2[1500000];

int cache[1500000];
int dp(int idx) {
    if(idx == N) return 0;
    
    int &ret = cache[idx];
    if(ret != -1) return ret;
    ret = dp(idx+1);
    
    if(idx+arr1[idx] <= N) {
        ret = max(ret, arr2[idx]+dp(idx+arr1[idx]));
    }
    
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> arr1[i] >> arr2[i];
    }
    
    memset(cache, -1, sizeof(cache));

    cout << dp(0);
}