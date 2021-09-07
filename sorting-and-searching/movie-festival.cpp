#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int num_movies;
	cin >> num_movies;

	vector<pair<int, int>> movies(num_movies);

	for(int i = 0; i < num_movies; ++i) {
		int s, e;
		cin >> s >> e;
		movies[i].first = s;
		movies[i].second = e;
	}

	sort(movies.begin(), movies.end(), [](const auto& a, const auto& b)
	{
		return a.second < b.second;
	});

	int prev_movie_end = -1, watched_movies = 0;
	for(auto& m: movies) {
		if(prev_movie_end <= m.first) {
			watched_movies++;
			prev_movie_end = m.second;
		}
	}

	cout << watched_movies << "\n";

	return 0;

}
