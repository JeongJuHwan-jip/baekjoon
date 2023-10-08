#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1001];
int cache[1001];
int via[1001];

int f(int idx) {
    int& ret = cache[idx];
    if(ret != -1) return ret;
    ret = 1;
    for(int i=idx+1; i<=N; ++i) {
        if(arr[i] <= arr[idx]) continue;
        int val = 1+f(i);
        if(ret < val) {
            ret = val;
            via[idx] = i;
        }
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    memset(cache, -1, sizeof(cache));
    memset(via, -1, sizeof(via));
    cin >> N;
    arr[0] = 0;
    for(int i=1; i<=N; ++i)
        cin >> arr[i];

    cout << f(0)-1 << '\n';
    int idx = 0;
    while(via[idx] != -1) {
        idx = via[idx];
        cout << arr[idx] << ' ';
    }

    return 0;
}
