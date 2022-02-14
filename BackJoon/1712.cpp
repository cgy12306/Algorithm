#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long A, B, C, sum = 0;
	long long sum2 = 0;
	long long cnt = 0;
	cin >> A >> B >> C;

	if (B >= C) {
		cout << "-1";
	}
	else {
		cout << A / (C - B) + 1;
	}
	
}