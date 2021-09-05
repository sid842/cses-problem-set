#include <iostream>
#include <vector>

using namespace std;

vector<string> GrayCode(int n) {
	if(n == 1) {
		return {"0", "1"};
	}

	auto codes_of_n_minus_1 = GrayCode(n-1);

	auto codes{codes_of_n_minus_1};
	for(auto& code: codes)
		code = "0" + code;
	for(int i = codes_of_n_minus_1.size() - 1; i >= 0; --i) {
		codes.push_back("1" + codes_of_n_minus_1[i]);
	}

	return codes;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	auto codes = GrayCode(n);

	for(auto& code: codes)
		cout << code << "\n";

	return 0;

}
