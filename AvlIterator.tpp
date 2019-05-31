//
// Created by fansin on 24.05.2019.
//
#include "AvlTree.h"

template<class T>
AvlIterator<T>::AvlIterator(Node<T>* p) : p(p)  {
}
template<class T>
AvlIterator<T>::AvlIterator()  {
}

template<class T>
AvlIterator<T>& AvlIterator<T>::operator++() {
    if (!p->right) {
        while (p->parent != nullptr && p->parent->right == p) {
            p = p->parent;
        }
        if (p != nullptr)
            p = p->parent;
    } else {
        p = p->right;
        while (p->left != nullptr) {
            p = p->left;
        }
    }

    return *this;
}

template<class T>
AvlIterator<T> AvlIterator<T>::operator++(int) {
    if (!p->right) {
        while (p->parent != nullptr && p->parent->right == p) {
            p = p->parent;
        }
        if (p != nullptr)
            p = p->parent;
    } else {
        p = p->right;
        while (p->left != nullptr) {
            p = p->left;
        }
    }

    return *this;
}

template<class T>
AvlIterator<T> AvlIterator<T>::operator--(int) {
    if (!p->left) {
        while (p->parent != nullptr && p->parent->left == p) {
            p = p->parent;
        }
        if (p != nullptr)
            p = p->parent;
    } else {
        p = p->left;
        while (p->right != nullptr)
            p = p->right;
    }


    return *this;
}

template<class T>
AvlIterator<T>& AvlIterator<T>::operator--() {
    if (!p->left) {
        while (p->parent != nullptr && p->parent->left == p) {
            p = p->parent;
        }
        if (p != nullptr)
            p = p->parent;
    } else {
        p = p->left;
        while (p->right != nullptr)
            p = p->right;
    }

    return *this;
}

template<class T>
bool AvlIterator<T>::operator!=(const AvlIterator<T>& a) const {
    return this->p != a.p;
}

template<class T>
T AvlIterator<T>::operator*() const {
    return p->key;
}

template<class T>
bool AvlIterator<T>::operator==(const AvlIterator<T>& a) const {
    return this->p == a.p;
}
