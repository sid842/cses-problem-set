#include <iostream>
#include <vector>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(n);
	for(int& a: arr) {
		cin >> a;
	}

	long long cost = 0;
	for(int i = 1; i < arr.size(); ++i) {
		if(arr[i] < arr[i-1]) {
			cost += (arr[i-1] - arr[i]);
			arr[i] = arr[i-1];
		}
	}

	cout << cost << "\n";

	return 0;

}
