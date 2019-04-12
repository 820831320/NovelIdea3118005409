#include "Huffman.h"
Huffman::Huffman(string inFileName, string outFileName)
{
	inFile.open(inFileName.c_str(), ios::in);
	outFile.open(outFileName.c_str(), ios::out);
}
Huffman::~Huffman()
{
	inFile.close();
	outFile.close();
}

void Huffman::compress()
{
	createPq();
	createHuffmanTree();
	calculateHuffmanCodes();
	doCompress();
}

void Huffman::decompress()
{
	rebuildHuffmanTree();
	decodeHuffman();
}