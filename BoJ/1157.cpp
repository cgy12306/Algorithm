#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	
	int a['z'+1] = { 0, };

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 'a' - 'A';
		a[s[i]]++;
	}

	int max = 0, tmp_idx, cnt = 0;

	for (int i = 'A'; i <= 'Z'; i++) {
		if (a[i] > max) {
			max = a[i];
			tmp_idx = i;
		}
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		if (a[i] == max)cnt++;
	}

	if (cnt >= 2) cout << '?';
	else if (cnt == 1) {
		cout << (char)tmp_idx;
	}
}