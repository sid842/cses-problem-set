#include <iostream>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for(int k = 1; k <= n; ++k) {
		using ll = long long;
		
		ll k_sqr = k*k;
		ll k_sqr_minus_1 = k_sqr-1;

		ll total_ways_to_place_two_pieces = 0;
		if(k_sqr%2 == 0)
			total_ways_to_place_two_pieces = (k_sqr/2)*k_sqr_minus_1;
		else 
			total_ways_to_place_two_pieces = (k_sqr_minus_1/2)*k_sqr;

		ll num_of_3_x_2_rects_on_board = 2LL * (k-1) * (k-2); //2 constant is for 3x2 and 2x3
		ll total_ways_knights_attack_on_board = num_of_3_x_2_rects_on_board * 2; //2 ways to places 2 knights attacking each other in 3x2 rect

		cout << (total_ways_to_place_two_pieces - total_ways_knights_attack_on_board) << "\n";

	}

	return 0;

}
