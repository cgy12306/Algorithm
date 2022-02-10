// https://www.acmicpc.net/problem/6603
// ·Î¶Ç
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int K, arr[50], tmparr[7];
bool visited[50];
void dfs(int cnt, int num) {
	if (cnt == 6) {
		for (int i = 0; i < cnt; i++) {
			cout << tmparr[i] <<" ";
		}
		cout << "\n";
		return;
	}
	for (int i = num; i < K; i++) {
		if (!visited[i]) {
			visited[i] = true;
			tmparr[cnt] = arr[i];
			dfs(cnt + 1, i + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	do {
		cin >> K;
		if (K == 0) break;
		memset(arr, 0, sizeof(int) * 50);
		memset(tmparr, 0, sizeof(int) * 7);
		memset(visited, false, sizeof(bool) * 50);
		for (int k = 0; k < K; k++) {
			cin >> arr[k];
		}


		dfs(0, 0);
		cout << "\n";
	} while (1);

}