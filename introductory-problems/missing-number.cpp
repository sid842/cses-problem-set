#include <iostream>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, ele;
	cin >> n;

	int missing_num = 0;
	for(int i = 1; i < n; ++i) {
		cin >> ele;
		missing_num = missing_num + i - ele;
	}

	cout << missing_num + n << "\n";

	return 0;

}
