#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
bool is_prime(int num) {
	int cnt = 0;
	if (num == 1) return false;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) cnt++;
	}
	if (cnt > 0) return false;
	return true;
}

int main() {
	int N, M;
	cin >> M >> N;
	int Min=-1;
	int sum = 0;
	for (int i = M; i <= N; i++) {
		if (is_prime(i)) {
			sum += i;
			if (Min == -1) Min = i;
		}
	}
	
	if (Min == -1) cout << "-1";
	else {
		cout << sum << "\n" << Min;
	}
	
}