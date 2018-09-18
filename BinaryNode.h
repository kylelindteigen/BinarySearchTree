//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file BinaryNode.h */
 /*
 @File BinaryNode.h
 @Author Kyle Lindteigen
 @Assignment: EECS-268 Lab 8
 @brief Header file for the BinaryNode class that stores all of the member variables and values
 @Date November 14, 2017
 */

#ifndef _BINARY_NODE
#define _BINARY_NODE

template<class T>
class BinaryNode
{

        public:

                /* constructor that just sets the item equal to m_item
                @pre  None
                @post  initializes all of the variables
                @param anItem a value to set equal to m_item
                */

                BinaryNode(const T& anItem);

                /* constructor that just initializes the variables
                @pre  None
                @post  initializes all of the variables
                @param anItem a value to set equal to m_item
                @param leftPtr a pointer that you set the left child equal to
                @param rightPtr a pointer that you set the right child equal to
                */

                BinaryNode(const T& anItem, BinaryNode<T>* leftPtr, BinaryNode<T>* rightPtr);

                /* sets an Item
                @pre  None
                @post  sets the item equal to anItem
                @param anItem an item that you want the value at this node to be
                */

                void setItem(const T& anItem);

		/* returns an Item
		@pre  None.
                @return returns the value at this node
		*/

                T getItem() const;

                /* checks if it is a leaf
                @pre  None.
                @post  if the child pointers are not pointing to anything then returns true
                */

                bool isLeaf() const;

		/* returns the left child
		@pre  None.
		@return returns the left child
		*/

                BinaryNode<T>* getLeftChildPtr() const;

		/* returns the right chils
	        @pre  None.
		@return returns the right child
		*/

                BinaryNode<T>* getRightChildPtr() const;

		/* sets the left child
		@pre  None.
		@post  sets the left child ptr to the given ptr
                @param leftPtr pointer to set on this Node
		*/

                void setLeftChildPtr(BinaryNode<T>* leftPtr);

		/* sets the right child
		@pre  None.
		@post  sets right child ptr to the given ptr
                @param rightPtr pointer that you want to set on this Node
		*/

                void setRightChildPtr(BinaryNode<T>* rightPtr);
        private:
                T m_item;           // Data portion
                BinaryNode<T>* m_leftChildPtr;   // Pointer to left child
                BinaryNode<T>* m_rightChildPtr;  // Pointer to right child
}; // end BinaryNode

#include "BinaryNode.hpp"

#endif
