#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, target;
	cin >> n >> target;

	vector<pair<int, int>> nums(n);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i].first;
		nums[i].second = i+1;
	}

	sort(nums.begin(), nums.end());

	int left = 0, right = n-1;

	while(left < right) {
		int sum = nums[left].first + nums[right].first;
		if(sum == target) {
			cout << nums[left].second << " " << nums[right].second << "\n";
			return 0;
		} else if(sum < target) {
			left++;
		} else {
			right--;
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;

}
