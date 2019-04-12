#include "Huffman.h"
void Huffman::decodeHuffman()
{
	bool pseudoEof;
	int i,id;
	char inChar;
	string outString;
	unsigned char uChar,flag;
	NodePtr node;
	outString.clear();
	node = root;
	pseudoEof = false;
	inFile.get(inChar);
	while (!inFile.eof())
	{
		inFile.get(inChar);
		uChar = (unsigned char)inChar;
		flag = 0x80;
		for (i = 0; i < 8; ++i)
		{

			if (uChar & flag)
			{
				node = node->right;
			}
			else
			{
				node = node->left;
			}
			if (node->left == NULL && node->right == NULL)
			{
				id = node->id;
				if (id == PSEUDOEOF)
				{
					pseudoEof = true;
					break;
				}
				else
				{
					// int to char是安全的，高位会被截断
					outString += (char)node->id;
					node = root;
				}
			}
			flag = flag >> 1;
		}
		if (pseudoEof)
			break;


		if (WRITEBUFFSIZE < outString.length())
		{
			outFile << outString;
			outString.clear();
		}
	}

	if (!outString.empty())
	{
		outFile << outString;
	}
}

