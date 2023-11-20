#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int N;
ll D;
vector<int> monster;
vector<int> equipment;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> D;
    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        if(tmp==1) {
            cin >> tmp;
            monster.push_back(tmp);
        } else {
            cin >> tmp;
            equipment.push_back(tmp);
        }
    }

    sort(monster.begin(), monster.end());
    sort(equipment.begin(), equipment.end());

    int ans = 0;
    int idx1 = 0, idx2 = 0;
    while(1) {
        if(idx1 < monster.size() && monster[idx1] < D) {
            D += monster[idx1++];
        } else {
            if(idx2 < equipment.size()) {
                D *= equipment[idx2++];
            } else {
                break;
            }
        }

        if(D > 1e+9) {
            ans = N;
            break;
        }

        ans++;
    }

    cout << ans;

    return 0;
}
