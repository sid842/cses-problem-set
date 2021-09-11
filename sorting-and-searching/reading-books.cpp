#include <iostream>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	//Ad-hoc problem, either 2*max will be the answer or the total sum.

	long long sum = 0, mx = -1, b;
	for(int i = 0; i < n; ++i) {
		cin >> b;
		mx = max(mx, b);
		sum += b;
	}

	if(mx > (sum-mx))
		cout << (2*mx) << "\n";
	else 
		cout << sum << "\n";

	return 0;

}
