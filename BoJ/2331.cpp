// https://www.acmicpc.net/problem/2331
// 반복수열
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int calc(int A, int P) {
	int num = 0, tmp = 1;

	while (A) {
		for (int i = 0; i < P; i++) {
			tmp *= (A % 10);
		}
		num += tmp;
		tmp = 1;
		A /= 10;
	}
	return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> D;
	vector<int>::iterator it;
	int A, P, num;
	cin >> A >> P;
	
	D.push_back(A);

	while (1) {
		A = calc(A, P);
		it = find(D.begin(), D.end(), A);
		if (it != D.end()) { // 있으면
			D.erase(it, D.end());
			break;
		}
		else D.push_back(A); // 없으면
	}
	
/*	for(auto next : D) {
		cout << next << "\n";
	}
*/
	cout << D.size();

}