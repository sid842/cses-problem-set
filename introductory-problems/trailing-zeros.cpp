#include <iostream>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int cnt = 0;

	for(long fac = 5; fac <= n; fac *= 5) {
		cnt += n/fac;
	}

	cout << cnt << "\n";

	return 0;

}
