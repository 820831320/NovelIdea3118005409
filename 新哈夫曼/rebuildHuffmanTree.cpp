#include"Huffman.h"
void Huffman::rebuildHuffmanTree()
{
	int i, j, id, length;
	string code;
	NodePtr node, tmp, new_node;
	root = new HuffmanNode();
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
	inFile >> size;
	for (i = 0; i < size; ++i)
	{
		inFile >> id;
		inFile >> code;
		length = code.length();
		node = root;
		for (j = 0; j < length; ++j)
		{
			if ('0' == code[j])
			{
				tmp = node->left;
			}
			else if ('1' == code[j])
			{
				tmp = node->right;
			}
			if (tmp == NULL)
			{
				new_node = new HuffmanNode();
				new_node->left = NULL;
				new_node->right = NULL;
				new_node->parent = node;

				if (j == length - 1)
				{
					new_node->id = id;
					new_node->code = code;
				}

				if ('0' == code[j])
					node->left = new_node;
				else
					node->right = new_node;

				tmp = new_node;
			}
			node = tmp;
		}
	}
}
