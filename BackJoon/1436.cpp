#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	string snum;
	int cnt = 0, num = 665;
	while (1) {
		snum = to_string(num);
		if (snum.find("666")!=string::npos) {
			cnt++;
		}

		if (cnt == N) break;
		num++;
	}
	cout << num;
}