#include <iostream>
#include <cstring>

using namespace std;

int sk(int n);
int cy(int n);

int cache1[1001];
int sk(int n) {
    if(n==1 || n==3) return 1;
    if(n==2) return 0;
    int &ret = cache1[n];
    if(ret != -1) return ret;
    return ret = max(!cy(n-1), !cy(n-3));
}

int cache2[1001];
int cy(int n) {
    if(n==1 || n==3) return 1;
    if(n==2) return 0;
    int &ret = cache2[n];
    if(ret != -1) return ret;
    return ret = max(!sk(n-1), !sk(n-3));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    memset(cache1, -1, sizeof(cache1));
    memset(cache2, -1, sizeof(cache2));
    if(sk(N)) cout << "SK";
    else cout << "CY";

    return 0;
}
