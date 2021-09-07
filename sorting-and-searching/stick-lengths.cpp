/**
 * 
 * There is another solution based on the idea of
 * finding the median and then calculating its distance
 * from other elements.
 * 
 */ 
#include <iostream>
#include <algorithm>
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
	vector<ll> stick_lengths(n);

	ll larger_sticks = 0, shorter_sticks = 0;

	for(auto& l: stick_lengths) {
		cin >> l;
		larger_sticks += l;
	}

	sort(stick_lengths.begin(), stick_lengths.end());

	ll min_cost = numeric_limits<ll>::max();

	for(int i = 0; i < n; ++i) {

		ll cost_to_shorten = larger_sticks - (n - i) * stick_lengths[i];
		ll cost_to_lengthen = i * stick_lengths[i] - shorter_sticks;

		min_cost = min(min_cost, cost_to_lengthen + cost_to_shorten);
		larger_sticks -= stick_lengths[i];
		shorter_sticks += stick_lengths[i];
	}

	cout << min_cost << "\n";

	return 0;

}
