#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int a;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto i : v) {
		cout << i << "\n";
	}
}