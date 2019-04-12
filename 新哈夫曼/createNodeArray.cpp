#include "Huffman.h"
void Huffman::createNodeArray()
{
	int i, count;
	int freq[MAXSIZE] = { 0 };
	char inChar;
	while (!inFile.eof())
	{
		inFile.get(inChar);
		if (inFile.eof())
		{
			break;
		}
		freq[(unsigned char)inChar]++;
	}
	count = 0;
	for (i = 0; i <= MAXSIZE; ++i)
	{
		if (freq[i] <= 0)
		{
			continue;
		}
		NodePtr node = new HuffmanNode();
		node->id = i;
		node->freq = freq[i];
		node->code = "";
		node->left = NULL;
		node->right = NULL;
		node->parent = NULL;
		nodeArray[count++] = node;
	}
	NodePtr node = new HuffmanNode();
	node->id = PSEUDOEOF;
	node->freq = 1;
	node->code = "";
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	nodeArray[count++] = node;
	size = count;
}