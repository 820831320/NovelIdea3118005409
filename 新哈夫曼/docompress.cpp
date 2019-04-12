#include "Huffman.h"
void Huffman::doCompress()
{
	int length, i,j;
	char inChar;
	unsigned char outC, temC;
	string code, outString;
	map<int, string>::iterator tableIt;
	outFile << size << endl;
	for (tableIt = table.begin(); tableIt != table.end(); ++tableIt)
	{
		outFile << tableIt->first << " " << tableIt->second << endl;
	}
	inFile.clear();
	inFile.seekg(ios::beg);
	code.clear();
	while (!inFile.eof())
	{
		inFile.get(inChar);
		if (inFile.eof())
		{
			break;
		}
		tableIt = table.find((unsigned char)inChar);
		if (tableIt != table.end())
		{
			code = code + tableIt->second;
		}
		length = code.length();
		if(length >WRITEBUFFSIZE)
		{

			for (i = 0; i + 7 < length; i += 8)
			{
				outC = 0;
				for (j = 0; j < 8; j++)
				{
					if ('0' == code[i + j])
					{
						temC = 0;
					}
					else
					{
						temC = 1;
					}
					outC += temC << (7 - j);
				}
				outString += outC;
			}
			outFile << outString;
			code = code.substr(i, length - i);
		}
	}	
	tableIt = table.find(PSEUDOEOF);
	if (tableIt != table.end())
	{
		code += tableIt->second;
	}
	length = code.length();
	outC = 0;
	for (i = 0; i < length; i++)
	{
		if ('0' == code[i])
		{
			temC = 0;
		}
		else
		{
			temC = 1;
		}
		outC += temC << (7 - (i % 8));
		if (0 == (i + 1) % 8 || i == length - 1)
		{
			outFile << outC;
			outC = 0;
		}
	}
}
