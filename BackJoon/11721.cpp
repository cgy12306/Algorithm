#include<iostream>
#include<string.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char s[101] = { 0, };
	int cnt = 0;
	cin >> s;
	for (int i = 0; strlen(s); i++) {
		cout << s[cnt];
		cnt++;
		if (s[cnt] == 0)break;
		if (cnt % 10 == 0) {
			cout << "\n";
		}
	}

	return 0;
}