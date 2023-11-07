#include <iostream>

using namespace std;

string S;
string S1 = "YONSEI";
string S2 = "KOREA";

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> S;

    int i1 = 0;
    int i2 = 0;

    for(int i=0; i<S.size(); ++i) {
        if(S[i] == S1[i1]) {
            i1++;
            if(i1 == 6) {
                cout << S1;
                return 0;
            }
        }
        if(S[i] == S2[i2]) {
            i2++;
            if(i2 == 5) {
                cout << S2;
                return 0;
            }
        }
    }

    return 0;
}
