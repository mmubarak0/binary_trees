#include "binary_trees.h"

/**
  * binary_tree_leaves - counts the leaves in a binary tree.
  * @tree: pointer to the root node of the tree to count the number of leaves.
  * Return: leaves count.
  */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);
	count += binary_tree_leaves(tree->left);
	count += binary_tree_leaves(tree->right);
	if (tree->left == NULL && tree->right == NULL)
		count++;
	return (count);
}
