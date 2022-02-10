#include<iostream>
using namespace std;
bool arr[100000000];
int d(int n) {
	int res = 0;
	res += n;

	do{	
		res += n % 10;
		n = n / 10;

	} while (n > 0);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 1; i <= 10000; i++) {
		int n = d(i);
		arr[n] = true;

	}
	for (int i = 1; i <= 10000; i++) {
		if (!arr[i]) cout << i << "\n";
	}
}