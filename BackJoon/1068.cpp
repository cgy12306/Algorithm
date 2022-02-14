// https://www.acmicpc.net/problem/1068
// Æ®¸®

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int del, N;
vector<int> tree[51];
bool deleted[51];

void bfs(int start) {
	queue<int> que;
	que.push(start);
	while (!que.empty()) {
		int leaf = que.front();
		que.pop();
		
		deleted[leaf] = true;

		for (int i = 0; i < tree[leaf].size(); i++) {	
			if (deleted[tree[leaf][i]]) continue;
			que.push(tree[leaf][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int parent;
	cin >> N;
	for (int child = 0; child < N; child++) {
		cin >> parent;
		if (parent == -1) continue;
		else {
			tree[parent].push_back(child);
		}
	}

	cin >> del;
	bfs(del);

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (!deleted[i]) {
			int delLeaf = 0;
			for (int j = 0; j < tree[i].size(); j++) {
				if (deleted[tree[i][j]])delLeaf++;
			}
			if (delLeaf == tree[i].size()) cnt++;
		}
	}
	
	cout << cnt;
}