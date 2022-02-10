// https://www.acmicpc.net/problem/10825
// ������
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct student{
	string name;
	int kor, eng, math;
}student;
bool cmp(student a, student b) {
	if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;
	if (a.kor == b.kor && a.eng == b.eng) return a.math > b.math;
	if (a.kor == b.kor) return a.eng < b.eng;
	return a.kor > b.kor;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<student> v(N);
	
	for (int i = 0; i < N; i++) {
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}
	sort(v.begin(), v.end(), cmp);

	for (auto V : v) {
		cout << V.name << "\n";
	}
	
}