#include <bits/stdc++.h>

using namespace std;

int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int tmp1 = CCW(x1,y1,x2,y2,x3,y3);
    int tmp2 = CCW(x1,y1,x2,y2,x4,y4);
    if(tmp1 > 0) tmp1 = 1;
    if(tmp1 < 0) tmp1 =-1;
    if(tmp2 > 0) tmp2 = 1;
    if(tmp2 < 0) tmp2 =-1;

    if(tmp1*tmp2 < 0) cout << 1;
    else cout << 0;

    return 0;
}
