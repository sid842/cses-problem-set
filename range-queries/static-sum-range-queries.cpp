#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for(int& a: arr)
		cin >> a;

	vector<ll> prefix_sum(n+1);
	for(int i = 1; i <= n; ++i) {
		prefix_sum[i] = prefix_sum[i-1] + arr[i-1];
	}

	while(q--) {
		int a, b;
		cin >> a >> b;
		cout << prefix_sum[b] - prefix_sum[a-1] << "\n";
	}

	return 0;

}
