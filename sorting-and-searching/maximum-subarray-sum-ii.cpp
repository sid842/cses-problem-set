//Solution Reference: https://www.geeksforgeeks.org/maximum-sum-subarray-of-size-range-l-r/
#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;
using ll = long long;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, l, r;
	cin >> n >> l >> r;

	vector<ll> arr(n);
	for(auto& a: arr)
		cin >> a;

	vector<ll> prefix_sum(n);
	prefix_sum[0] = arr[0];
	for(int i = 1; i < n; ++i)
		prefix_sum[i] = prefix_sum[i-1] + arr[i];

	multiset<ll> s;

	s.insert(0);
	ll ans = numeric_limits<ll>::min();

	ans = max(ans, prefix_sum[l-1]);
	
	int flag = 0;

	for(int i = l; i < n; ++i) {
		
		if(i-r >= 0) {
			if(flag == 0) {
				auto it = s.find(0);
				s.erase(it);
				flag = 1;
			}
		}

		if(i-l >= 0)
			s.insert(prefix_sum[i-l]);

		ans = max(ans, prefix_sum[i] - *s.begin());

		if(i-r >= 0) {
			auto it = s.find(prefix_sum[i-r]);
			s.erase(it);
		}
	}

	cout << ans << "\n";

	return 0;

}
