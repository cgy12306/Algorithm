// https://www.acmicpc.net/submit/15652
// N°ú M (4)
#include <iostream>
using namespace std;
int N, M;
int arr[9];
bool visited[9];
void dfs(int cnt, int num) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = num; i <= N; i++) {
		if (!visited[i]) {
			arr[cnt] = i;
			dfs(cnt + 1, i);
		}
	}
}
int main() {
	cin >> N >> M;
	dfs(0, 1);
}