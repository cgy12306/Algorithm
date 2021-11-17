#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int H, W, N, T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		int ho, ch;
		if (N%H == 0) {
			ch = H * 100;
			ho = (N / H);
		}
		else {
			ch = (N%H) * 100;
			ho = (N / H) + 1;
		}
		
		cout<< ho + ch << "\n";
	}


}