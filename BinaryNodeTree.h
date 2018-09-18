//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
// This file is a subset of Carrano's file for Lab 8

/** ADT binary tree: Link-based implementation.
 Listing 16-3.
 @file BinaryNodeTree.h */
 /*
 @File Executive.h
 @Author Kyle Lindteigen
 @Assignment: EECS-268 Lab 8
 @brief Header file for the BinaryNodeTree class that holds all of the member methods and values
 @Date November 14, 2017
 */

#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"

template<typename T>
class BinaryNodeTree : public BinaryTreeInterface<T>
{
        private:
                BinaryNode<T>* m_root;

        protected:
                //------------------------------------------------------------
                // Protected Utility Methods Section:
                // Recursive helper methods for the public methods.
                //------------------------------------------------------------

                // Recursively deletes all nodes from the tree.
                void destroyTree(BinaryNode<T>* subTreePtr);

                // Copies the tree rooted at treePtr and returns a pointer to
                // the copy.
                BinaryNode<T>* copyTree(const BinaryNode<T>* treePtr) const;

                // Recursive traversal helper methods:

		/* recursively goes through the tree
		@pre  None.
		@post  visits before recursively calling the next pointer in the tree
                @param visit the function that you want to do at each node in the tree
                @param treePtr the pointer that you want to get the preorder of
		*/
                void preorder(void visit(T&), BinaryNode<T>* treePtr) const;

		/* recursively goes through the tree
		@pre  None.
		@post  calls visit after recursively calling the left child and before the right child
                @param visit the function that you want to do at each node in the tree
                @param treePtr the pointer that you want to get the inorder of
		*/

                void inorder(void visit(T&), BinaryNode<T>* treePtr) const;

		/* recursively goes through the tree
		@pre  None.
		@post  calls visit after recursively calling the left and right child and returns when node==nullptr
                @param visit the function that you want to do at each node in the tree
                @param treePtr the pointer that you want to get the postorder of
		*/

                void postorder(void visit(T&), BinaryNode<T>* treePtr) const;

        public:
                //------------------------------------------------------------
                // Constructor and Destructor Section.
                //------------------------------------------------------------
                BinaryNodeTree(const T& rootItem);
                BinaryNodeTree(const T& rootItem, const BinaryNodeTree<T>* leftTreePtr, const BinaryNodeTree<T>* rightTreePtr);
                BinaryNodeTree(const BinaryNodeTree<T>& tree);
                ~BinaryNodeTree();

                //------------------------------------------------------------
                // Public BinaryTreeInterface Methods Section.
                //------------------------------------------------------------

		/* checks if the tree is empty
		@pre  None.
		@post returns true if the root is pointing to nullptr
                @return returns if there are values in the tree or not
		*/
                bool isEmpty() const;

		/* Returns the value of the root
		@pre  None.
		@post  returns the value of the root
                @throw throws an error if the tree is empty
		*/

                T getRootData() const throw(PrecondViolatedExcep);

                //------------------------------------------------------------
                // Public Traversals Section.
                //------------------------------------------------------------
                void preorderTraverse(void visit(T&)) const;
                void inorderTraverse(void visit(T&)) const;
                void postorderTraverse(void visit(T&)) const;

                //------------------------------------------------------------
                // Overloaded Operator Section.
                //------------------------------------------------------------
                BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
}; // end BinaryNodeTree
#include "BinaryNodeTree.cpp"
#endif
