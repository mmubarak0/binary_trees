#include "binary_trees.h"
#include <stdio.h>

/**
  * pow2 - power function.
  * @a: first number.
  * @b: second number.
  * Return: a ^ b
  */
size_t pow2(int a, int b)
{
	int c = 1;

	b = b - 1;
	if (b <= 0)
		return (1);
	while (b--)
		c *= a;
	return (c);
}

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

	l_subtree = binary_tree_height(tree->left);
	r_subtree = binary_tree_height(tree->right);
	return (l_subtree - r_subtree);
}

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

/**
  * binary_tree_is_perfect - checks if a binary tree is perfect.
  * @tree: pointer to the root node of the tree to check.
  * Return: 1 if tree is perfect 0 otherwise.
  */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaves_count;

	if (tree == NULL)
		return (0);

	leaves_count = binary_tree_leaves(tree) == pow2(2, binary_tree_height(tree));
	return (binary_tree_balance(tree) == 0 && leaves_count);
}
