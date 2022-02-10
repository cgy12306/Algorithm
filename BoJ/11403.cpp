// https://www.acmicpc.net/problem/11403
// 경로 찾기
#include<iostream>
#include<algorithm>

using namespace std;
int N;
int arr[101][101];
void floyd_warshall() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][k] && arr[k][j]) {
					arr[i][j] = 1;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	floyd_warshall();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}