
/***********************************************************************************************/
/* Programmer: Inna Yedzinovich                                                                */
/* Date: 10/23/2017                                                                            */
/* Purpose: This class creates a binary tree data structure.                                   */
/*          It is a Template class can be used to implement a binary tree for a generic type T.*/
/* Professor: Anna Salvati                                                                     */
/***********************************************************************************************/

#ifndef TREE_PROJECT_BINARYTREE_H
#define TREE_PROJECT_BINARYTREE_H
#include <stack>
#include <queue>

//This structure creates Binary Node for the Binary Tree
template <class T>
struct Bnode{

    T info;            //T type contains any datatype for the binary tree
    Bnode<T> *left;    //pointer to the address of the left node of the binary tree
    Bnode<T> *right;   //pointer to the address of the right node of the binary tree
    int count = 0;     //count variable contains a number of duplicated data nodes in the binary tree
    int balance = 0;   //balance variable contains a balance factor of the AVL tree

};

template <class T>
class BinaryTree{

private:
    Bnode<T>* copyTree(Bnode<T>*);    //the function makes a deep copy of the binary tree
    void deleteTree(Bnode<T>*&);      //the function deletes a binary tree
    void inorder(Bnode<T>*);          //the function prints binary nodes in inorder sequence (inorder traversal)
    void preorder(Bnode<T>*);         //the function prints binary tree in preorder sequence (preorder traversal)
    void postorder(Bnode<T>*);        //the function prints binary tree in postorder sequence (postorder traversal)
    int treeHeight(Bnode<T>*);        //the function returns the height of the binary tree as an integer
    int nodeCount(Bnode<T>*);         //the function return a number of nodes in binary tree as an integer

    void inorder(Bnode<T>*, std::queue<T>&); //this function takes a queue as a reference parameter it fills it up
                                             //with all data from binary tree in inorder sequence (inorder traversal)

protected:
    Bnode<T> *root;                 //the root of the binary tree
public:

    BinaryTree();                     //constructor with parameters
    ~BinaryTree();                    //destructor
    BinaryTree(const BinaryTree<T>&); //copy constructor
    BinaryTree& operator=(const BinaryTree<T>&); //overloaded = operator
    void inorder();                  //function to perform inorder binary tree traversal
    void preorder();                 //function to perform preorder binary tree traversal
    void postorder();                //function to pefromm postorder binary tree traversal
    bool isEmpty();                  //boolean function to check if binary tree is empty
    int treeHeight();                //integer function that returns a height of the binary tree
    int nodeCount();                 //integer function that returns a number of nodes in the binary tree
    void inorder(std::queue<T>&);    //function that receives a queue as a reference parameter and fill it up with
                                     //all data from the binary tree in inorder sequence


};

#endif
