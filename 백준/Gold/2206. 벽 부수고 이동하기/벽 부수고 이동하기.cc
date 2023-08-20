#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> pii;
typedef pair<bool,int> pbi;
typedef pair<pii, pbi> pib;

int N, M;
int arr[1000][1000];

const int x[4] = { 1 , -1 , 0 , 0 };
const int y[4] = { 0 , 0 , 1 , -1 };
const int not_Used = 0;
const int Wall = 1;
const int com_Used = 2;
const int pre_Used = 3;

int bfs() {
    queue<pib> q;
    q.push(pib(pii(0,0),pbi(false,1)));
    arr[0][0] = com_Used;

    while( !q.empty() ) {
        int _x = q.front().first.first;
        int _y = q.front().first.second;
        bool Used = q.front().second.first;
        int dist = q.front().second.second;
        if( _x == N-1 && _y == M-1 ) return dist;
        q.pop();

        for( int i = 0 ; i < 4 ; ++i ) {
            int next_x = _x + x[i];
            int next_y = _y + y[i];
            if( next_x < 0 || next_x >= N || next_y < 0 || next_y >= M || arr[next_x][next_y] == com_Used ) continue;

            if( Used == false ) {
                if( arr[next_x][next_y] == Wall ) {
                    q.push( pib( pii(next_x,next_y), pbi( true , dist+1 ) ) );
                }
                else {
                    q.push( pib( pii(next_x,next_y), pbi( false , dist+1 ) ) );
                    arr[next_x][next_y] = com_Used;
                }
            }
            else {
                if( arr[next_x][next_y] == not_Used ) {
                    q.push( pib( pii(next_x,next_y), pbi( true , dist+1 ) ) );
                    arr[next_x][next_y] = pre_Used;
                }
            }

        }

    }

    return -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for( int i = 0 ; i < N ; ++i ) {
        string S;
        cin >> S;
        for( int j = 0 ; j < M ; ++j ) {
            arr[i][j] = S[j] - '0';
        }
    }

    cout << bfs();

    return 0;
}
