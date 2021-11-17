#include<iostream>
using namespace std;

int main() {

	int a, res = 0;
	cin >> a;
	for (int i = 1; i <= a; i++) {
		res += i;
	}
	cout << res;

	return 0;
}