#include <iostream>
#include <ostream>
#include <sstream>

using namespace std;

const int RED_CUBES_MAX = 12;
const int GREEN_CUBES_MAX = 13;
const int BLUE_CUBES_MAX = 14;

int main() {
  string game;
  int sum = 0;
  while (getline(cin, game)) {
    stringstream gameStream(game);
    string gameNumber;

    gameStream >> gameNumber >> gameNumber; // Remove Game and get number
    gameNumber.pop_back();          // Remove colon

    string set;
    int setCount = 0;
    vector<bool> gameStatus;

    while (getline(gameStream, set, ';')) {
      stringstream setStream(set);
      string cube; // The cube in the set i.e. 6 red
      string color;
      int count;
      setCount++;
      vector<bool> setStatus;

      while (getline(setStream, cube, ',')) {
        stringstream cubeStream(cube);
        cubeStream >> count >> color;
        if (color == "red" && count > RED_CUBES_MAX) {
          setStatus.push_back(false);
        } else if (color == "green" && count > GREEN_CUBES_MAX) {
          setStatus.push_back(false);
        } else if (color == "blue" && count > BLUE_CUBES_MAX) {
          setStatus.push_back(false);
        } else {
          setStatus.push_back(true);
        }
      }
      for (bool status : setStatus) {
        if (!status) {
          gameStatus.push_back(false);
        } else {
          gameStatus.push_back(true);
        }
      }
    }
    bool gameValid = true;
    for (bool status : gameStatus) {
      if (!status) {
        gameValid = false;
      }
    }
    if (gameValid) {
      cout << "game " << gameNumber << " is valid" << endl;
      sum += stoi(gameNumber);
    } else {
      cout << "game " << gameNumber << " is invalid" << endl;
    }
  }

  cout << sum << endl;
  return 0;
}
