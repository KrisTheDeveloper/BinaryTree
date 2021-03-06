// Insertion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution {
public:

	void preOrder(Node *root) {

		if (root == NULL)
			return;

		cout << root->data << " ";

		preOrder(root->left);
		preOrder(root->right);
	}

	/*
	Node is defined as

	class Node {
		public:
			int data;
			Node *left;
			Node *right;
			Node(int d) {
				data = d;
				left = NULL;
				right = NULL;
			}
	};

	*/

	Node * insert(Node * root, int data) {

		if (root == nullptr)
		{
			root = new Node(data);
		}

		
		if (data < root->data)
			root->left = insert(root->left, data); //->left;
		if (data > root->data)
			root->right = insert(root->right,data);// ->right;
		

		return root;
	}

};

int main() {

	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	cin >> t;

	while (t-- > 0) {
		cin >> data;
		root = myTree.insert(root, data);
	}

	myTree.preOrder(root);

	return 0;
}