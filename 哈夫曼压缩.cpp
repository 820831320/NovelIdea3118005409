#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct AFNode AlphaFreq;
struct AFNode
{
	unsigned char alpha;
	int freq;
};
AlphaFreq *GetAlphaFreq(char *fileName, int *alphaVariety)//Í³¼Æ×Ö·ûÆµÂÊ
{
	int freq[256];
	int i = 0, j = 0, ch;
	FILE *fpin;
	fpin = fopen(fileName, "r");
	ch = fgetc(fpin);
	while (!feof(fpin))
	{
		freq[ch]++;
		ch = fgetc(fpin);
	}
	fclose(fpin);
	while (i < 256)
	{
		if (freq[i])
		{
			(*alphaVariety)++;
		}
	}
	AlphaFreq *alphaFreq = new AFNode[*alphaVariety];
	for (i = 0, j = 0; i < 256; i++)
	{
		if (freq[i])
		{
			alphaFreq[j].alpha = i;
			alphaFreq[j].freq = freq[i];
			j++;
		}
	}
	return alphaFreq;
} 
typedef struct HTNode Node;
struct HTNode
{
	AFNode alphaFreq;
	int weight = alphaFreq.freq;
	Node * Left;
	Node * Right;
};
typedef struct HNode *Heap;
struct HNode
{
	int Size;
	Node Data[256];
};
Node *CreateNode(int w)
{
	Node * node = new HTNode;
	node->weight = w;
	node->Left = NULL;
	node->Right = NULL;
	return node;
}
void Insert(Heap MinHeap, Node *node)
{
	int i;
	i = ++MinHeap->Size;
	for (; MinHeap->Data[i / 2].alphaFreq.freq> node->alphaFreq.freq; i /= 2)
	{
		MinHeap->Data[i] = MinHeap->Data[i / 2];
	}
	MinHeap->Data[i] = *node;
}
Heap *BuildHeap(AlphaFreq alphaFreq[], int *alphaVariety)
{
	int i;
	Heap MinHeap = new HNode;
	MinHeap->Size = 0;
	MinHeap->Data[0] = *CreateNode(0)
	for(i = 0;i < *alphaVariety; i++)
	{
		Node * node = CreateNode(alphaFreq[i].freq);
		Insert(MinHeap, node);
	}
	return MinHeap;
}
Node * DeleteMin(Heap minHeap)
{
	int sizes = minHeap->Size;
	int i;
	Node *newNode;
	for(i = 0;i<sizes-1;i++)
	{
		newNode = CreateNode(0);
		newNode->Left = DeleteMin(minHeap);
		newNode->Right = DeleteMin(minHeap);
		newNode->weight = 



	

