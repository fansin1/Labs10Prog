//
// Created by fansin on 24.05.2019.
//
// Lab10.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "AvlTree.h"

int main()
{

    AvlTree<int> a;
    a.insert(12);
    a.insert(11);
    a.insert(13);
    a.insert(14);
    a.insert(15);
    a.insert(16);

    AvlTree<int>::iterator e = a.end();
    AvlTree<int>::iterator ait = a.begin();

    for(; ait != a.end(); ++ait) {
        std::cout << *ait << std::endl;
    }

    ait = a.begin();
    std::cout << *ait << std::endl;
    ait++;
    std::cout << *ait << std::endl;
    ait--;
    std::cout << *ait << std::endl;
    ait++;
    std::cout << *ait << std::endl;
    ait++;
    std::cout << *ait << std::endl;
    ait--;
    std::cout << *ait << std::endl;

    std::cout << *a.find(12) << std::endl;
    auto af = a.find(10);
    std::cout << (af == a.end()) << std::endl;

    a.remove(12);

    for(ait = a.begin(); ait != a.end(); ++ait) {
        std::cout << *ait << std::endl;
    }

    return 0;
}
