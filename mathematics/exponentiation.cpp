#include <iostream>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	const int MOD = static_cast<int>(1e9) + 7;

	int t;
	cin >> t;

	while(t--) {
		long long a, b;
		cin >> a >> b;

		long long res = 1;

		while(b) {
			if(b & 1) {
				res = (res * a) % MOD;
			}
			a = (a * a) % MOD;
			b >>= 1;
		}

		cout << res << "\n";
	}

	return 0;
}
