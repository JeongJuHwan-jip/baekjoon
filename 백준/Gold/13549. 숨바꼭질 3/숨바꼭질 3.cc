#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int N, K;
int dist[100001];

int bfs() {
    memset(dist, -1, sizeof(dist));
    deque<int> dq;
    dq.push_back(N);
    dist[N] = 0;
    while(!dq.empty()) {
        int here = dq.front();
        dq.pop_front();
        
        if(here == K) return dist[here];
        
        int there = here * 2;
        if(there <= 100000 && dist[there] == -1) {
            dist[there] = dist[here];
            dq.push_front(there);
        }
        there = here - 1;
        if(there >= 0 && dist[there] == -1) {
            dist[there] = dist[here] + 1;
            dq.push_back(there);
        }
        there = here + 1;
        if(there <= 100000 && dist[there] == -1) {
            dist[there] = dist[here] + 1;
            dq.push_back(there);
        }
    }
    
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N >> K;
    
    cout << bfs();
    
    return 0;
}