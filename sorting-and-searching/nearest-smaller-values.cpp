#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(n);
	for(int& a: arr)
		cin >> a;

	stack<int> smaller_values;

	for(int i = 1; i <= n; ++i) {
		while(!smaller_values.empty() && arr[i-1] <= arr[smaller_values.top()-1])
			smaller_values.pop();

		cout << (smaller_values.empty() ? 0 : smaller_values.top()) << " ";
		smaller_values.push(i);
	}

	return 0;

}
