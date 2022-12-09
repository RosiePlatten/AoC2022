#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

bool readList(std::vector<int>* calories) {
    const char *elvesList = "elvesList.txt";
	std::ifstream file;
    file.open(elvesList, std::ios::in);
        if (!file) {
            std::cout << "Error in opening file!!" <<std::endl;
            return false;
        }
        

    char ch;
    std::string currentNumber = "";
    int currentSum=0;
    bool lastCharNewLine=false;
        while (!file.eof()) {
            file >> std::noskipws >> ch;  
            if (ch == '\n') {
              if (lastCharNewLine) {
                calories->push_back(currentSum);
                currentSum =0;
              } else {
                currentSum = currentSum + std::stoi(currentNumber);
                currentNumber = "";
                lastCharNewLine=true;
              }
            } else {

                lastCharNewLine=false;
                currentNumber.push_back(ch);
            }
        }
    return true;

}

int main() { 
    std::vector<int> calories;
    readList(&calories); 
    int maxCalories =
        *max_element(std::begin(calories), std::end(calories));
    std::cout << "The elf with the most snacks has " << maxCalories << " calories."
              << std::endl;


    std::partial_sort(calories.begin(), calories.begin()+3, calories.end(), std::greater<int>() );
    int topThreeSum = calories[0] + calories[1] + calories[2];
    std::cout << "The top 3 elves have " << topThreeSum << " calories." << std::endl;
}
