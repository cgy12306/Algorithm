#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v1.push_back(num);
		v2.push_back(num);
	}

	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());

	for (int i = 0; i < N; i++) {
		cout << lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin() <<" ";
	}
}