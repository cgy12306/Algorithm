#include<iostream>
using namespace std;
long long N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int layer = 0;
	if (N == 1) {
		cout << '1';
		return 0;
	}
	for (int i = 2; i <= N; layer++) {
		i += 6 * layer;
	}
	cout << layer;
}


// 6 12 18 24 36