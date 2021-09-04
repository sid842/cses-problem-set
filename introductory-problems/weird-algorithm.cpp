#include <iostream>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//Since multiplication is involved we need long long
	long long n;
	cin >> n;

	while(n != 1) {
		cout << n << " ";
		if(n%2 == 0) {
			n /= 2;
		} else {
			n = 3 * n + 1;
		}
	}

	cout << 1 << "\n";

	return 0;

}
