#include <iostream>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//Ad-hoc question
	int n;
	cin >> n;

	if(n == 1) {
		cout << 1 << "\n";
	}else if(n <= 3) {
		cout << "NO SOLUTION\n";
	} else if(n == 4) {
		//Missed this case in attempt#1
		cout << 3 << " " << 1 << " " << 4 << " " << 2 << "\n"; 
	}else {
		for(int i = 1; i <= n; i += 2) 
			cout << i << " ";
		for(int i = 2; i <= n; i += 2) 
			cout << i << " ";
		cout << "\n";
	}

	return 0;

}
