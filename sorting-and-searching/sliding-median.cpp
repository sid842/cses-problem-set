/**
 * This code does not compile on my local machine(macOS).
 * Throws file now found error.
 * Used ideone for this problem.
 */ 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <vector>

using namespace __gnu_pbds;

using namespace std;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> nums(n);

	for(int i = 0; i < n; ++i) {
		cin >> nums[i].first;
		nums[i].second = i;
	}

	ordered_set<pair<int, int>> values;
	
	for(int i = 0; i < k-1; ++i)
		values.insert(nums[i]);

	for(int i = k-1; i < n; ++i) {
		values.insert(nums[i]);
		int ans;
		if(k%2)
			ans = values.find_by_order(k/2)->first;
		else 
			ans = min(values.find_by_order(k/2)->first, values.find_by_order((k/2)-1)->first);
		cout << ans << " ";
		values.erase(nums[i-k+1]);
	}

	return 0;

}
