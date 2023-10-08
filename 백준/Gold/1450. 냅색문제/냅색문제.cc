#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, C;
int arr[30];

void f(vector<ll>& vec, ll sum, int lo, int hi) {
    if(lo == hi) vec.push_back(sum);
    else {
        f(vec, sum, lo+1, hi);
        f(vec, sum+arr[lo], lo+1, hi);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> C;
    for(int i=0; i<N; ++i)
        cin >> arr[i];

    vector<ll> vec1, vec2;
    f(vec1, 0, 0, N/2);
    f(vec2, 0, N/2, N);

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    vec1.erase(upper_bound(vec1.begin(), vec1.end(), C), vec1.end());
    vec2.erase(upper_bound(vec2.begin(), vec2.end(), C), vec2.end());

    int ans = 0;
    int p1 = 0, p2 = vec2.size()-1;
    while(p1 < vec1.size() && p2 >= 0) {
        ll val = vec1[p1]+vec2[p2];
        if(val > C) --p2;
        else {
            ++p1;
            ans += p2+1;
        }
    }
    cout << ans;

    return 0;
}
