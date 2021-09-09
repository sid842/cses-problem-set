#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	ll target;
	cin >> n >> target;

	map<ll, int> sum_to_count;
	sum_to_count[0] = 1;

	ll prefix_sum = 0, ans = 0;

	for(int i = 0; i < n; ++i) {
		ll ele;
		cin >> ele;
		prefix_sum += ele;

		if(sum_to_count.find(prefix_sum-target) != sum_to_count.end()) {
			ans += sum_to_count[prefix_sum-target];
		}
		sum_to_count[prefix_sum]++;
	}

	cout << ans << "\n";

	return 0;

}
