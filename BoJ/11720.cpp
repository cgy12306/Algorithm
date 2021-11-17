#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, res = 0;
	char s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		s -= 0x30;
		res += s;

	}
	cout << res;

	return 0;
}