//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
// This file is a subset of Carrano's file for Lab 8

// PARTIALLY COMPLETE.

/** @file BinaryTree.cpp */
/*
@File BinaryNodeTree.cpp
@Author Kyle Lindteigen
@Assignment: EECS-268 Lab 8
@brief .cpp file for the BinaryNodeTree Class that has basic functions to control the Node
@Date November 14, 2017
*/

#include "BinaryNodeTree.h"
#include "BinaryNode.h"
#include <string>
#include <iostream>

//////////////////////////////////////////////////////////////
//      Protected Utility Methods Section
//////////////////////////////////////////////////////////////

template<typename T>
void BinaryNodeTree<T>::destroyTree(BinaryNode<T>* subTreePtr)
{
        if(subTreePtr==nullptr)
        {
                return;
        }
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());//recursively calls the next pointers and then deletes from the leafs backwards
        delete subTreePtr;
}

template<typename T>
BinaryNode<T>* BinaryNodeTree<T>::copyTree(const BinaryNode<T>* treePtr) const
{
        if(treePtr==nullptr)
        {
                return(nullptr);
        }
                //cout<<treePtr->getItem()<<"\n";
        BinaryNode<T>* hold=new BinaryNode<T>(treePtr->getItem(), copyTree(treePtr->getLeftChildPtr()), copyTree(treePtr->getRightChildPtr()));
        return(hold);//recursively calls the next pointer to set in this BinaryNode and when = to nullptr it returns backwards copying the whole tree
}

template<typename T>
void BinaryNodeTree<T>::preorder(void visit(T&), BinaryNode<T>* treePtr) const
{
        if(treePtr==nullptr)
        {
                return;
        }
        string a=treePtr->getItem();
        visit(a);//visits before recursively calling
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
}

template<typename T>
void BinaryNodeTree<T>::inorder(void visit(T&), BinaryNode<T>* treePtr) const
{
        if(treePtr==nullptr)
        {
                return;
        }
        inorder(visit, treePtr->getLeftChildPtr());
        string a=treePtr->getItem();
        visit(a);//visits in between recursive calls
        inorder(visit, treePtr->getRightChildPtr());
}

template<typename T>
void BinaryNodeTree<T>::postorder(void visit(T&), BinaryNode<T>* treePtr) const
{
        if(treePtr==nullptr)
        {
                return;
        }
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        string a=treePtr->getItem();
        visit(a);//visits after recursively calling
}

template<typename T>
BinaryNodeTree<T>& BinaryNodeTree<T>::operator=(const BinaryNodeTree& rightHandSide)
{
        m_root->setRightChildPtr(copyTree(rightHandSide.m_root));//copys the tree to set equal to the right hand side
}


//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////
template<typename T>
bool BinaryNodeTree<T>::isEmpty() const
{
        if(m_root==nullptr)
        {
                return(1);
        }
        else
        {
                return(0);
        }//returns true if it is empty false if not
}

template<typename T>
T BinaryNodeTree<T>::getRootData() const throw(PrecondViolatedExcep)
{
        if(m_root==nullptr)
        {
                throw(PrecondViolatedExcep("The root is empty"));
        }
        return(m_root->getItem());//returns the value unles the root is empty
}
//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template<typename T>
BinaryNodeTree<T>::BinaryNodeTree(const T& rootItem)
{
        m_root = new BinaryNode<T>(rootItem);
}  // end constructor

template<typename T>
BinaryNodeTree<T>::BinaryNodeTree(const T& rootItem, const BinaryNodeTree<T>* leftTreePtr, const BinaryNodeTree<T>* rightTreePtr)
{
        m_root = new BinaryNode<T>(rootItem, copyTree(leftTreePtr->m_root), copyTree(rightTreePtr->m_root));
}  // end constructor

template<typename T>
BinaryNodeTree<T>::BinaryNodeTree(const BinaryNodeTree<T>& treePtr)
{
        m_root = copyTree(treePtr.m_root);
}  // end copy constructor

template<typename T>
BinaryNodeTree<T>::~BinaryNodeTree()
{
        destroyTree(m_root);
}  // end destructor
//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////
template<typename T>
void BinaryNodeTree<T>::preorderTraverse(void visit(T&)) const
{
        preorder(visit, m_root);
}

template<typename T>
void BinaryNodeTree<T>::postorderTraverse(void visit(T&)) const
{
        postorder(visit, m_root);
}

template<typename T>
void BinaryNodeTree<T>::inorderTraverse(void visit(T&)) const
{
        inorder(visit, m_root);
}  // end inorderTraverse
