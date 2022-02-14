#include<iostream>
#include<cmath>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long A, B, V, height = 0, day = 1;
	cin >> A >> B >> V;
	
	day = ceil((double)(V - B) / (A - B));
	cout << day;
}