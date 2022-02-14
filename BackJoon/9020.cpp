// https://www.acmicpc.net/problem/9020
// ∞ÒµÂπŸ»Â¿« √ﬂ√¯
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool arr[10001];
bool is_prime(int num) {
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	int cnt = 0;
	int N;
	vector<pair<int, int>> V;
	cin >> N;

	for (int i = 2; i < 10001; i++) {
		if (is_prime(i)) {
			arr[i] = true;
		}
	}
	
	for (int n = 0; n < N; n++) {
		int num, left, right;
		cin >> num;

		left = right = num / 2;
		
		while (left >= 0) {
			if (arr[left] && arr[right]) {
				if (left + right == num) {
					cout << left << " " << right <<"\n";
					break;
				}
			}
			left -= 1;
			right += 1;
		}
	}
}