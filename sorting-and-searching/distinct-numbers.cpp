#include <iostream>
#include <set>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, ele;
	cin >> n;

	set<int> distinct;

	for(int i = 0; i < n; ++i) {
		cin >> ele;
		distinct.insert(ele);
	}

	cout << distinct.size();

	return 0;

}
