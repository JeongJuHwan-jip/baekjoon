#include <iostream>

using namespace std;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int N;
double p[4];

bool visited[50][50] = {0, };
double backtrack(int y, int x, int steps) {
    if(steps == N) return 1;
    double ret = 0;
    for(int d=0; d<4; ++d) {
        int ny = y+dy[d];
        int nx = x+dx[d];
        if(visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        ret += backtrack(ny, nx, steps+1) * p[d];
        visited[ny][nx] = 0;
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<4; ++i) {
        cin >> p[i];
        p[i] /= 100;
    }

    visited[25][25] = 1;
    cout.precision(20);
    cout << backtrack(25, 25, 0);

    return 0;
}
