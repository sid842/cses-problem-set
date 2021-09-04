#include <iostream>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int test_case;
	cin >> test_case;

	while(test_case--) {
		int y, x;
		cin >> y >> x;

		//Each level has 2*n-1 numbers, for all n
		//Max of the two coordinate would help find n
		int level = max(y, x), offset = min(y, x);

		//AP Series
		long long l = 2L * (level-1), a = 1, d = 2;
		long long n = 1l + (l-a)/d;
		long long nums_before = n * ((a + l)/2);
		
		/**
		 * 
		 *  Eg y = 2, x = 3
		 *  level is 3 so we calculate the numbers before not caring
		 *  about the order.
		 *  nums_before is 4 based on the level.
		 *  now since it is spiral traversal we need to check 
		 *  if the y coordinate moves in increasing or decreasing direction.
		 *  If increasing adding the offset is enough. 
		 *  Otherwise we first add the previous numbers as the level, the (level-offset).
		 *  
		 */ 
		long long num = nums_before;
		if((x == level && x%2 == 1) || (y == level && y%2 == 0)) {
			num += level + (level-offset);
		} else {
			num += offset;
		}
		cout << num << "\n";
	}

	return 0;
}
