#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vector<int> steps(n+1);

	steps[0] = 0;

	for(int i = 1; i <= n; ++i) {
		int temp = i;
		steps[i] = numeric_limits<int>::max();
		while(temp) {
			if(temp%10) {
				int remaining_steps = steps[i - temp%10];
				steps[i] = min(steps[i], 1 + remaining_steps);
			}
			temp /= 10;
		}
	}

	cout << steps[n] << "\n";

	return 0;

}