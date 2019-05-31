//
// Created by fansin on 24.05.2019.
//
#ifndef LABS2SEM_AVLTREE_H
#define LABS2SEM_AVLTREE_H

#include <iterator>

template<class T>
struct Node {
    T key;
    unsigned char height;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
    Node<T>* parent = nullptr;
    explicit Node(const T& k) { key = k; left = right = 0; height = 1; }
};

template<class T>
class AvlIterator: public std::iterator<std::input_iterator_tag, Node<T>>
{
public:
    explicit AvlIterator(Node<T>* p);
    AvlIterator();
    bool operator!=(const AvlIterator<T>&) const;
    bool operator==(const AvlIterator<T>&) const;
    T operator*() const;
    AvlIterator<T>& operator++();
    AvlIterator<T> operator++(int);
    AvlIterator<T>& operator--();
    AvlIterator<T> operator--(int);
private:
    Node<T>* p;
};

template<class T, class Compare = std::less<T>>
class AvlTree {
public:

    typedef AvlIterator<T> iterator;
    typedef const AvlIterator<T> const_iterator;

    AvlTree();
    AvlTree(const AvlTree&);
    AvlTree<T, Compare>& operator=(const AvlTree& avl);

    iterator begin();
    const_iterator cbegin();
    iterator end();
    const_iterator cend();

    iterator insert(const T& value);
    iterator remove(const T& value);
    iterator find(const T& value);
    const_iterator find(const T& value) const;

    bool empty() const;
    size_t size() const;

private:
    Node<T>* insert(Node<T>* p, const T& value, iterator& out);

    Node<T>* _root = nullptr;

    size_t _size = 0;

    unsigned char height(Node<T>* p);

    int bFactor(Node<T>* p);

    void fixHeight(Node<T>* p);

    Node<T>* rotateRight(Node<T>* p);

    Node<T>* rotateLeft(Node<T>* q);

    Node<T>* balance(Node<T>* p);

    Node<T>* findMin(Node<T>* p);

    Node<T>* removeMin(Node<T>* p);

    Node<T>* remove(Node<T>* p, const T k);

    Compare _comp;

};


#include "AvlIterator.tpp"

#include "AvlTree.tpp"


#endif //LABS2SEM_AVLTREE_H
