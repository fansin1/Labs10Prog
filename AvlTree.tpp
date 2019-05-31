#include "AvlTree.h"

template<class T, class Compare>
AvlTree<T, Compare>::AvlTree() {
	_comp = Compare();
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
    Node<T>* p = _root;

    while (p->left != nullptr) {
        p = p->left;
    }

	return iterator(p);
}

template<class T, class Compare>
typename AvlTree<T, Compare>::const_iterator AvlTree<T, Compare>::cbegin() {
    Node<T>* p = _root;

    while (p->left != nullptr) {
        p = p->left;
    }

	return const_iterator(p);
}

template<class T, class Compare>
typename AvlTree<T, Compare>::iterator AvlTree<T, Compare>::end() {
    return iterator(nullptr);
}

template<class T, class Compare>
typename AvlTree<T, Compare>::const_iterator AvlTree<T, Compare>::cend() {
	return const_iterator(nullptr);
}

template<class T, class Compare>
Node<T>* AvlTree<T, Compare>::insert(Node<T>* p, const T & value, iterator& out)
{
	if (!p) {
		Node<T>* a = new Node(value);
		out = iterator(a);
		return a;
	}

	if (_comp(value, p->key)) {
		p->left = insert(p->left, value, out);
        p->left->parent = p;
	}
	else {
		p->right = insert(p->right, value, out);
        p->right->parent = p;
	}

	return balance(p);
}

template<class T, class Compare>
typename AvlTree<T, Compare>::iterator AvlTree<T, Compare>::insert(const T& value) {
	iterator res;
	_root = insert(_root, value, res);
	return res;
}

template<class T, class Compare>
typename AvlTree<T, Compare>::iterator AvlTree<T, Compare>::remove(const T& value) {
	_root = remove(_root, value);
	return iterator(nullptr);
}

template<class T, class Compare>
typename AvlTree<T, Compare>::iterator AvlTree<T, Compare>::find(const T& value) {
	Node<T> *p = _root;

	while (p->key != value) {
		if (p->key > value) {
			if (p->left != nullptr)
				p = p->left;
			else
				break;
		} else {
			if (p->right != nullptr)
				p = p->right;
			else
				break;
		}
	}

	if (p->key != value)
		p = nullptr;

	return iterator(p);
}

template<class T, class Compare>
typename AvlTree<T, Compare>::const_iterator AvlTree<T, Compare>::find(const T& value) const {
	Node<T> *p = _root;

	while (p->key != value) {
		if (p->key > value) {
			if (p->left != nullptr)
				p = p->left;
			else
				break;
		} else {
			if (p->right != nullptr)
				p = p->right;
			else
				break;
		}
	}

	if (p->key != value)
		p = nullptr;

	return const_iterator(p);
}

template<class T, class Compare>
bool AvlTree<T, Compare>::empty() const {
	return _size == 0;
}

template<class T, class Compare>
size_t AvlTree<T, Compare>::size() const {
	return _size;
}

template<class T, class Compare>
unsigned char AvlTree<T, Compare>::height(Node<T>* p) {
	return p ? p->height : 0;
}

template<class T, class Compare>
int AvlTree<T, Compare>::bFactor(Node<T>* p) {
	return height(p->right) - height(p->left);
}

template<class T, class Compare>
void AvlTree<T, Compare>::fixHeight(Node<T>* p) {
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

template<class T, class Compare>
Node<T>* AvlTree<T, Compare>::rotateRight(Node<T>* p) {
	Node<T>* q = p->left;

	p->left = q->right;
	q->right = p;
    q->parent = p->parent;
    p->parent = q;
    if (p->left != nullptr)
        p->left->parent = p;
	fixHeight(p);
	fixHeight(q);

	return p;
}

template<class T, class Compare>
Node<T>* AvlTree<T, Compare>::rotateLeft(Node<T>* q) {
	Node<T>* p = q->right;

	q->right = p->left;
	p->left = q;
    p->parent = q->parent;
    q->parent = p;
    if (q->right != nullptr)
        q->right->parent = q;
	fixHeight(q);
	fixHeight(p);

	return p;
}

template<class T, class Compare>
Node<T>* AvlTree<T, Compare>::balance(Node<T>* p) {
	fixHeight(p);

	if (bFactor(p) == 2) {
		if (bFactor(p->right) < 0) {
            p->right = rotateRight(p->right);
            p->right->parent = p;
        }
		return rotateLeft(p);
	}

	if (bFactor(p) == -2) {
		if (bFactor(p->left) > 0) {
            p->left = rotateLeft(p->left);
            p->left->parent = p;
        }
		return rotateRight(p);
	}

	return p;
}

template<class T, class Compare>
Node<T> *AvlTree<T, Compare>::findMin(Node<T> *p) {
	return p->left ? findMin(p->left) : p;
}

template<class T, class Compare>
Node<T> *AvlTree<T, Compare>::removeMin(Node<T> *p) {
	if (p->left == nullptr)
		return p->right;
	p->left = removeMin(p->left);
	p->left->parent = p;

	return balance(p);
}

template<class T, class Compare>
Node<T> *AvlTree<T, Compare>::remove(Node<T> *p, const T k) {
	if (!p) return nullptr;

	if (_comp(k, p->key)) {
		p->left = remove(p->left, k);
		p->left->parent = p;
	} else if (_comp(p->key, k)) {
		p->right = remove(p->right, k);
		p->right->parent = p;
	} else {
		Node<T>* q = p->left;
		Node<T>* r = p->right;
		delete p;

		if (!r) return q;

		Node<T>* min = findMin(r);
		min->right = removeMin(r);
		min->left = q;
		min->left->parent = min;

		return balance(min);
	}


	return balance(p);
}
