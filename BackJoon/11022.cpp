#include<iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, n;
	cin >> n;
	for (int i = 1; i <=n; i++) {
		cin >> a >> b;
		cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b <<"\n";
	}


	return 0;
}