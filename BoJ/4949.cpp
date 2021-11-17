#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	stack<char> st;
	
	while (1) {
		bool flag = false;
		string s;
		getline(cin, s);
		
		if (!s.compare(".")) break;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') st.push('(');
			else if (s[i] == '[')st.push('[');

			if (s[i] == ')') {
				if (st.empty() || st.top() != '(') {
					flag = true;
					break;
				}
				else {
					st.pop();
				}
			}
			else if (s[i] == ']') {
				if (st.empty() || st.top() != '[') {
					flag = true;
					break;
				}
				else {
					st.pop();
				}
			}
		}
		while (!st.empty()) {
			flag = true;
			st.pop();
		}
		if (flag) cout << "no" << "\n";
		else cout << "yes" <<"\n";
		

	}
}