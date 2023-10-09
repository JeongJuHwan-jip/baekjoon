#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int,int>;

int N;
int arr[50][9];

int prm[9] = {-1, -1, -1, 0, -1, -1, -1, -1, -1};

int f() {
    int ret = 0;
    int ord = 0;
    int hitter = 0;
    int hit_num = 0;
    int out_cnt = 0;
    int run_sit = 0;
    for(int in = 0; in < N; ++in) {
        out_cnt = 0;
        run_sit = 0;
        while(out_cnt < 3) {
            hitter = prm[ord];
            hit_num = arr[in][hitter];
            if(hit_num == 0) out_cnt++;
            else {
                run_sit += 1;
                run_sit <<= hit_num;
                int scr = 0;
                int tmp = run_sit / 16;
                while(tmp) {
                    if(tmp%2) scr += 1;
                    tmp /= 2;
                }
                run_sit %= 16;
                //cout << run_sit << '\n';
                ret += scr;
            }
            ord = (ord+1)%9;
        }
    }
    return ret;
}

int ans = 0;

void p(int idx) {
    if(idx==9) {
//        if(f() == 5) {
//            for(int i=0; i<9; ++i) {
//                cout << prm[i] << ' ';
//            }
//            cout << '\n';
//        }
        ans = max(ans, f());
        return;
    }

    for(int i=0; i<9; ++i) {
        if(prm[i] == -1) {
            prm[i] = idx;
            p(idx+1);
            prm[i] = -1;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<9; ++j) {
            cin >> arr[i][j];
        }
    }

    p(1);
//    for(int i=0; i<9; ++i) {
//        prm[i] = i;
//    }
    cout << ans;

    return 0;
}
