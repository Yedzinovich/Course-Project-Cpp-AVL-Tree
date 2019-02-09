#include "BinaryTree.h"
#include <iostream>

/*********************************************************************************************/
/* Programmer: Inna Yedzinovich                                                              */
/* Date: 10/23/2017                                                                          */
/* Purpose: There is an implementation file for the binary tree                              */
/* Professor: Anna Salvati                                                                   */
/*********************************************************************************************/


/*************************FUNCTIONS IMPLEMENTATION********************************************/

template <class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    deleteTree(root);
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> & other) {

    if(other.root == nullptr)
        root = nullptr;
    else
        root=copyTree(other.root);
}

template <class T>
Bnode<T>* BinaryTree<T>::copyTree(Bnode<T> *copyNode){
    if(copyNode == nullptr)
        return NULL;

    Bnode<T> *temp = new Bnode<T>;
    temp->info = copyNode->info;
    temp->count = copyNode->count;
    temp->left = copyTree(copyNode->left);
    temp->right = copyTree(copyNode->right);


}

template  <class T>
void BinaryTree<T>::deleteTree(Bnode<T> *&deleteNode) {

    if(deleteNode!= nullptr){
        deleteTree(deleteNode->left);
        deleteTree(deleteNode->right);
        delete deleteNode;
        deleteNode = nullptr;
    }
}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T> & other) {

    if (this!=&other){
        if (root != nullptr)
            deleteTree(root);
        if(other.root== nullptr)
            root = nullptr;
        else
            root = copyTree(other.root);
    }
    return *this;
}

template <class T>
void BinaryTree<T>::preorder() {
    preorder(root);
}

template <class T>
void BinaryTree<T>::preorder(Bnode<T> * p) {
    if(p!= nullptr){
        std::cout<<p->info<<"\n";
        preorder(p->left);
        preorder(p->right);
    }
}

template <class T>
void BinaryTree<T>::inorder() {
    inorder(root);
}

template <class T>
void BinaryTree<T>::inorder(Bnode<T> *p) {
    if(p!= nullptr){
        inorder(p->left);
        std::cout<<p->info<<"\n";
        inorder(p->right);
    }
}

template <class T>
void BinaryTree<T>::postorder() {
    postorder(root);
}

template <class T>
void BinaryTree<T>::postorder(Bnode<T> *p) {
    if(p!= nullptr){
        postorder(p->left);
        postorder(p->right);
        std::cout<<p->info<<"\n";
    }
}

template <class T>
bool BinaryTree<T> ::isEmpty() {
    return  (root == NULL);
}

template <class T>
int BinaryTree<T>::treeHeight() {
    return treeHeight(root);
}

template <class T>
int BinaryTree<T>::treeHeight(Bnode<T>*p) {

    if (p== nullptr)
        return 0;
    else
    {
        int leftWalk = treeHeight(p->left);
        int rightWalk = treeHeight(p->right);

        if (leftWalk > rightWalk)
            return 1+leftWalk;

        else return 1+rightWalk;
    }

}

template <class T>
void BinaryTree<T>::inorder(std::queue<T> &st) {

    inorder(root, st);
}

template <class T>
void BinaryTree<T>::inorder(Bnode<T> *p, std::queue<T> &st) {

    if(p!= nullptr){
        inorder(p->left, st);
        st.push(p->info);
        inorder(p->right,st);
    }

}


template <class T>
int BinaryTree<T>::nodeCount() {
    return nodeCount(root);
}

template <class T>
int BinaryTree<T>::nodeCount(Bnode<T>* p) {
    if(p == nullptr)
        return 0;
    else{
        if(p->left== nullptr&&p->right== nullptr)
            return 1;
        else
            return 1+nodeCount(p->left)+nodeCount(p->right);
    }

}









