#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long A, B, gcd, tmp, lcm, ori_A, ori_B;
	cin >> A >> B;
	ori_A = A;
	ori_B = B;
	if (A < B)swap(A, B);
	
	while (1) {
		if (A%B == 0) {
			gcd = B;
			break;
		}

		tmp = A;
		A = B;
		B = tmp - B;
		if (A < B)swap(A, B);

		if (B == 1) {
			gcd = B;
			break;
		}
	}
	lcm = gcd;
	tmp = lcm;
	while (1) {
		if (lcm % ori_A == 0 && lcm % ori_B == 0) {
			break;
		}
		lcm += tmp;
	}
	cout << gcd << "\n" << lcm;
}