// https://www.acmicpc.net/problem/5052
// 전화번호 목록
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, N;

	cin >> T;
	
	for (int t = 0; t < T; t++) {
		cin >> N;
		
		vector<string> v;
		
		bool flag = false;

		for (int n = 0; n < N; n++) {
			string s;

			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] == v[i + 1].substr(0, v[i].size())) {
				flag = true;
				break;
			}
		}
		if (flag) cout << "NO\n";
		else cout << "YES\n";
		flag = false;
		while (!v.empty()) v.pop_back();
		
	}
}