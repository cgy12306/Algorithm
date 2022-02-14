// https://www.acmicpc.net/problem/10815
// [10815] - 숫자 카드
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int N, M, num;
vector <int>A, B, check;

int search(int target) {
	int start = 0, end, mid;
	end = A.size() - 1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (A[mid] < target) start = mid + 1;
		else if (A[mid] > target) end = mid - 1;
		else if (A[mid] == target) return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		A.push_back(num);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		B.push_back(num);
	}
	

	sort(A.begin(), A.end());

	for(auto it = B.begin(); it != B.end(); ++it) {
		cout << search(*it) << " ";
	}

	return 0;

}