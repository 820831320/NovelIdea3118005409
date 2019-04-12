#include "Huffman.h"
void Huffman::createHuffmanTree()
{
	root = NULL;
	while (!pq.empty())
	{
		NodePtr first = pq.top();
		pq.pop();
		if (pq.empty())
		{
			root = first;
			break;
		}
		NodePtr second = pq.top();
		pq.pop();
		NodePtr newNode = new HuffmanNode();
		newNode->freq = first->freq + second->freq;
		if (first->freq <= second->freq)
		{
			newNode->left = first;
			newNode->right = second;
		}
		else
		{
			newNode->left = second;
			newNode->right = first;
		}
		first->parent = newNode;
		second->parent = newNode;
		pq.push(newNode);
	}
	cout << "ok2" << endl;
}

	
