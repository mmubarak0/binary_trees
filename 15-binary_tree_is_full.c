#include "binary_trees.h"

/**
  * tree_is_full - checks if a binary tree is full.
  * @tree: pointer to the root node of the tree to check.
  * Return: 1 if binary tree is full otherwise 0.
  */
int tree_is_full(const binary_tree_t *tree)
{
	int full = 0;

	if (tree == NULL)
		return (0);

	full = tree_is_full(tree->left);
	full = tree_is_full(tree->right);

	if (tree->left == NULL && tree->right)
		full++;
	if (tree->left && tree->right == NULL)
		full++;
	return (full);
}

/**
  * binary_tree_is_full - checks if a binary tree is full.
  * @tree: pointer to the root node of the tree to check.
  * Return: 1 if binary tree is full otherwise 0.
  */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (!tree_is_full(tree));
}
