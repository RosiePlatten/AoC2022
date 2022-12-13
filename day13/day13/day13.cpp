#include <iostream>
#include <fstream>
#include <string>
#include "PacketPair.h"
#include <vector>

std::vector<PacketPair> readFile() { 
    std::ifstream file("inputTest.txt");
    std::string line;
    bool firstItem = true;
    std::string prevLine;

    std::vector<PacketPair> pairs;

    while (std::getline(file, line) ){
      if (!firstItem) {
        PacketPair newPair(prevLine, line);
        pairs.push_back(newPair);
        firstItem = true;
      } else if (firstItem && line != "") {
          prevLine = line;
          firstItem = false;
      }
    }
    file.close();
    return pairs;
}


int main()
{ 
    readFile();
}


