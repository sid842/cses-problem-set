#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vector<ll> coins(n);

	for(auto& c: coins)
		cin >> c;

	sort(coins.begin(), coins.end());

	ll max_sum_non_constructible = 0;

	for(auto c: coins) {
		if(c > max_sum_non_constructible + 1) 
			break;

		max_sum_non_constructible += c;
	}

	cout << (max_sum_non_constructible + 1) << "\n";

	return 0;

}
