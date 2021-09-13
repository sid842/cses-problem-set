#include <iostream>
#include <vector>
#include <limits>

using namespace std;

using ll = long long;

bool check(vector<ll>& times, ll time_allowed, ll products_needed) {
	ll products_created = 0;
	for(auto& t: times) {
		products_created += (time_allowed / t);
		if(products_created >= products_needed)
			return true;
	}

	return false;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	ll num_products;
	cin >> n >> num_products;

	vector<ll> times(n);
	ll max_time = 0;
	for(auto& t: times) {
		cin >> t;
		max_time = max(max_time, t);
	}

	ll min_time_possible = 0, max_time_possible = numeric_limits<ll>::max(), ans;

	while(min_time_possible <= max_time_possible) {
		auto probe = min_time_possible + (max_time_possible - min_time_possible)/2;
		if(check(times, probe, num_products)) {
			ans = probe;
			max_time_possible = probe - 1;
		} else {
			min_time_possible = probe + 1;
		}
	}

	cout << ans;

	return 0;

}
