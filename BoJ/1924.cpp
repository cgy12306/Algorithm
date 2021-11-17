#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> x >> y;
	
	if (x == 1) {
		
	}
	else if (x == 2) {
		y += (31 * 1) + (30 * 0);
	}
	else if (x == 3) {
		y += (31 * 1) + (30 * 0) + 28;
	}
	else if (x == 4) {
		y += (31 * 2) + (30 * 0) + 28;
	}
	else if (x == 5) {
		y += (31 * 2) + (30 * 1) + 28;
	}
	else if (x == 6) {
		y += (31 * 3) + (30 * 1) + 28;
	}
	else if (x == 7) {
		y += (31 * 3) + (30 * 2) + 28;
	}
	else if (x == 8) {
		y += (31 * 4) + (30 * 2) + 28;
	}
	else if (x == 9) {
		y += (31 * 5) + (30 * 2) + 28;
	}
	else if (x == 10) {
		y += (31 * 5) + (30 * 3) + 28;
	}
	else if (x == 11) {
		y += (31 * 6) + (30 * 3) + 28;
	}
	else if (x == 12) {
		y += (31 * 6) + (30 * 4) + 28;
	}

	switch (y % 7) {
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	case 0:
		cout << "SUN";
		break;
	}

	return 0;
}