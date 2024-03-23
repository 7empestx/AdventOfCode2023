#include <cctype>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

int main() {
    string line;
    vector<string> wordNumbers =
    {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
     "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    int sum = 0;

    while (getline(cin, line)) {
      vector<string> memo(200);
      vector<string> final;
      cout << "line read: " << line << endl;

      for(int i = 0; i < wordNumbers.size(); i++) {
        size_t pos = line.find(wordNumbers[i]);
        while(pos != string::npos) {
          memo[pos] = wordNumbers[i];
          pos = line.find(wordNumbers[i], pos + 1);
        }
      }

      for(int i = 0; i < memo.size(); i++) {
        if(memo[i] != "") {
          final.push_back(memo[i]);
        }
      }

      string firstDigit = final[0];
      string secondDigit = final[final.size() - 1];

      if(!isdigit(firstDigit[0])) {
        for(int i = 0; i < wordNumbers.size(); i++) {
          if(wordNumbers[i] == firstDigit) {
            firstDigit = to_string(i);
            break;
          }
        }
      }
      if(!isdigit(secondDigit[0])) {
        for(int i = 0; i < wordNumbers.size(); i++) {
          if(wordNumbers[i] == secondDigit) {
            secondDigit = to_string(i);
            break;
          }
        }
      }

      cout << firstDigit << ' ' << secondDigit << endl;
      sum += stoi(firstDigit + secondDigit);
      cout << "end" << endl;
      cout << endl;
    }
    cout << sum << endl;
}

