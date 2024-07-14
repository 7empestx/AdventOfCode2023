#include <iostream>
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
    gameNumber.pop_back();                  // Remove colon

    string set;
    vector<int> redCubes;
    vector<int> greenCubes;
    vector<int> blueCubes;
    int power;

    while (getline(gameStream, set, ';')) {
      stringstream setStream(set);
      string cube; // The cube in the set i.e. 6 red
      string color;
      int count;

      while (getline(setStream, cube, ',')) {
        stringstream cubeStream(cube);
        cubeStream >> count >> color;
        if (color == "red") {
          redCubes.push_back(count);
        } else if (color == "green") {
          greenCubes.push_back(count);
        } else if (color == "blue") {
          blueCubes.push_back(count);
        } else {
          cout << "Invalid color: " << color << endl;
          return 1;
        }
      }
    }

    sort(redCubes.begin(), redCubes.end());
    sort(greenCubes.begin(), greenCubes.end());
    sort(blueCubes.begin(), blueCubes.end());
    power = redCubes[redCubes.size() - 1] * greenCubes[greenCubes.size() - 1] * blueCubes[blueCubes.size() - 1];
    sum += power;
  }
  cout << sum << endl;
  return 0;
}
