#include "Huffman.h"
void Huffman::createMapTable(const NodePtr node, bool left)
{
	if (left)
	{
		node->code = node->parent->code + "0";

	}
	else
	{
		node->code = node->parent->code + "1";
	}
	if (node->left == NULL && node->right == NULL)
	{
		table[node->id] = node->code;
	}
	else
	{
		if (node->left != NULL)
		{
			createMapTable(node->left, true);
		}
		if (node->right != NULL)
		{
			createMapTable(node->right, false);
		}
	}
}