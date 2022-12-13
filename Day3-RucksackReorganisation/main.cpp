#include<vector>
#include<utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include<algorithm>
#include<map>
#include<iterator>

typedef std::pair<std::string, std::string> rucksack;

std::vector<rucksack> readFile() {
	std::vector<rucksack> rucksacks;
	const char *list = "list.txt";
	std::ifstream file;
	file.open(list, std::ios::in);

	std::string line;
    while (std::getline(file, line) ){
		int len = line.length();
		std::string compartment1 = line.substr(0,len/2);
        std::string compartment2 = line.substr(len/2,len/2);
        rucksack newRucksack(compartment1, compartment2);
        rucksacks.push_back(newRucksack);
    }
	return rucksacks;

}

char findOddOneOut(rucksack r) {
  std::string compartment1 = r.first;
  std::string compartment2 = r.second;

  for (int i = 0; i < compartment1.length(); ++i) {
    auto searchPtr = std::find(compartment1.begin(), compartment1.end(), compartment2[i]);
    if (searchPtr != compartment1.end()) {
      return compartment2[i];
    }
  }
  return 0;
}

int calculatePriority(rucksack r, std::map<char,int> mapping) { 
    
	char oddOne = findOddOneOut(r);

    return mapping[oddOne];

}

int calculateBadgeTotal(std::vector<rucksack> rucksack) {
    vector<rucksack>::iterator iter 

}

std::map<char, int> generateMap() {
  std::map<char, int> mapping;
  for (int i = 0; i < 26; i++) {
    mapping.insert({'a' + i, 1+i});
    mapping.insert({'A' + i, 27 + i});
  }
  return mapping;
}

int main() {
    std::map<char, int> mapping = generateMap();
	std::vector<rucksack> rucksacks = readFile();
	int total =0;
        for (rucksack r : rucksacks) {
          total += calculatePriority(r, mapping);
        }
    std::cout << "The answer to part one is " <<  total << std::endl;


}