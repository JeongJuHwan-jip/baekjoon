#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;
    while(N--) {
    	int q;
    	cin >> q;
    	int val;
    	switch (q) {
    		
    		case 1:
    			cin >> val;
    			dq.push_front(val);
    			break;
    		case 2:
    			cin >> val;
    			dq.push_back(val);
    			break;
    		case 3:
    			if(dq.empty()) cout << "-1\n";
    			else {
    				cout << dq.front() << '\n';
    				dq.pop_front();
				}
				break;
			case 4:
    			if(dq.empty()) cout << "-1\n";
    			else {
    				cout << dq.back() << '\n';
    				dq.pop_back();
				}
				break;
			case 5:
				cout << dq.size() << '\n';
				break;
			case 6:
				cout << dq.empty() << '\n';
				break;
			case 7:
				if(dq.empty()) cout << "-1\n";
    			else cout << dq.front() << '\n';
    			break;
    		case 8:
				if(dq.empty()) cout << "-1\n";
    			else cout << dq.back() << '\n';
    			break;
		}
	}
    
    return 0;
}