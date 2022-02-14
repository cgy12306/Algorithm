#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	string s;
	stack<char> st;
	bool flag = true;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '(') st.push(s[j]);
			else if(s[j] == ')') {
				if (st.empty()) {
					cout << "NO" << "\n";
					flag = false;
					break;
				}
				st.pop();
			}
		}
		if (!st.empty()) {
			cout << "NO" << "\n";
			flag = false;

		}

		if (flag) cout << "YES" << "\n";
		
		while (!st.empty()) st.pop();
		flag = true;
	}
}