/***********************************************************************************************/
/* Programmer: Inna Yedzinovich                                                                */
/* Date: 10/23/2017                                                                            */
/* Purpose: AVL Tree class functions implementation file                                       */
/* Professor: Anna Salvati                                                                     */
/***********************************************************************************************/

#include <iostream>
#include "AVLTree.h"

/*************************FUNCTIONS IMPLEMENTATION********************************************/

template <class T>
void AVLTree<T>::insertItem(T item) {
    insertItem(this->root,item);
}
template <class T>
void AVLTree<T>::insertItem(Bnode<T> *&p, T item) {

    if(p == nullptr){
        p=new Bnode<T>;
        p->info = item;
        p->left = nullptr;
        p->right = nullptr;
        p->count = 1;
    }
    if (p->info==item) {
        p->count++;
        return;
    }

    else if (p->info > item)
        insertItem(p->left,item);
    else
        insertItem(p->right,item);

    toBalance(p);

}

template <class T>
void AVLTree<T>::deleteItem(T item) {

    deleteItem(this->root, item);
}

template <class T>
void AVLTree<T>::deleteItem(Bnode<T> *&p, T item) {

    if(p == nullptr){
        std::cout<<"Item is not found"<<std::endl;
        return;
    }
    else{

        if(p->info==item)
            deleteNode(p);
        else if (p->info > item)
            deleteItem(p->left, item);
        else
            deleteItem(p->right, item);
    }
}

template <class T>
void AVLTree<T>::deleteNode(Bnode<T> *&p) {

    Bnode<T>*q = p;

    if(p->left== nullptr){
        p = p->right;
       delete q;
    }
    else if(p->right == nullptr){
        p = p->left;
        delete q;
    }
    else{
        T item = getValue(p->left);
        p->info = item;
        toBalance(p);
        deleteItem(p->left, item);
    }
}

template <class T>
T AVLTree<T>::getValue(Bnode<T> *p) {

    while(p->right != nullptr)
        p = p->right;
    return p->info;
}

template <class T>
bool AVLTree<T>::searchItem(T item) {

    return searchItem(this->root, item);
}

template <class T>
bool AVLTree<T>::searchItem(Bnode<T> *& p, T item) {

    if(p== nullptr)
        return false;
    else{
        if(p->info==item)
            return true;
        else if(p->info>item)
            return searchItem(p->left, item);
        else
            return searchItem(p->right, item);
    }

}

//Function to return avl tree balance height for avl
template <class T>
int AVLTree<T>::avlheight(Bnode<T> *p) {

    if(p == nullptr)
        return 0;
    else
        return p->balance;
}

//look at balance factor (if not 0 only!!!!!)
template <class T>
int AVLTree<T>::bfactor(Bnode<T> *p) {
    return avlheight(p->right)-avlheight(p->left);
}

//making a correct height if left and right have correct balance
template <class T>
void AVLTree<T>::fixHeight(Bnode<T> *&p) {

    int leftH=avlheight(p->left);
    int rightH=avlheight(p->right);

    if(leftH > rightH)
        p->balance=leftH+1;
    else
        p->balance=rightH+1;
}

//Rotations
template <class T>
void AVLTree<T>::rightRotation(Bnode<T> *&p) {

    Bnode<T> *q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    p = q;
}

template <class T>
void AVLTree<T>::leftRotation(Bnode<T> *&p) {

    Bnode<T>* q = p->right;
    p->right = q->left;
    q->left=p;
    fixHeight(p);
    fixHeight(q);
    p = q;

}

template <class T>
void AVLTree<T>::toBalance(Bnode<T> *&p) {

    fixHeight(p);
    if(bfactor(p)==2){
        if(bfactor(p->right)<0)
            rightRotation(p->right);
        leftRotation(p);
    }
    if(bfactor(p)==-2){
        if(bfactor(p->left)>0)
            leftRotation(p->left);
        rightRotation(p);
    }

}

template <class T>
bool AVLTree<T>::isBalanced(Bnode<T> *p) {

    int result =  getBalance(p);
    if(result>0)
        return true;
    else
        return false;

}
template <class T>
bool AVLTree<T>::isBalanced() {
    return isBalanced(this->root);

}

template <class T>
int AVLTree<T>::getBalance(Bnode<T> *p) {
    if(p== nullptr)
        return 0;
    int leftH = getBalance(p->left);
    if(leftH==-1)
        return -1;

    int rightH = getBalance(p->right);
    if(rightH==-1){
        return -1;
    }
    int difference = leftH-rightH;
    if(difference>1||difference<-1)
        return -1;

    if(leftH>rightH)
        return 1+leftH;
    else
        return 1+rightH;
}

template <class T>
int AVLTree<T>::getCount(T item) {
    return getCount(this->root, item);
}

template <class T>
int AVLTree<T>::getCount(Bnode<T> *p, T item) {

    if(p == nullptr)
        return 0;
    else{
        if(p->info>item)
            return getCount(p->left, item);
        else if (p->info<item)
            return getCount(p->right, item);
        else
            return p->count;


    }

}




