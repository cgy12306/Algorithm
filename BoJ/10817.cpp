#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int A, B, C;
	vector<int> v;
	cin >> A >> B >> C;
	v.push_back(A);
	v.push_back(B);
	v.push_back(C);

	sort(v.begin(), v.end());
	cout << v[1];
}