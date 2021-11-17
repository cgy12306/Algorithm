#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;

	
	int cnt = 1, N, sum = 0;
	cin >> N;

	for (int j = 0; j < N; j++) {
		cin >> s;
	
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'O') {
				sum += cnt;
				cnt++;
				if (s[i + 1] == 'X' || s[i + 1] == 0) cnt = 1;
			}
		}
		cout << sum << "\n";
		sum = 0;
	}

}