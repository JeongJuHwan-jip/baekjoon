#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int,int>;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int N, M, D;
int oarr[15][15];
int arr[15][15];

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<M;
}

void cpy() {
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            arr[i][j] = oarr[i][j];
        }
    }
}

int f(vector<int> &xs, int a) {
    int ans = 0;
    vector<pii> targets;
    for(int i=0; i<3; ++i) {
        int y = N-1-a;
        int x = xs[i];

        for(int dist=0; dist<D; ++dist) {
            bool found_target = 0;
            for(int j=0; j<dist; ++j) {
                int yy = y-j;
                int xx = x-dist+j;
                if(!InBoard(yy, xx)) continue;
                if(arr[yy][xx]) {
                    targets.push_back(pii(yy, xx));
                    found_target = 1;
                    break;
                }
            }
            if(found_target) break;
            for(int j=0; j<=dist; ++j) {
                int yy = y-dist+j;
                int xx = x+j;
                if(!InBoard(yy, xx)) continue;
                if(arr[yy][xx]) {
                    targets.push_back(pii(yy, xx));
                    found_target = 1;
                    break;
                }
            }
            if(found_target) break;
        }
    }

    for(auto &v : targets) {
        int y = v.first;
        int x = v.second;
        if(arr[y][x] == 1) {
            arr[y][x] = 0;
            ++ans;
        }
    }
    return ans;
}

int c() {
    int ret = 0;
    for(int i=0; i<M; ++i) {
        for(int j=i+1; j<M; ++j) {
            for(int k=j+1; k<M; ++k) {
                vector<int> xs = {i, j, k};
                cpy();
                int tmp=0;
                for(int h=0; h<N; ++h) {
                    tmp += f(xs, h);
                }
                ret = max(ret, tmp);
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> D;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            cin >> oarr[i][j];
        }
    }

    cout << c();

    return 0;
}
