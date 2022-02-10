#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001], N;
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] >= arr[j]) swap(arr[i], arr[j]);
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}

}