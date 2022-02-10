// https://www.acmicpc.net/problem/17298
// ¿ÀÅ«¼ö
#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;

	cin >> N;
	stack<int> s;
	vector<int> v;
	vector<int> ans(N, -1);

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	bool flag = false;
	for (int i = 0; i < N; i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			ans[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (auto a : ans) cout << a << " ";
}