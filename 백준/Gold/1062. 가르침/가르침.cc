#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
string sarr[50]; // anta tica a, c, i, n, t
int taught[26] = {0, };

int f() {
    int ans = 0;
    for(int i=0; i<N; ++i) {
        bool CanRead = 1;
        for(int j=4; j<sarr[i].size()-4; ++j) {
            if(!taught[sarr[i][j]-'a']) {
                CanRead = 0;
                break;
            }
        }
        if(CanRead) ans++;
    }
    return ans;
}

int tmp[21] = {0, };
int prm() {
    int ans = 0;
    taught['a'-'a'] = 1;
    taught['c'-'a'] = 1;
    taught['i'-'a'] = 1;
    taught['n'-'a'] = 1;
    taught['t'-'a'] = 1;

    for(int i=0; i<K; ++i) {
        tmp[20-i] = 1;
    }

    do {
        int num = 0;
        for(int i=0; i<26; ++i) {
            if(i=='a'-'a') ++num;
            else if(i=='c'-'a') ++num;
            else if(i=='i'-'a') ++num;
            else if(i=='n'-'a') ++num;
            else if(i=='t'-'a') ++num;
            else taught[i] = tmp[i-num];
        }

        ans = max(ans, f());

    } while(next_permutation(tmp, tmp+21));

    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    for(int i=0; i<N; ++i) {
        cin >> sarr[i];
    }

    K -= 5;
    if(K<0) cout << 0;
    else cout << prm();

    return 0;
}
