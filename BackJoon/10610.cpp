// https://www.acmicpc.net/problem/10610
// 30

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	string s;
	bool flag = false;
	int sum = 0;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i] - '0');
		sum += s[i] - '0';
	}
	sort(v.begin(), v.end(), greater<int>());
	
	if (v[v.size() - 1] == 0 && sum % 3 == 0) {
		for (int i = 0; i < s.size(); i++) {
			cout << v[i];
		}
	}
	else {
		cout << "-1";
	}

	return 0;
}