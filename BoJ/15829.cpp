#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int N;

	cin >> N >> s;
	long long hash = 0;
	long long M = 1234567891, thone = 31, r = 1;

	for (int i = 0; i < N; i++) {
		hash = (hash + (s[i] - 0x60) * r) % M;
		r = (r*thone) % M;
	}
	cout << hash;

}


