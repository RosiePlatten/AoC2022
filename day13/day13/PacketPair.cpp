#include "PacketPair.h"
#include<iostream>

PacketPair::PacketPair(std::string left, std::string right){ 
	processString(left);
}

bool PacketPair::inOrder() const{ 
	return false;
}

std::vector<std::string> PacketPair::processString(std::string str) const{
	std::vector<std::string> out;

	// first we remove the brackets from the start and end of the string
	str = str.substr(1, str.length() - 2);

	// we then iterate through the string and split into its components
	std::string temp;
	int nestingTracker =0;
    for (const char c : str) {
          if (c == ',' && nestingTracker ==0) {
			  out.push_back(temp);
			  temp = "";
          } else if (c == ']') {
			  nestingTracker --;
            temp.push_back(c);
          } else if (c == '[') {
			  nestingTracker ++;
            temp.push_back(c);
          } else {
            temp.push_back(c);
          }
	}
    out.push_back(temp);

	for (std::string s : out) {
          std::cout << s << " and ";
	}

	std::cout << std::endl;

	return out;
}