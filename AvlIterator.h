//
// Created by fansin on 24.05.2019.
//

#ifndef LABS2SEM_AVLITERATOR_H
#define LABS2SEM_AVLITERATOR_H

#include <iterator>
template<class T>
class AvlIterator: public std::iterator<std::input_iterator_tag, T>
{
public:
    AvlIterator(T* p);
    AvlIterator();

private:
    T* p;
};

#include "AvlIterator.tpp"

#endif //LABS2SEM_AVLITERATOR_H
