#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	
	if (b >= 45) {
		b -= 45;
	}
	else if (b < 45) {
		b += 60 - 45;
		if (a == 0) {
			a += 24;
		}
		a--;
	}

	cout << a << " "<< b;

	return 0;
}