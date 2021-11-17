#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	stack<int> st;
	vector<char> v;
	int n, arr[100001] = { 0, };
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int j = 0;
	for (int i = 1; i <= n; i++) {
		st.push(i);
		v.push_back('+');
		while (!st.empty() && st.top() == arr[j]) {
			st.pop();
			v.push_back('-');
			j++;
		}
	}
	if (!st.empty()) cout << "NO";
	else {
		for (auto i : v) cout << i << "\n";
	}
}