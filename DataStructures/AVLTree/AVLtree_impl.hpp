#include "AVLtree.h"

template<typename T>
AVLtree<T>::AVLtree()
{
	avl_root = nullptr;
}

template<typename T>
Node<T>* AVLtree<T>::left_rotate(Node<T>* node)
{
	Node<T>* newNode = node->n_rigth;
	node->n_rigth = newNode->n_left;
	newNode->n_left = node;

	node->n_heigth = std::max(get_heigth(node->n_left), get_heigth(node->n_rigth)) + 1;
	newNode->n_heigth = std::max(get_heigth(newNode->n_left), get_heigth(newNode->n_rigth)) + 1;

	return newNode;
}

template<typename T>
Node<T>* AVLtree<T>::rigth_rotate(Node<T>* node)
{
	Node<T>* newNode = node->n_left;
	node->n_left = newNode->n_rigth;
	newNode->n_rigth = node;

	node->n_heigth = std::max(get_heigth(node->n_left), get_heigth(node->n_rigth)) + 1;
	newNode->n_heigth = std::max(get_heigth(newNode->n_left), get_heigth(newNode->n_rigth)) + 1;

	return newNode;
}

template<typename T>
int AVLtree<T>::get_heigth(Node<T>* node)
{
	if (node == nullptr)
		return 0;
	return node->n_heigth;
}

template<typename T>
int AVLtree<T>::get_balance(Node<T>* node)
{
	if (node == nullptr)
		return 0;
	return (get_heigth(node->n_left) - get_heigth(node->n_rigth));
}

template<typename T>
Node<T>* AVLtree<T>::insert_node(Node<T>* root, T value)
{
	if (root == nullptr)
		return new Node<T>(value);

	if (value < root->n_data)
		root->n_left = insert_node(root->n_left, value);
	else if (value > root->n_data)
		root->n_rigth = insert_node(root->n_rigth, value);
	else
		return root;

	root->n_heigth = std::max(get_heigth(root->n_left), get_heigth(root->n_rigth)) + 1;
	int balance_factor = get_balance(root);

	if (balance_factor > 1 && value < root->n_left->n_data)
		return rigth_rotate(root);

	if (balance_factor < -1 && value > root->n_rigth->n_data)
		return left_rotate(root);

	if (balance_factor > 1 && value > root->n_left->n_data)
	{
		root->n_left = left_rotate(root->n_left);
		return rigth_rotate(root);
	}

	if (balance_factor < -1 && value < root->n_rigth->n_data)
	{
		root->n_rigth = rigth_rotate(root->n_rigth);
		return left_rotate(root);
	}

	return root;
}

template<typename T>
void AVLtree<T>::insert(T value)
{
	avl_root = insert_node(avl_root, value);
}

template<typename T>
Node<T>* AVLtree<T>::delete_node(Node<T>* root, T value)
{
	if (root == nullptr)
		return root;

	if (value < root->n_data)
		root->n_left = delete_node(root->n_left, value);
	else if (value > root->n_data)
		root->n_rigth = delete_node(root->n_rigth, value);
	else
	{
		if (root->n_left == nullptr || root->n_rigth == nullptr)
		{
			Node<T>* temp = root->n_left ? root->n_left : root->n_rigth;

			if (temp == nullptr)
			{
				temp = root;
				root = nullptr;
			}
			else
				*root = *temp;

			delete temp;
		}
		else
		{
			Node<T>* temp = root->n_rigth;
			while (temp->n_left != nullptr)
				temp = temp->n_left;

			root->n_data = temp->n_data;
			root->n_rigth = delete_node(root->n_rigth, temp->n_data);
		}
	}

	if (root == nullptr)
		return root;

	root->n_heigth = std::max(get_heigth(root->n_left), get_heigth(root->n_rigth)) + 1;
	int balance_factor = get_balance(root);

	if (balance_factor > 1 && get_balance(root->n_left) >= 0)
		return rigth_rotate(root);

	if (balance_factor > 1 && get_balance(root->n_left) < 0)
	{
		root->n_left = left_rotate(root->n_left);
		return rigth_rotate(root);
	}

	if (balance_factor < -1 && get_balance(root->n_rigth) <= 0)
		return left_rotate(root);

	if (balance_factor < -1 && get_balance(root->n_rigth) > 0)
	{
		root->n_rigth = rigth_rotate(root->n_rigth);
		return left_rotate(root);
	}

	return root;
}


template<typename T>
void AVLtree<T>::del(T value)
{
	avl_root = delete_node(avl_root, value);
}

template<typename T>
void AVLtree<T>::print_tree(Node<T>* root)
{
	if (root == nullptr)
		return;
	std::cout << root->n_data << " ";
	print_tree(root->n_left);
	print_tree(root->n_rigth);
}

template<typename T>
void AVLtree<T>::print()
{
	print_tree(avl_root);
}
