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
	ll target;
	cin >> n >> target;

	vector<pair<ll, int>> arr(n);

	for(int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i+1;
	}

	sort(arr.begin(), arr.end());

	for(int i = 0; i < n - 2; ++i) {
		int left = i+1, right = n-1;
		while(left < right) {
			ll sum = arr[left].first + arr[right].first;
			if(sum == target - arr[i].first) {
				cout << arr[i].second << " " << arr[left].second << " " << arr[right].second << "\n";
				return 0;
			} else if(sum < target - arr[i].first) {
				left++;
			} else {
				right--;
			}
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;

}
