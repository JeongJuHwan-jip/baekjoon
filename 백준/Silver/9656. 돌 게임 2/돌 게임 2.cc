#include <iostream>
#include <cstring>

using namespace std;

int N;

int SK(int n);
int CY(int n);

int cache1[1001];
int SK(int n) {
    if(n == 1) return 0;
    int &ret = cache1[n];
    if(ret != -1) return ret;
    ret = !CY(n-1);
    if(n-3 >= 1) ret |= !CY(n-3);
    return ret;
}

int cache2[1001];
int CY(int n) {
    if(n == 1) return 0;
    int &ret = cache2[n];
    if(ret != -1) return ret;
    ret = !SK(n-1);
    if(n-3 >= 1) ret |= !SK(n-3);
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    //for(N=1; N<=1000; ++N) cout << SK(N) << '\n';

    memset(cache1, -1, sizeof(cache1));
    memset(cache2, -1, sizeof(cache2));

    if(SK(N)) cout << "SK";
    else cout << "CY";

    return 0;
}
