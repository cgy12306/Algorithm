#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char s[101];


	while (1) {
		cin.getline(s, 101);
		if (cin.eof()) {
			break;
		}
		cout << s << "\n";
	}
}