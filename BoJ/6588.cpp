// https://www.acmicpc.net/problem/6588
// ∞ÒµÂπŸ»Â¿« √ﬂ√¯
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool arr[1000001] = {false, false,};
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

	for (int i = 2; i < 1000000; i++) {
		if (is_prime(i)) {
			arr[i] = true;
		}
	}

	while(1){
		int num, left, right;
		cin >> num;
		if (num == 0) break;

		left = 3;
		right = num - 3;

		while (left <= right) {
			if (arr[left] && arr[right]) {
				if (left + right == num) break;
			}
			left += 2;
			right -= 2;
		}

		if (left > right) cout << "Goldbach's conjecture is wrong.\n";
		else {
			cout << num << " = " << left << " + " << right << "\n";
		}
		
	}
}