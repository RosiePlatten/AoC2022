#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include <memory>

typedef std::unique_ptr<std::vector<std::pair<char, char>>> pairsPtr ; 

 pairsPtr readFile() {
  auto pairs = std::make_unique<std::vector<std::pair<char,char>>>();
  const char *strategy = "strategy.txt";
  std::ifstream file;
  file.open(strategy, std::ios::in);


  char a,b;
  while (file >> a >> b) {
    std::pair<char, char> newPair(a,b);
    pairs->push_back(newPair);
  }
  return move(pairs);
}


 int getScore(char elf, char me) {
     int score = 0;

     switch (me) { 
     case 'X':
         score += 1;
         break;
     case 'Y':
         score += 2;
         break;
     case 'Z':
         score +=3;
         break;
     }

     if ((elf == 'A' && me == 'X') || (elf == 'B' && me == 'Y') ||
         (elf == 'C' && me == 'Z')) {
       // Draw
       score += 3;
     }
     else if ((elf == 'A' && me == 'Z') || (elf == 'B' && me == 'X') || (elf == 'C' && me == 'Y')) {
         //elf wins
         score += 0;
     }
     else {
         //I win
         score += 6;
     }
     return score;
 }

 int getScorev2(char elf, char result) {
     int score = 0; 
     switch (result) { 
        case 'X':
            switch (elf) { 
                case 'A':
                    score+=3;
                    break;
                case 'B':
                    score += 1;
                    break;
                case 'C':
                    score += 2;
                    break;
            }
            break;

        case 'Y':
            score+=3;
            switch (elf) { 
                case 'A':
                    score += 1;
                    break;
                case 'B':
                    score += 2;
                    break;
                case 'C':
                    score += 3;
                    break;
            }
            break;

        case 'Z':
          score += 6;
          switch (elf) {
            case 'A':
              score += 2;
              break;
            case 'B':
              score += 3;
              break;
            case 'C':
              score += 1;
              break;
          }
          break;
     }

     return score;

 }

int main() { 
    pairsPtr pairs = readFile();
    int score = 0;
    int scorev2 =0;
    for (std::pair<char, char> i : *pairs) {
      score += getScore(i.first, i.second);
      scorev2 += getScorev2(i.first, i.second);
    }

    std::cout << score << std::endl;
    std::cout << scorev2 << std::endl;
     }
