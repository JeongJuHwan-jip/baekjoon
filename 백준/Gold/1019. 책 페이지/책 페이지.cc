#include <iostream>
#include <vector>

using namespace std;

int N;

void add(vector<int> &v, int n) {
    while(n) {
        v[n%10]++;
        n /= 10;
    }
}

vector<int> solve(int n) {
    vector<int> ret(10);

    if(n < 10) {
        for(int i=1; i<=n; i++) ret[i]++;
        return ret;
    }

    ret = solve(n/10 - 1);

    for(int i=0; i<10; i++) ret[i] = ret[i]*10 + n/10;
    ret[0] -= 1;

    for(int val = n - n%10; val <= n; val++)
        add(ret, val);

    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    vector<int> ans = solve(N);

    for(int i=0; i<10; i++) cout << ans[i] << ' ';

    return 0;
}

