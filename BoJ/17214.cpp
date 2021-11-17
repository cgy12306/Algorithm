#include<iostream>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;

	cin >> s;
	unsigned int num, num2 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'x') {
			num = stoi(s.substr(i-1))/2;
			if (i + 1 == s.size()) break;
			num2 = stoi(s.substr(i + 2, s.size() - i + 2));
		}

	}
	cout << num;
	if (num == 1) {
		cout << "xx";
		if (num2 == 1) {
			cout << "+x";
		}
		else if (num2 == 0) {
			cout << "+W";
			return 0;
		}
		else {
			cout << "+" << num2 << "x";
		}
		cout << "+W";
	}
	else {
		cout << num << "xx";
		if (num2 == 1) {
			cout << "+x";
		}
		else if (num2 == 0) {
			cout << "+W";
			return 0;
		}
		else {
			cout <<"+" << num2 << "x";
		}
		cout << "+W";
	}

}