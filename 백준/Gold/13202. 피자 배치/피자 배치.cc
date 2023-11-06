#include <iostream>
#include <cmath>

using namespace std;

const double pi = acos(-1);

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--) {
        double a, b, c;
        int k;
        cin >> a >> b >> k;

        cout << fixed;
        cout.precision(10);

        c = sqrt(pow(a,2)+pow(b,2));
        double r = a*b / (a+b+c);
        if(k==1) { cout << pi * r * r << '\n'; continue; }

        double arr[3];

        arr[0] = sqrt(pow(r,2)+pow(r,2)) - r;
        arr[1] = sqrt(pow(a-r,2)+pow(r,2)) - r;
        arr[2] = sqrt(pow(b-r,2)+pow(r,2)) - r;

        for(int t=0; t<k-2; ++t) {
            double r1 = arr[0]/(sqrt(2) + 1);
            double r2 = arr[1]/(sqrt(pow((a-r)/r, 2) + 1) + 1);
            double r3 = arr[2]/(sqrt(pow((b-r)/r, 2) + 1) + 1);

            if(r1 >= r2 && r1 >= r3)
                arr[0] -= r1*2;
            else if(r2 >= r1 && r2 >= r3)
                arr[1] -= r2*2;
            else
                arr[2] -= r3*2;
        }

        double r1 = arr[0]/(1+sqrt(2));
        double r2 = arr[1]/(sqrt(pow((a-r)/r, 2) + 1) + 1);
        double r3 = arr[2]/(sqrt(pow((b-r)/r, 2) + 1) + 1);

        if(r1 >= r2 && r1 >= r3)
            cout << pi * r1 * r1 << '\n';
        else if(r2 >= r1 && r2 >= r3)
            cout << pi * r2 * r2 << '\n';
        else
            cout << pi * r3 * r3 << '\n';
    }
}
