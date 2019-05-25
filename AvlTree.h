//
// Created by fansin on 24.05.2019.
//

#ifndef LABS2SEM_AVLTREE_H
#define LABS2SEM_AVLTREE_H

#include <iterator>
#include "AvlIterator.h"

template<class T, class Compare = std::less<T>>
class AvlTree {
public:

    struct Node {
        T key;
        unsigned char height;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(const T& k) { key = k; left = right = 0; height = 1; }
    };

    typedef AvlIterator<Node> iterator;
    typedef AvlIterator<Node> const_iterator;

    AvlTree();
    AvlTree(const AvlTree&);
    AvlTree<T, Compare>& operator=(const AvlTree& avl);
    Compare comp;

    template<class InputIt>
    void assign(InputIt first, InputIt last);

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
    Node* insert(Node* p, const T& value, iterator& out);

    Node* root = nullptr;

    unsigned char height(Node* p);

    int bFactor(Node* p);

    void fixHeight(Node* p);

    Node* rotateRight(Node* p);

    Node* rotateLeft(Node* q);

    Node* balance(Node* p);

};

#include "AvlTree.tpp"


#endif //LABS2SEM_AVLTREE_H
