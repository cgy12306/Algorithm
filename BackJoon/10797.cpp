#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		if (num == N) cnt++;
	}
	cout << cnt;
}