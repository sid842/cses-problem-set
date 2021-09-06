/**
 * 
 * This was a really hard question due to the constraints.
 * We need to calculate the exact number where the kth digit lies.
 * Rest some hit and trial to get the calculations right.  
 */

#include <iostream>
#include <cmath>

using namespace std;

using ull = unsigned long long;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int num_queries;
	cin >> num_queries;

	while(num_queries--) {
		ull kth_digit;
		cin >> kth_digit;

		if(kth_digit <= 9) {
			cout << kth_digit << "\n";
			continue;
		}

		ull digit_range_width = 1, total_num_of_digits_in_range = 9, total_nums = 9, prev_range_digits_sum = 0;
		while(kth_digit > total_num_of_digits_in_range + prev_range_digits_sum) {
			digit_range_width++;
			total_nums = total_nums * 10;
			prev_range_digits_sum += total_num_of_digits_in_range;
			total_num_of_digits_in_range = digit_range_width * total_nums;
		}
		
		kth_digit -= prev_range_digits_sum;

		ull number = static_cast<ull>(pow(10, digit_range_width-1)) + ((kth_digit-1)/digit_range_width);
	
		auto number_str = to_string(number);

		ull idx = (kth_digit-1)%digit_range_width;
		cout << number_str[idx] << "\n";

	}

	return 0;

}
