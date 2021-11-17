#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, max, min, a;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (i == 0) {
			min = a;
			max = a;
		}
		if (min > a) {
			min = a;
		}
		if (max < a) {
			max = a;
		}
	}
	cout << min << " " << max;
}