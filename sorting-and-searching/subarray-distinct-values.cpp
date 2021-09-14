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

	int n, k;
	cin >> n >> k;

	vector<int> arr(n);

	for(int& a: arr)
		cin >> a;

	map<int, int> distinct;

	ll ans = 0;

	for(int left = 0, right = 0; right < n; ++right) {
		distinct[arr[right]]++;
		while(distinct.size() > k) {
			distinct[arr[left]]--;
			if(distinct[arr[left]] == 0) {
				distinct.erase(arr[left]);
			}
			left++;
		}
		ans = ans + (right-left+1);
	}
	
	cout << ans << "\n";

	return 0;
}
