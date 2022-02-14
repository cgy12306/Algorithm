// https://www.acmicpc.net/problem/5639
// 이진 검색 트리
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
}TreeNode;


TreeNode *insert(TreeNode *node, int key) {
	if (node == NULL) {
		node = (TreeNode *)malloc(sizeof(TreeNode));
		node->key = key;
		node->left = NULL;
		node->right = NULL;
	}
	else if (node->key > key) {
			node->left = insert(node->left, key);
		}
	else if(node->key < key) {
		node->right = insert(node->right, key);
	}
	return node;
	
}

void postorder(TreeNode *root) {
	if (root->left != NULL) postorder(root->left);
	if (root->right != NULL) postorder(root->right);
	cout << root->key << "\n";
}

void freedom(TreeNode *root) {
	if (root != NULL) {
		freedom(root->left);
		freedom(root->right);
		free(root);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	TreeNode *root;
	root = NULL;
	while (cin >> n) {
		root = insert(root, n);
	}
	postorder(root);
	freedom(root);
}