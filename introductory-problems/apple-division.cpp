#include <iostream>
#include <vector>

using namespace std;

//To handle overflow since 10^9 * 20 exceeds int
using ll = long long;

ll FindMinDiffDivision(vector<int>& arr, size_t idx, ll curSum, ll totalSum) {
	if(idx == arr.size()) {
		//curSum is the sum of the elements selected.
		//(totalSum-curSum) is the sum of the elements left over. 
		return abs((totalSum-curSum) - curSum);
	}

	return min(FindMinDiffDivision(arr, idx+1, curSum + arr[idx], totalSum), 
			   FindMinDiffDivision(arr, idx+1, curSum, totalSum));
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	ll total_sum = 0;
	vector<int> arr(n);
	for(int& a: arr) {
		cin >> a;
		total_sum += a;
	}

	cout << FindMinDiffDivision(arr, 0, 0, total_sum);

	return 0;
}
