#include<iostream>
#include<string>
using namespace std;

bool bit[22];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		int x;
		cin >> s;

		if (!s.compare("add")) {
			cin >> x;
			bit[x] = 1;
		}
		else if (!s.compare("remove")) {
			cin >> x;
			bit[x] = 0;
		}
		else if (!s.compare("check")) {
			cin >> x;
			cout << bit[x] << "\n";
		}
		else if (!s.compare("toggle")) {
			cin >> x;
			if (bit[x] == 0) bit[x] = 1;
			else bit[x] = 0;
		}
		else if (!s.compare("all")) {
			for (int j = 1; j <= 21; j++) bit[j] = 1;
		}
		else if (!s.compare("empty")) {
			for (int j = 1; j <= 21; j++) bit[j] = 0;
		}
	}
}