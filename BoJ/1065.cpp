#include <iostream>
#include <cstring>
int arr[5];
using namespace std;

bool hansu(int n) {
	memset(arr, 0, sizeof(arr));
	int res = 0, cnt = 0;
	do {
		res = n % 10;
		arr[cnt] = res;
		n /= 10;
		cnt++;
	} while (n > 0);

	bool flag = false;
	
	for (int i = 0; i < cnt - 2; i++) {
		int x = arr[i + 2] - arr[i + 1];
		int y = arr[i + 1] - arr[i];
		if (x != y) flag = true;
	}

	if (flag) return false;
	else return true;

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	int N;
	cin >> N;
	int cnt = 0;
	if (N < 100) {
		cout << N;
		return 0;
	}
	else {
		for (int i = 100; i <= N; i++) {
			if (hansu(i))cnt++;
		}
	}
	
	cout << cnt + 99 ;
}