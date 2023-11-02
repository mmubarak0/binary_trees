#include "binary_trees.h"

/**
  * tree_height - measures the height of a binary tree.
  * @tree: pointer to the root node of the tree to measure the height.
  * Return: tree height.
  */
size_t tree_height(const binary_tree_t *tree)
{
	size_t len1 = 0, len2 = 0;

	if (tree == NULL)
		return (0);

	len1 = tree_height(tree->left);
	len2 = tree_height(tree->right);

	if (len1 >= len2)
		return (len1 + 1);
	else
		return (len2 + 1);
}

/**
  * binary_tree_height - measures the height of a binary tree.
  * @tree: pointer to the root node of the tree to measure the height.
  * Return: tree height.
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (tree_height(tree) - 1);
}
