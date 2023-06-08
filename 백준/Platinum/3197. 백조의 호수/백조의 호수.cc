#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
using pi3 = pair<int,pii>;

const int INF = 987654321;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int R, C;
string arr[1500];

bool InBoard(int y, int x) {
	return y>=0 && y<R && x>=0 && x<C;
}

vector<int> Ly, Lx;
void findL() {
	for(int y=0; y<R; ++y) {
		for(int x=0; x<C; ++x) {
			if(arr[y][x]=='L') {
				Ly.push_back(y);
				Lx.push_back(x);
			}
		}
	}
}

int dist[1500][1500];
void make_dist() {
	memset(dist, -1, sizeof(dist));
	
	queue<pii> q;
	for(int y=0; y<R; ++y) {
		for(int x=0; x<C; ++x) {
			if(arr[y][x]!='X') {
				dist[y][x] = 0;
				q.push(pii(y,x));
			}
		}
	}
	
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int d=0; d<4; ++d) {
			int ny = y+dy[d];
			int nx = x+dx[d];
			if(!InBoard(ny, nx)) continue;
			if(dist[ny][nx] != -1) continue;
			q.push(pii(ny,nx));
			dist[ny][nx] = dist[y][x] + 1;
		}
	}
}

bool visited[1500][1500] = {0, };
int bfs() {
	int sy = Ly[0];
	int sx = Lx[0];
	int fy = Ly[1];
	int fx = Lx[1];
	
	priority_queue<pi3> pq;
	pq.push(pi3(0,pii(sy,sx)));
	while(!pq.empty()) {
		int val = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		
		if(y==fy && x==fx) return val;
		
		for(int d=0; d<4; ++d) {
			int ny = y+dy[d];
			int nx = x+dx[d];
			int nval = max(dist[ny][nx], val);
			
			if(!InBoard(ny, nx)) continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			pq.push(pi3(-nval, pii(ny, nx)));
		}
	}
}

int solve() {
	findL();
	make_dist();
	return bfs();
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> R >> C;
	for(int y=0; y<R; ++y) {
		cin >> arr[y];
	}
	
	cout << solve();
	
	return 0;
}