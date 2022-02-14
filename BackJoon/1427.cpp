#include<iostream>
#include<algorithm>
using namespace std;
int N;
int arr[11];
int main() {
	cin >> N;
	int cnt = 0;
	while (N > 0) {
		arr[cnt] = N % 10;
		N /= 10;
		cnt++;
	}
	for (int i = 0; i < cnt - 1; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (arr[i] <= arr[j]) swap(arr[i], arr[j]);
		}
	}
	for (int i = 0; i < cnt; i++) {
		cout << arr[i];
	}

}