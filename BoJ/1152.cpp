#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	int cnt = 0;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') cnt++;
	}
	if (s[0] == ' ')cnt--;
	if (s[s.size() - 1] == ' ')cnt--;
	cnt++;
	cout << cnt;
}