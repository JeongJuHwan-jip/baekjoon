#include <bits/stdc++.h>

using namespace std;

int arr[6][3];

int backtrack(int a, int b) {
    if(a==5) {
        for(int i=0; i<6; ++i) {
            for(int j=0; j<3; ++j) {
                if(arr[i][j]) return 0;
            }
        }
        return 1;
    }
    int na = a;
    int nb = b+1;
    if(nb == 6) {
        ++na;
        nb = na+1;
    }
    if(arr[a][0]>=1 && arr[b][2]>=1) {
        --arr[a][0];
        --arr[b][2];
        if(backtrack(na, nb)) return 1;
        ++arr[a][0];
        ++arr[b][2];
    }
    if(arr[a][1]>=1 && arr[b][1]>=1) {
        --arr[a][1];
        --arr[b][1];
        if(backtrack(na, nb)) return 1;
        ++arr[a][1];
        ++arr[b][1];
    }
    if(arr[a][2]>=1 && arr[b][0]>=1) {
        --arr[a][2];
        --arr[b][0];
        if(backtrack(na, nb)) return 1;
        ++arr[a][2];
        ++arr[b][0];
    }

    return 0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T=4;
    while(T--) {
        for(int i=0; i<6; ++i) {
            for(int j=0; j<3; ++j) {
                cin >> arr[i][j];
            }
        }

        cout << backtrack(0, 1) << ' ';
    }

    return 0;
}
