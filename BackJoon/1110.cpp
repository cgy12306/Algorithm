#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	int res = N;
	int cnt = 0;
	do {
		int x = (res / 10) + (res % 10); // ���ڸ� �� ��
		int y = res%10;

		res = y * 10 + (x % 10);
		cnt++;

	} while (res != N);

	cout << cnt;
}