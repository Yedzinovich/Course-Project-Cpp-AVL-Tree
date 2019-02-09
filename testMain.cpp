//
// Created by Inna on 4/26/2018.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "AVLTree.cpp"

int main(){

    AVLTree<int> tree;

    tree.insertItem(9);
    tree.insertItem(5);
    tree.insertItem(10);
    tree.insertItem(0);
    tree.insertItem(6);
    tree.insertItem(11);
    tree.insertItem(-1);
    tree.insertItem(1);
    tree.insertItem(2);
    //tree.insertItem(80);
    //tree.insertItem(90);

    tree.deleteItem(10);
    tree.preorder();

    system("PAUSE");

    return 0;
}
