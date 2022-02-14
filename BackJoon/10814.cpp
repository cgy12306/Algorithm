#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool comp(pair<int,string> a, pair<int,string> b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, age;
	string name;
	vector<pair<int, string>> pv;

	cin >> N;



	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		pv.push_back({ age, name });
	}
	stable_sort(pv.begin(), pv.end(), comp);

	for (auto i : pv) {
		cout << i.first << " " << i.second << "\n";
	}

}