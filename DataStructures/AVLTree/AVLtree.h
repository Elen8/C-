#ifndef AVLTREE
#define AVLTREE

#include <iostream>

template <typename T>
class Node
{
public:
	Node<T>* n_left;
	Node<T>* n_rigth;
	int n_heigth;
	T n_data;

	Node(T value)
	{
		n_data = value;
		n_left = nullptr;
		n_rigth = nullptr;
		n_heigth = 1;
	}
};

template <typename T>
class AVLtree
{
public:
	AVLtree();

	void insert(T);
	void del(T);
	void print();

private:
	Node<T>* left_rotate(Node<T>*);
	Node<T>* rigth_rotate(Node<T>*);
	Node<T>* insert_node(Node<T>*, T);
	int get_heigth(Node<T>*);
	int get_balance(Node<T>*);
	Node<T>* delete_node(Node<T>*, T);
	void print_tree(Node<T>*);

	Node<T>* avl_root;

};


#include "AVLtree_impl.hpp"
#endif //AVLTREE
