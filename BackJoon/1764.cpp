#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;
	string s;
	vector<string> d, db;


	for (int i = 0; i < N; i++) {
		cin >> s;
		d.push_back(s);
	}

	sort(d.begin(), d.end());

	for (int i = 0; i < M; i++) {
		cin >> s;
		if (binary_search(d.begin(), d.end(), s)) {
			db.push_back(s);
		}
	}

	sort(db.begin(), db.end());
	cout << db.size() << "\n";
	for (auto i : db) {
		cout << i << "\n";
	}
}