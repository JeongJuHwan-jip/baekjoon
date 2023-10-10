#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int,int>;

int N, M, K;
int arr[50][50];

const int INF = 987654321;

struct trn {
    int r; int c; int s;
    trn() {}
    trn(int r, int c, int s) : r(r), c(c), s(s) {}
};

vector<trn> trns;

int find_min() {
    int ret = INF;
    for(int i=0; i<N; ++i) {
        int tmp = 0;
        for(int j=0; j<M; ++j) {
            tmp += arr[i][j];
        }
        ret = min(ret, tmp);
    }
    return ret;
}

int prm[6] = {-1, -1, -1, -1, -1, -1};

int tmp_arr[50][50];
int oarr[50][50];
void make_turn(trn &t, int clk) { // 1 clk 0 cclk
    int r = t.r;
    int c = t.c;
    int s = t.s;

    if(clk == 1) {
        for(int i=-s; i<=s; ++i) {
            for(int j=-s; j<=s; ++j) {
                if(i<0 && j>=i+1 && j<=-i)
                    tmp_arr[r+i][c+j] = arr[r+i][c+j-1];
                if(i>0 && j>=-i && j<=i-1)
                    tmp_arr[r+i][c+j] = arr[r+i][c+j+1];
                if(j<0 && i>=j && i<=-j-1)
                    tmp_arr[r+i][c+j] = arr[r+i+1][c+j];
                if(j>0 && i>=-j+1 && i<=j)
                    tmp_arr[r+i][c+j] = arr[r+i-1][c+j];
            }
        }
    }
//    else {
//        for(int i=-s; i<=s; ++i) {
//            for(int j=-s; j<=s; ++j) {
//                if(i<0 && j>=i && j<=-i-1)
//                    tmp_arr[r+i][c+j] = arr[r+i][c+j+1];
//                if(i>0 && j>=-i+1 && j<=i)
//                    tmp_arr[r+i][c+j] = arr[r+i][c+j-1];
//                if(j<0 && i>=j+1 && i<=-j)
//                    tmp_arr[r+i][c+j] = arr[r+i-1][c+j];
//                if(j>0 && i>=-j && i<=j-1)
//                    tmp_arr[r+i][c+j] = arr[r+i+1][c+j];
//            }
//        }
//    }

    for(int i=-s; i<=s; ++i) {
        for(int j=-s; j<=s; ++j) {
            if(i!=0 || j!=0)
                arr[r+i][c+j] = tmp_arr[r+i][c+j];
        }
    }
}

int ans = INF;
int solve() {
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            arr[i][j] = oarr[i][j];
        }
    }
    for(int i=0; i<K; ++i) {
        int idx = prm[i];
        make_turn(trns[idx],1);
    }
    return find_min();
}


void permu(int idx) {
    if(idx == K) {
//        for(int i=0; i<K; ++i) {
//            cout << prm[i] << ' ';
//        }
//        cout << '\n';

        ans = min(ans, solve());

        return;
    }
    for(int i=0; i<K; ++i) {
        if(prm[i] == -1) {
            prm[i] = idx;
            permu(idx+1);
            prm[i] = -1;
        }
    }
}

//void print_arr() {
//    for(int i=0; i<N; ++i) {
//        for(int j=0; j<M; ++j) {
//            cout << arr[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            cin >> oarr[i][j];
        }
    }
    for(int i=0; i<K; ++i) {
        int r, c, s;
        cin >> r >> c >> s;
        trns.push_back(trn(r-1,c-1,s));
    }

    permu(0);

    cout << ans;

    return 0;
}
