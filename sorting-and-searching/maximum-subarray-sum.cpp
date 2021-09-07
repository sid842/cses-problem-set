#include <iostream>
#include <vector>
#include <limits>

using namespace std;
using ll = long long;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	vector<ll> arr(n);
	for(auto& a: arr)
		cin >> a;

	// Kadane's Algorithm

	auto MIN_INT = -(static_cast<ll>(1e9) + 1);

	long long max_sum_here = MIN_INT, best_sum_till_now = MIN_INT;

	for(auto a: arr) {
		max_sum_here = max(max_sum_here + a, a);
		best_sum_till_now = max(best_sum_till_now, max_sum_here);
	}

	cout << best_sum_till_now << "\n";

	return 0;

}
