#include <iostream>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int test_case;
	cin >> test_case;

	while(test_case--) {
		long long a, b;
		cin >> a >> b;

		if(a > b) {
			swap(a, b);
		}

		if(2*a < b) {
			cout << "NO\n";
		} else {
			//We can remove (2, 1) & (1, 2) from both piles
			//So 3 coins from each pile
			a %= 3, b %= 3;
			if(a > b) {
				swap(a, b);
			}
			if((a == 0 && b == 0) || (a == 1 && b == 2)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;

}
