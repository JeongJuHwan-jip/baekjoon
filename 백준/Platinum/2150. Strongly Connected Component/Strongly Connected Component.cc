#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mem(v, e) memset((v), (e), sizeof((v)))

using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using ll = long long;
const int MAXV = 10000;

int V, E;
vector<int> adj[MAXV+1];
int sccId[MAXV+1], discovered[MAXV+1];
stack<int> st;
int sccCounter, vertexCounter;
vector< vector<int> > SCCs;

int scc(int here) {
    int ret = discovered[here] = vertexCounter++;
    st.push(here);
    for(const auto &there : adj[here]) {
        if(discovered[there] == -1)
            ret = min( ret, scc(there) );
        else if(sccId[there] == -1)
            ret = min( ret, discovered[there] );
    }

    if(ret == discovered[here]) {
        SCCs.push_back(vector<int>());
        while(true) {
            int t = st.top();
            st.pop();
            SCCs[sccCounter].push_back(t);
            sccId[t] = sccCounter;
            if( t == here ) {
                sort(all(SCCs[sccCounter]));
                break;
            }
        }
        ++sccCounter;
    }
    return ret;
}

void tarjanSCC() {
    mem(sccId, -1); mem(discovered, -1);
    sccCounter = vertexCounter = 0;
    for( int i = 1 ; i <= V ; ++i )
        if( discovered[i] == -1 ) scc( i );
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E;
    int a, b;
    for(int i=0; i<E; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    tarjanSCC();
    sort(all(SCCs));
    cout << SCCs.size() << '\n';
    for(int i=0; i<SCCs.size(); ++i) {
        for(const auto &tmp : SCCs[i])
            cout << tmp << ' ';
        cout << "-1\n";
    }

    return 0;
}
