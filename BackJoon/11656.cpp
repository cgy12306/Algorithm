#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	vector<string> V;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		V.push_back(s.substr(i, s.size() - i));
	}

	sort(V.begin(), V.end());
	for (auto v : V) cout << v << "\n";
}