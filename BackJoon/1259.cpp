#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	string s1, s2;
	while (1) {
		cin >> N;
		if (N == 0)	break;
		s1 = to_string(N);
		s2 = s1;
		reverse(s1.begin(), s1.end());
		
		if (s1.compare(s2) == 0) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
}