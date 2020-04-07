#pragma once
#ifndef BSTHPP
#define BSTHPP
#include "BST.h"

template <class T>
TreeNode<T>* BinarySearchTree<T>::_insert(TreeNode<T>* current, T x)
{
    if (current == NULL) return new TreeNode<T> (x);

    int nodeheight = 0;
    
    if (current->_item > x)
    {
        current->_left = _insert(current->_left, x);
        nodeheight = height(current->_left) + 1;
    }
    else if (x > current->_item)
    {
        current->_right = _insert(current->_right, x);
        nodeheight = height(current->_right) + 1;
    }
    else
        return current;
    
    current->_height = nodeheight;
    
    int difference = height(current->_left) - height(current->_right);
    if (difference > 1)
    {
        if (x < current->_left->_item) return _rightRotation(current);
        else if (x > current->_left->_item)
        {
            current->_left = _leftRotation(current->_left);
            return _rightRotation(current);
        }
    }
    else if (difference < -1)
    {
        if (x > current->_right->_item) return _leftRotation(current);
        else if (x < current->_right->_item)
        {
            current->_right = _rightRotation(current->_right);
            return _leftRotation(current);
        }
    }
    return current;
}





template <class T>
void BinarySearchTree<T>::insert(T x) {
    if (!exist(x))
    {
        if (_root == NULL)
            _root = new TreeNode<T>(x);
        else
            _root = _insert(_root, x);
        _size++;
    }
}

//Fourth Task

template <class T>
bool BinarySearchTree<T>::exist(T x) {
 return _exist(_root, x);
}


template <class T>
bool BinarySearchTree<T>::_exist(TreeNode<T>* node, T x) {
 if (!node) return false;
 if (node->_item == x) return true;
 else return _exist(node->_left, x) || _exist(node->_right, x);
}

//Third Task
template <class T>
T BinarySearchTree<T>::searchMax() {
 if (!_root) return T();
 return _searchMax(_root)->_item;
}
template <class T>
TreeNode<T>* BinarySearchTree<T>::_searchMax(TreeNode<T>* node) {
 if (!node->_right) return node;
 return _searchMax(node->_right);
}

template <class T>
T BinarySearchTree<T>::searchMin() {
 if(!_root) return T();
 return _searchMin(_root)->_item;
}
template <class T>
TreeNode<T>* BinarySearchTree<T>::_searchMin(TreeNode<T>* node) {
 if (!node->_left) return node;
 return _searchMin(node->_left);
}

//Fifth task
//SUCCESSOR: minimum of right child
//Follow the search to find the node for x
//If the node has a right child  -> return the max of its right subtree
//Follow the search path from the root, find the last parent that goes left to find x
template <class T>
TreeNode<T>* BinarySearchTree<T>::_successor(TreeNode<T>* node, T x)
{
    if (!node) return NULL;
    TreeNode<T>* current = node->_item > x ? node : NULL;
    TreeNode<T>* next = !current ? _successor(node->_right, x) : _successor(node->_left, x);
    if (!next) return current;
    if (!current) return next;
    return next->_item < current->_item ? next : current;
}

template <class T>
T BinarySearchTree<T>::successor(T x)
{
    TreeNode<T>* node = _successor(_root, x);
    return !node ? T() : node->_item;
}

template <class T>
int BinarySearchTree<T>::height(TreeNode<T>* node)
{
 if (!node) return -1;
 return node->_height;
}

//Sixth Task
//The origional root of the subtree moves left
template <class T>
TreeNode<T>* BinarySearchTree<T>::_leftRotation(TreeNode<T>* v)
{
    TreeNode<T>* w = v->_right;
    TreeNode<T>* parent = w->_left;
    w->_left = v;
    v->_right = parent;
    int left_height = height(v->_left);
    int right_height = height(v->_right);
    v->_height = left_height > right_height ? left_height + 1 : right_height + 1;
    return w;
}

//The origional root of the subtree moves right
template <class T>
TreeNode<T>* BinarySearchTree<T>::_rightRotation(TreeNode<T>* v)
{
    TreeNode<T>* w = v->_left;
    TreeNode<T>* parent = w->_right;
    w->_right = v;
    v->_left = parent;
    int left_height = height(v->_left);
    int right_height = height(v->_right);
    v->_height = left_height > right_height ? left_height + 1 : right_height + 1;
    return w;
}




//First Task
template <class T>
void BinarySearchTree<T>::inOrderPrint() {
    _inOrderPrint(_root);
    cout << endl;
}

template <class T>
void BinarySearchTree<T>::_inOrderPrint(TreeNode<T>* node) {
    if (!node) return;
    _inOrderPrint(node->_left);
    cout << node->_item << " ";
    _inOrderPrint(node->_right);
}

template <class T>
void BinarySearchTree<T>::postOrderPrint() {
    _postOrderPrint(_root);
    cout << endl;
}

template <class T>
void BinarySearchTree<T>::_postOrderPrint(TreeNode<T>* node) {
    if (!node) return;
    _postOrderPrint(node->_left);
    _postOrderPrint(node->_right);
    cout << node->_item << " ";
}


////Height
/*
template <class T>
int BinarySearchTree<T>::height(TreeNode<T>* node){
    int leftHeight = 0;
    int rightHeight = 0;
    if(node->_left != NULL)
        leftHeight = height(node->_left)+1;
    if(node->_right != NULL)
        rightHeight = height(node->_right)+1;
    return (rightHeight > leftHeight) ? rightHeight : leftHeight;
    
}
 */




template <class T>
void BinarySearchTree<T>::_printTree(int indent, TreeNode<T>* node, bool withHeight) {

	if (!node)
		return;

	if (node->_right)
		_printTree(indent + 2, node->_right, withHeight);
	for (int i = 0; i < indent; i++)
		cout << "  ";
	cout << node->_item;
	if (withHeight)
        //node->_height = height(node);
    cout << "(h=" << height(node) << ")";
	cout << endl;
	if (node->_left)
		_printTree(indent + 2, node->_left, withHeight);

};


template <class T>
void BinarySearchTree<T> ::_destroySubTree(TreeNode<T>* node)
{
    if (node->_left)
        _destroySubTree(node->_left);
    if (node->_right)
        _destroySubTree(node->_right);
    delete node;
}

template <class T>
BinarySearchTree<T> :: ~BinarySearchTree()
{
    if (_root)
        _destroySubTree(_root);
}


template <class T>
void BinarySearchTree<T>::printTree(bool withHeight) {
    _printTree(0, _root, withHeight);
}

template <class T>
void BinarySearchTree<T>::preOrderPrint() {
    _preOrderPrint(_root);
    cout << endl;
}


template <class T>
void BinarySearchTree<T>::_preOrderPrint(TreeNode<T>* node) {
    if (!node) return;
    cout << node->_item << " ";
    _preOrderPrint(node->_left);
    _preOrderPrint(node->_right);
}
#endif
