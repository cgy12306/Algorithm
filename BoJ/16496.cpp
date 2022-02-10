// https://www.acmicpc.net/problem/16496
// 큰 수 만들기
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	vector<string> vs;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		vs.push_back(s);
	}

	sort(vs.begin(), vs.end(), cmp);
	string res;
	for (int i = 0; i < vs.size(); i++) {
		res += vs[i];
	}
	if (vs[0] == "0") cout << "0";
	else cout << res;

}