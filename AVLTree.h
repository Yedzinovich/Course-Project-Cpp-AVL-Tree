
/***********************************************************************************************/
/* Programmer: Inna Yedzinovich                                                                */
/* Date: 10/23/2017                                                                            */
/* Purpose: This class creates an AVL Tree data structure.                                     */
/*          It is a Template class can be used to implement a binary tree for a generic type T.*/
/* Professor: Anna Salvati                                                                     */
/***********************************************************************************************/

#ifndef UNTITLED_AVLTREE_H
#define UNTITLED_AVLTREE_H
#include "BinaryTree.cpp"

template <class T>
class AVLTree: public BinaryTree<T>{

private:
    void insertItem(Bnode<T>*&, T);        //function to insert data into the AVL Tree
    void deleteItem(Bnode<T> *&, T);       //function to delete data from the AVL Tree
    bool searchItem(Bnode<T>*&, T);        //boolean function to search data in the AVL Tree
    bool isBalanced(Bnode<T>*);            //boolean function to check if AVL Tree is balanced
    int getBalance(Bnode<T>*);             //integer function to return balance(help function for the isBalanced function)

    int avlheight(Bnode<T>*);              //integer function to return an AVL height
    int bfactor(Bnode<T>*);                //integer function to return balance factor of the AVL node
    void fixHeight(Bnode<T>*&);            //function to fix a height of an AVL Tree
    void rightRotation(Bnode<T>*&);        //function to perform right rotation of nodes in the AVL Tree
    void leftRotation(Bnode<T>*&);         //function to perform left rotation of nodes in the AVL Tree
    void toBalance(Bnode<T>*&);            //function to receive the node that should be balanced
    void deleteNode(Bnode<T>*&);           //function to delete node from AVL Tree (help function for deleteItem)
    T getValue(Bnode<T>*);                 //T function to return a value of the node
    int getCount(Bnode<T>*, T);            //integer function to return a number of duplicated nodes in the AVL tree


public:
    void deleteItem(T);                    //client call to delete data from the AVL Tree
    bool searchItem(T);                    //client call to search data in the AVL Tree
    void insertItem(T);                    //client call to insert data into the AVL Tree
    bool isBalanced();                     //boolean client call function to check if AVL Tree is balanced
    int getCount(T item);                  //integer client call function to return a number of duplicated nodes
                                           //in the AVL Trees
};


#endif
