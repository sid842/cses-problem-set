#include <iostream>

using namespace std;

namespace {
	static const int MOD = static_cast<int>(1e9 + 7);
}

/**
 *
 * This is a very standard algorithm to compute power of a number.
 * Logic behind this algorithm is that every number can be expressed as a power of 2.
 * So let's say x = 5 (101)
 * which means to calculate (a ^ 5) we need (a ^ 1) && (a ^ 4). 
 */ 
long long power_func(long long a, int x) {
	if(a == 0)
		return 0;
	if(x == 0 || a == 1)
		return 1;

	long long res = 1;
	while(x > 0) {
		if((x & 1) == 1) {
			res = (res * a)%MOD;
		}
		a = (a * a)%MOD;
		x >>= 1;
	}

	return res;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	cout << power_func(2, n) << "\n";

	return 0;

}
