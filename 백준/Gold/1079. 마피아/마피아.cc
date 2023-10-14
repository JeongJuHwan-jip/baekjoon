#include <iostream>

using namespace std;

const int INF = 987654321;
int N = 0;
int died[16] = {0, };
int scr[16] = {0, };
int arr[16][16] = {0, };
int ej = 0;

int ans = 0;
void night(int num);
void day(int num);

void night(int num) {
    for(int i=0; i<N; ++i) {
        if(died[i]) continue;
        if(i == ej) {
            ans = max(ans, num);
            continue;
        }
        died[i] = 1;
        for(int j=0; j<N; ++j) {
            scr[j] += arr[i][j];
        }

        day(num+1);

        died[i] = 0;
        for(int j=0; j<N; ++j) {
            scr[j] -= arr[i][j];
        }
    }
}

void day(int num) {
    int die_idx = -1;
    int die_val = -INF;
    for(int j=0; j<N; ++j) {
        if(died[j]) continue;
        if(die_val < scr[j]) {
            die_idx = j;
            die_val = scr[j];
        }
    }
    if(die_idx == ej || die_idx == -1) {
        ans = max(ans, num);
    }
    else {
        died[die_idx] = 1;
        night(num);
        died[die_idx] = 0;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> scr[i];
    }
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> arr[i][j];
        }
    }
    cin >> ej;

    if(N%2) day(0);
    else night(0);
    cout << ans;

    return 0;
}
