#include <iostream>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	//This a and b variables logic I am not able to understand.
	//n/=2 makes sense since each round we are eliminating half the people.
	//a can be inversion of n, since we are multiplying a by 2 everytime.
	//b can be the offset then. 

	int a = 1, b = 0;
	while(n > 0) {
		// cout << "\n Watchpoint: " << a << " " << b << " " << n << "\n";
		for(int i = 2; i <= n; i+=2) {
			cout << a*i + b << " ";
		}
		if(n&1) {
			cout << (a+b) <<" ";
			b += a;
		} else {
			b -= a;
		}

		n >>= 1;
		a <<= 1;
	}

	return 0;

}
