#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;
	char s[4];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		a = s[0] - 0x30;
		b = s[2] - 0x30;
		cout << a+b << "\n";
	}


	return 0;
}