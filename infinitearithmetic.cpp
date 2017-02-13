// infinitearithmetic.cpp
#include <stdio.h>
#include <iostream>
#include <cctype>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include "doublelinkedlist.h"
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
	{
		std::cerr << "Usage: infinitearithmetic \"input=xyz.txt;digitsPerNode=<number>\"\n";
	}
	ArgumentManager am(argc, argv);
	std::string filename = am.get("input");
	int digitsPerNode = std::stoi(am.get("digitsPerNode"));
	std::ifstream ifs(filename.c_str());
	std::string line;
	int result;
	while (getline(ifs, line))
	{	
		std::string num1;
		std::string num2;
		int pos;
		size_t symbol;
		if (symbol = line.find("+") != -1)
		{
			num1 = line.substr(0, line.find("+"));
			num2 = line.substr(line.find("+") + 1);
			symbol = 0;
		}
		else if (symbol = line.find("*") != -1)
		{
			num1 = line.substr(0, line.find("*"));
			num2 = line.substr(line.find("*") + 1);
			symbol = 1;
		}
		DoubleLinkedList l1(num1, digitsPerNode);
		DoubleLinkedList l2(num2, digitsPerNode);
		DoubleLinkedList l;
		if (symbol == 0)
		{
			
		}         
		// else if (symbol == 1)
		// {
		// 	l = l1 * l2;
		// }
		l1.Print();
		// l2.Print();
		// cout << "=";
		// l.Print();
		// cout << endl;
	}		
	return 0;
}
// digitsPerNode = 3
// carry = 0
//         123 456 789
//       + 987 654 321
// carry  1  1   1   0
// ----------------------------
//        1 111 111 110 
	   
//         123 456 789
//       * 987 654 321	   
// ----------------------------
//          123 456 789
//        *         321
// carry    146 253   0	  
// ----------------------------
// list1 39 629 629 269
							
// 	        + 123 456 789
//             *     654 000
// carry   298   359   0	  
// ----------------------------
// list2    80 740  583 784 000

	  
// 	  + 123 456 789
//       * 987 000 000
// list3	xxxxxxxxx 000 000  
// ----------------------------
// result = list1 + list2 + list3

//       10 001 000
	  
// 	  cout << node->num
// 	  0
