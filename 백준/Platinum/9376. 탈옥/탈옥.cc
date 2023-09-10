#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
using pi3 = pair<int,pii>;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};
const int INF = 54321;

int N, M;
string arr[100];
vector<pii> pr;
int dist1[100][100];
int dist2[100][100][2];

bool InBoard(int y, int x) {
    return y>=0 && y<N && x>=0 && x<M;
}

void make_dist1() {
    priority_queue<pi3> pq;
    for(int y=0; y<N; ++y) {
        for(int x=0; x<M; ++x) {
            if(y>0 && y<N-1 && x>0 && x<M-1) continue;
            if(arr[y][x]=='*') continue;
            int v = (arr[y][x]=='#');
            pq.push(pi3(-v,pii(y,x)));
            dist1[y][x] = v;
        }
    }

    while(!pq.empty()) {
        int v = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        for(int d=0; d<4; ++d) {
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(!InBoard(ny, nx)) continue;
            if(arr[ny][nx]=='*') continue;
            if(dist1[ny][nx]!=INF) continue;

            int nv = v+(arr[ny][nx]=='#');
            pq.push(pi3(-nv,pii(ny,nx)));
            dist1[ny][nx] = nv;
        }
    }
}

void make_dist2(int i) {
    priority_queue<pi3> pq;
    pq.push(pi3(0,pr[i]));
    dist2[pr[i].first][pr[i].second][i] = 0;

    while(!pq.empty()) {
        int v = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        for(int d=0; d<4; ++d) {
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(!InBoard(ny, nx)) continue;
            if(arr[ny][nx]=='*') continue;
            if(dist2[ny][nx][i]!=INF) continue;

            int nv = v+(arr[ny][nx]=='#');
            pq.push(pi3(-nv,pii(ny,nx)));
            dist2[ny][nx][i] = nv;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--) {
        fill(dist1[0], dist1[100], INF);
        fill(dist2[0][0], dist2[99][100], INF);
        pr.clear();

        cin >> N >> M;
        for(int i=0; i<N; ++i) {
            cin >> arr[i];
            for(int j=0; j<M; ++j) {
                if(arr[i][j] == '$') {
                    pr.push_back(pii(i,j));
                }
            }
        }

        make_dist1();
        make_dist2(0);
        make_dist2(1);

        int dist20_min = INF;
        int dist21_min = INF;
        for(int y=0; y<N; ++y) {
            for(int x=0; x<M; ++x) {
                if(y>0 && y<N-1 && x>0 && x<M-1) continue;
                dist20_min = min(dist20_min, dist2[y][x][0]);
                dist21_min = min(dist21_min, dist2[y][x][1]);
            }
        }
        int ans = dist20_min+dist21_min;
        for(int y=0; y<N; ++y) {
            for(int x=0; x<M; ++x) {
                int v = dist1[y][x]+dist2[y][x][0]+dist2[y][x][1];
                if(arr[y][x] == '#') v -= 2;
                ans = min(ans, v);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
