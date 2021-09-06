#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsApartmentInRange(int desire, int actual, int diff) {
	return desire - diff <= actual && actual <= desire + diff;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int num_apartments, num_applicants, allowed_diff;
	cin >> num_applicants >> num_apartments >> allowed_diff;

	vector<int> applicants(num_applicants), apartments(num_apartments);
	for(int& a: applicants)
		cin >> a;

	for(int& a: apartments)
		cin >> a;


	sort(applicants.begin(), applicants.end());
	sort(apartments.begin(), apartments.end());

	int ans = 0;
	int i = 0, j = 0;
	while(i < num_applicants && j < num_apartments) {
		if(IsAppartmentInRange(applicants[i], apartments[j], allowed_diff)) {
			i++, j++;
			ans++;
		} else if(apartments[j] < applicants[i] - allowed_diff) {
			//Apartment j cannot be used by other applicants with higher desire.
			j++;
		} else {
			//Apartment was too big for applicant.
			i++;
		}
	} 

	cout << ans << "\n";

	return 0;

}
