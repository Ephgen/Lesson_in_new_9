#include "Three.h"

Three::Three() {
	root = nullptr;
}
Three::~Three() {
	Del();
}

void Three::Print(Elem* node) {
	if (node != 0) {
		Print(node->left);
		cout << node->Name
			<< node->Match
			<< node->Opponent
			<< endl;
		Print(node->right);
	}
}
Elem* Three::Search(Elem* node, char* k) {
	while (node != 0 && strcmp(k, node->Name) != 0) {
		if (strcmp(k, node->Name) < 0)
			node = node->left;
		else
			node = node->right;
	}
	return node;
}
Elem* Three::Min(Elem* node) {
	if (node != 0) {
		while (node->left != 0) node = node->left;
		return node;
	}
}
Elem* Three::Max(Elem* node) {
	if (node != 0) {
		while (node->right != 0) node = node->right;
		return node;
	}
}
Elem* Three::Next(Elem* node) {
	Elem* y = 0;
	if (node != 0) {
		if (node->right != 0) {
			return Min(node->right);
		}
		y = node->parent;
		while (y != 0 && node == y->right) {
			node = y;
			y = y->parent;
		}
	}
	return y;
}
Elem* Three::Previous(Elem* node) {
	Elem* y = 0;
	if (node != 0) {
		if (node->left != 0) {
			return Max(node->left);
		}
		y = node->parent;
		while (y != 0 && node == y->left) {
			node = y;
			y = y->parent;
		}
	}
	return y;
}
Elem* Three::GetRoot() {
	return root;
}
void Three::Insert(Elem* z) {
	z->left = nullptr;
	z->right = nullptr;

	Elem* y = nullptr;
	Elem* node = root;

	while (node != 0) {
		y = node;
		if (strcmp(z->Name, node->Name) < 0)
			node = node->left;
		else
			node = node->right;
	}
	z->parent = y;
	if (y == 0)
		root = z;
	else if (strcmp(z->Name, y->Name) < 0) {
		y->left = z;
		cout << " left ";
	}
	else {
		y->right = z;
		cout << " right ";
	}
}
void Three::Del(Elem* z) {
	if (z != 0) {
		Elem* node, * y;
		if (z->left == 0 || z->right == 0)
			y = z;
		else
			y = Next(z);
		if (y->left != 0)
			node = y->left;
		else
			node = y->right;

		if (node != 0)
			node->parent = y->parent;
		if (y->parent == 0)
			root = node;
		else if (y == y->parent->left)
			y->parent->left = node;
		else
			y->parent->right = node;

		if (y != z) {
			strcpy_s(z->Name, y->Name);
			strcpy_s(z->Opponent, y->Opponent);
			strcpy_s(z->Match, y->Match);
			z->oppPoints = y->oppPoints;
			z->ownerPoints = y->ownerPoints;
		}
		delete y;
	}
	else
		while (root != 0)
			Del(root);
}