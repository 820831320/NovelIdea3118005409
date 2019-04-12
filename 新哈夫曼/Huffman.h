#pragma once
#include <string>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
#define MAXSIZE 270
#define WRITEBUFFSIZE 10
#define PSEUDOEOF 256

struct HuffmanNode
{
	int id;
	unsigned int freq;
	string code;
	HuffmanNode *left, *right, *parent;
};
typedef HuffmanNode *NodePtr;
class Huffman
{
private:
	NodePtr nodeArray[MAXSIZE];
	int size;
	NodePtr root;
	fstream inFile, outFile;
	map<int,string>table;
	class Compare
	{
	public:
		bool operator()(const NodePtr &c1, const NodePtr &c2)
		{
			return (*c1).freq > (*c2).freq;
		}
	};
	priority_queue< NodePtr, vector<NodePtr>, Compare > pq;
	void createNodeArray();
	void createPq();
	void createHuffmanTree();
	void createMapTable(const NodePtr node, bool left);
	void calculateHuffmanCodes();
	void doCompress();
	void rebuildHuffmanTree();
	void decodeHuffman();
public:
	Huffman(string inFileName, string outFileName);
	~Huffman();
	void compress();
	void decompress();
};