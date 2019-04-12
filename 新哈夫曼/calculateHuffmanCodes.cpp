#include "Huffman.h"
void Huffman::calculateHuffmanCodes()
{
	if (root == NULL)
	{
		cout << "Without huffman tree" << endl;
		exit(1);
	}
	if (root->left != NULL)
	{
		createMapTable(root->left, true);
	}
	if (root->right != NULL)
	{
		createMapTable(root->right, false);
	}
}