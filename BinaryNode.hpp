/*
@File BinaryNode.hpp
@Author Kyle Lindteigen
@Assignment: EECS-268 Lab 8
@brief cpp file for the BinaryNode class that holds a bunch of basic functions
@Date November 14, 2017
*/
template<typename T>
BinaryNode<T>::BinaryNode(const T& anItem)
{
	m_item=anItem;
	m_leftChildPtr=nullptr;
	m_rightChildPtr=nullptr;
}//initializes all of the values

template<typename T>
BinaryNode<T>::BinaryNode(const T& anItem, BinaryNode<T>* leftPtr, BinaryNode<T>* rightPtr)
{
	m_item=anItem;
	m_leftChildPtr=leftPtr;
	m_rightChildPtr=rightPtr;
}//initializes all of the values

template<typename T>
void BinaryNode<T>::setItem(const T& anItem)
{
	m_item=anItem;
}//sets m_item = to the passed in item

template<typename T>
T BinaryNode<T>::getItem() const
{
	return(m_item);
}//returns the item value

template<typename T>
bool BinaryNode<T>::isLeaf() const
{
	if(m_leftChildPtr==nullptr&&m_rightChildPtr==nullptr)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}//returns true if the child pointers are not pointing to anything and false if they are

template<typename T>
BinaryNode<T>* BinaryNode<T>::getLeftChildPtr() const
{
	return(m_leftChildPtr);
}//returns the left child

template<typename T>
BinaryNode<T>* BinaryNode<T>::getRightChildPtr() const
{
	return(m_rightChildPtr);
}//returns the right child

template<typename T>
void BinaryNode<T>::setLeftChildPtr(BinaryNode<T>* leftPtr)
{
	if(m_leftChildPtr!=nullptr)
	{
		delete m_leftChildPtr;
	}
	m_leftChildPtr=leftPtr;
}//sets the value of the left child

template<typename T>
void BinaryNode<T>::setRightChildPtr(BinaryNode<T>* rightPtr)
{
	if(m_rightChildPtr!=nullptr)
	{
		delete m_rightChildPtr;
	}
	m_rightChildPtr=rightPtr;
}//sets the value of the right child
