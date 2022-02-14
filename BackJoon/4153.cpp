#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long a, b, c;

	while (1) {
		cin >> a >> b >> c;
		if (!a && !b && !c) break;

		if ((a*a) + (b * b) == (c * c) || (a*a) == (b * b) + (c * c) || (a*a) +  (c * c)== (b * b)) cout << "right" <<"\n";
		else cout << "wrong"<<"\n";
	}
}