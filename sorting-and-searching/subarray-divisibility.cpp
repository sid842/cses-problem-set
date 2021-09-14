#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	ll prefix_sum = 0, ans = 0;
	map<ll, ll> sum_to_count;
	sum_to_count[0] = 1;

	for(int i = 0; i < n; ++i) {
		ll val;
		cin >> val;
		val = val%n;
		if(val < 0)
			val += n;
		prefix_sum = (prefix_sum + val%n)%n;
		if(sum_to_count.find(prefix_sum) != sum_to_count.end()) {
			ans += sum_to_count[prefix_sum];
		}
		sum_to_count[prefix_sum]++;
	}

	cout << ans << "\n";


	return 0;

}
