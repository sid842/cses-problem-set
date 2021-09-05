#include <iostream>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	long long sum_1_to_n = (1LL*(n)*(n+1))/2;

	if(sum_1_to_n%2) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		long long target = sum_1_to_n / 2;

		int cnt_set_1 = 0, last_term_set_1 = -1, set_2_start = -1;
		long long set_1_sum = 0;
		for(int i = 1; i <= n; ++i) {
			set_1_sum += i;
			if(set_1_sum > target) {
				set_2_start = set_1_sum - target;
				cnt_set_1 = i - 1;
				last_term_set_1 = i;
				break;
			} 
		}

		cout << cnt_set_1 << "\n";
		for(int i = 1; i <= last_term_set_1; ++i) {
			if(i == set_2_start)
				continue;
			cout << i << " ";
		}
		cout << "\n";

		cout << (n - cnt_set_1) << "\n";
		cout << set_2_start << " ";
		for(int i = last_term_set_1 + 1; i <= n; ++i) {
			cout << i << " ";
		}
		cout << "\n";

	}


	return 0;

}
