#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

bool check(vector<ll>& arr, ll subarraySum, int k) {
	int possible_subarrays = 1;
	ll cur_sum = 0;

	for(size_t i = 0; i < arr.size(); ++i) {
		if(cur_sum + arr[i] > subarraySum) {
			possible_subarrays++;
			if(possible_subarrays > k || arr[i] > subarraySum)
				return false;
			cur_sum = arr[i];
		} else {
			cur_sum += arr[i];
		}
	}

	return possible_subarrays <= k;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	vector<ll> arr(n);
	ll sum = 0;

	for(auto& a: arr) {
		cin >> a;
		sum += a;
	}

	ll min_possible_sum_division = 1, max_possible_sum_division = sum, ans;

	while(min_possible_sum_division <= max_possible_sum_division) {
		auto probe = min_possible_sum_division + (max_possible_sum_division - min_possible_sum_division)/2;
		if(check(arr, probe, k)) {
			ans = probe;
			max_possible_sum_division = probe - 1;
		} else {
			min_possible_sum_division = probe + 1;
		}
	}

	cout << ans << "\n";

	return 0;

}
