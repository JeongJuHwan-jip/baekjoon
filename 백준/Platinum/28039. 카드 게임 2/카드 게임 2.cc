#include <iostream>
#include <list>

using namespace std;
using ll = long long;

int N;
list<ll> li;

ll solve() {
    ll sum = 0;
    for(auto &v : li) {
        sum += v;
    }

    auto it1 = li.begin();
    auto it2 = it1; it2++;
    auto it3 = it2; it3++;

    while(it1 != li.end() && it2 != li.end() && it3 != li.end()) {
        if(*it1 <= *it2 && *it2 >= *it3) {
            ll tmp = *it1 - *it2 + *it3;
            it1 = li.erase(it1);
            it1 = li.erase(it1);
            *it1 = tmp;
            it2 = it1; it2++;
            it3 = it2; it3++;

            if(it1 != li.begin()) { it1--; it2--; it3--; }
            if(it1 != li.begin()) { it1--; it2--; it3--; }
        } else {
            it1++;
            it2++;
            it3++;
        }
    }

    //for(auto v: li) cout << v << ' ';

    int K = 1;
    while(!li.empty()) {
        if(li.front() > li.back()) {
            sum += li.front()*K;
            li.pop_front();
        }
        else {
            sum += li.back()*K;
            li.pop_back();
        }
        K *= -1;
    }

    return sum/2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i=0; i<N; i++) {
            ll tmp;
            cin >> tmp;
            li.push_back(tmp);
        }

        cout << solve() << '\n';
    }

    return 0;
}
