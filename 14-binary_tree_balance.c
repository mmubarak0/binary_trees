#include "binary_trees.h"

/**
  * binary_tree_height - measures the height of a binary tree.
  * @tree: pointer to the root node of the tree to measure the height.
  * Return: tree height.
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t len1 = 0, len2 = 0;

	if (tree == NULL)
		return (0);

	len1 = binary_tree_height(tree->left);
	len2 = binary_tree_height(tree->right);

	if (len1 >= len2)
		return (len1 + 1);
	else
		return (len2 + 1);
}

/**
  * binary_tree_balance - measures the balance factor of a binary tree.
  * @tree: pointer to the root node of the tree to measure the balance factor.
  * Return: balance factor.
  */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l_subtree = 0, r_subtree = 0;

	if (tree == NULL)
		return (0);

	l_subtree = binary_tree_height(tree->left);
	r_subtree = binary_tree_height(tree->right);
	return (l_subtree - r_subtree);
}
