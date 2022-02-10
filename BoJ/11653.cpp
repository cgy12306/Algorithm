#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int start = 2;
	vector<int> V;

	while (N >= start) {
		if (N%start == 0) {
			N /= start;
			V.push_back(start);
		}
		else {
			start++;
		}
	}
	for (auto v : V) {
		cout << v <<"\n";
	}
}