#include "AvlTree.h"

template<class T, class Compare>
AvlTree<T, Compare>::AvlTree() {
	comp = Compare();
}

template<class T, class Compare>
AvlTree<T, Compare>::AvlTree(const AvlTree& avl) {
}

template<class T, class Compare>
AvlTree<T, Compare>& AvlTree<T, Compare>::operator=(const AvlTree & avl) {
    AvlTree<T, Compare> a;
	return a;
}

template<class T, class Compare>
typename AvlTree<T, Compare>::iterator AvlTree<T, Compare>::begin() {
	return iterator();
}

template<class T, class Compare>
typename AvlTree<T, Compare>::const_iterator AvlTree<T, Compare>::cbegin() {
	return const_iterator();
}

template<class T, class Compare>
typename AvlTree<T, Compare>::iterator AvlTree<T, Compare>::end() {
	return iterator();
}

template<class T, class Compare>
typename AvlTree<T, Compare>::const_iterator AvlTree<T, Compare>::cend() {
	return const_iterator();
}

template<class T, class Compare>
typename AvlTree<T, Compare>::Node* AvlTree<T, Compare>::insert(Node * p, const T & value, iterator& out)
{
	if (!p) {
		Node* a = new Node(value);
		out = iterator(a);
		return a;
	}

	if (comp(value, p->key)) {
		p->left = insert(p->left, value, out);
	}
	else {
		p->right = insert(p->right, value, out);
	}

	return balance(p);
}

template<class T, class Compare>
typename AvlTree<T, Compare>::iterator AvlTree<T, Compare>::insert(const T& value) {
	iterator res;
	root = insert(root, value, res);
	return res;
}

template<class T, class Compare>
typename AvlTree<T, Compare>::iterator AvlTree<T, Compare>::remove(const T& value) {
	return iterator();
}

template<class T, class Compare>
typename AvlTree<T, Compare>::iterator AvlTree<T, Compare>::find(const T& value) {
	return iterator();
}

template<class T, class Compare>
typename AvlTree<T, Compare>::const_iterator AvlTree<T, Compare>::find(const T& value) const {
	return const_iterator();
}

template<class T, class Compare>
bool AvlTree<T, Compare>::empty() const {
	return false;
}

template<class T, class Compare>
size_t AvlTree<T, Compare>::size() const {
	return size_t();
}

template<class T, class Compare>
unsigned char AvlTree<T, Compare>::height(Node* p) {
	return p ? p->height : 0;
}

template<class T, class Compare>
int AvlTree<T, Compare>::bFactor(Node* p) {
	return height(p->right) - height(p->left);
}

template<class T, class Compare>
void AvlTree<T, Compare>::fixHeight(Node* p) {
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

template<class T, class Compare>
typename AvlTree<T, Compare>::Node* AvlTree<T, Compare>::rotateRight(Node * p) {
	Node* q = p->left;

	p->left = q->right;
	q->right = p;
	fixHeight(p);
	fixHeight(q);

	return p;
}

template<class T, class Compare>
typename  AvlTree<T, Compare>::Node* AvlTree<T, Compare>::rotateLeft(Node* q) {
	Node* p = q->right;

	q->right = p->left;
	p->left = q;
	fixHeight(q);
	fixHeight(p);

	return p;
}

template<class T, class Compare>
typename  AvlTree<T, Compare>::Node* AvlTree<T, Compare>::balance(Node* p) {
	fixHeight(p);

	if (bFactor(p) == 2) {
		if (bFactor(p->right) < 0)
			p->right = rotateRight(p->right);
		return rotateLeft(p);
	}

	if (bFactor(p) == -2) {
		if (bFactor(p->left) > 0)
			p->left = rotateLeft(p->left);
		return rotateRight(p);
	}

	return p;
}

template<class T, class Compare>
template<class InputIt>
void AvlTree<T, Compare>::assign(InputIt first, InputIt last)
{
}