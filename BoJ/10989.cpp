#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	int N;
	cin >> N;

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		arr[x]++;
	}

	for (int i = 1; i <= 10000;i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
	}
}