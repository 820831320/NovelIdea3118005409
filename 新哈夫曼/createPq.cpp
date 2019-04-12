#include "Huffman.h"
void Huffman::createPq()
{
	int i;
	createNodeArray();
	for (i = 0; i < size; i++)
	{
		pq.push(nodeArray[i]);
	}
	cout << "ok1" << endl;
}