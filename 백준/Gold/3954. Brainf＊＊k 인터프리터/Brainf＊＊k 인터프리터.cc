#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using pii = pair<int,int>;

const int MOD = 1<<8;

int m_size, c_size, i_size;
string A, B;
int marr[100000];
int m_idx, c_idx, i_idx;

int go_to[4096];
void make_go_to() {
    stack<int> s;
    for(int i=0; i<c_size; ++i) {
        if(A[i] == '[') s.push(i);
        if(A[i] == ']') {
            go_to[i] = s.top();
            go_to[s.top()] = i;
            s.pop();
        }
    }
}

void f(char inst) {
    if(inst == '-')
        marr[m_idx] = (marr[m_idx]-1+MOD)%MOD;
    if(inst == '+')
        marr[m_idx] = (marr[m_idx]+1+MOD)%MOD;
    if(inst == '<')
        m_idx = (m_idx-1+m_size)%m_size;
    if(inst == '>')
        m_idx = (m_idx+1+m_size)%m_size;
    if(inst == '[')
        if(marr[m_idx] == 0)
            c_idx = go_to[c_idx];
    if(inst == ']')
        if(marr[m_idx] != 0)
            c_idx = go_to[c_idx];
    if(inst == ',') {
        if(i_idx < i_size)
            marr[m_idx] = (int)B[i_idx++];
        else
            marr[m_idx] = 255;
    }

    c_idx++;
}



int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    for(int t=0; t<T; ++t) {
        cin >> m_size >> c_size >> i_size;
        cin >> A;
        cin >> B;

        memset(marr, 0, sizeof(marr));
        m_idx = 0;
        c_idx = 0;
        i_idx = 0;

        memset(go_to, 0, sizeof(go_to));
        make_go_to();

//        for(int i=0; i<c_size; ++i) {
//            cout << go_to[i] << ' ';
//        }
//        cout << '\n';

        for(int i=0; i<50000000; ++i) {
            if(c_idx<c_size) f(A[c_idx]);
            else break;
        }

        if(c_idx == c_size) cout << "Terminates\n";
        else {
            int max_idx = 0;
            for(int i=0; i<50000000; ++i) {
                f(A[c_idx]);
                max_idx = max(max_idx, c_idx);
            }
            cout << "Loops " << go_to[max_idx] << " " << max_idx << "\n";
        }

    }

    return 0;
}
