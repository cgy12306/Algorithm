// https://www.acmicpc.net/problem/11047
// µ¿Àü 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> coin;
int N, K,  res = 999999999, cnt = 0;
int counting() {
	int sum = 0;
	int tmpK = 0;
	int coin_cnt = 0;
	tmpK = K;
	for (int i = coin.size() - 1; i >= 0; i--) {
		if (K == sum) break;
		
		if (tmpK < coin[i]) continue;
		else {
			cnt = tmpK / coin[i];
			coin_cnt += cnt;
			tmpK = tmpK % coin[i];
			sum += coin[i] * cnt;
			cnt = 0;
		}
	}
	return coin_cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		coin.push_back(num);

		res = min(res, counting());
	}
	cout << res;
}