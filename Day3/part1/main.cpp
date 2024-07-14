#include "iostream"
#include "vector"
#include <cctype>
#include <string>

using namespace std;

bool neighborContainsSymbol(vector<vector<char>>, int, int);
bool isSafeToCheckNeighbor(int, int, vector<vector<char>>);
bool isSymbol(char);

int main() {

  string row;
  vector<vector<char>> grid;
  int colSize = 0;
  int sum = 0;

  while (getline(cin, row)) {
    vector<char> rowVector;
    for (int i = 0; i < row.size(); i++) {
      rowVector.push_back(row[i]);
    }
    colSize = row.size();
    grid.push_back(rowVector);
  }

  bool validPartNumber = false;
  string possiblePartNumber;

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < colSize; j++) {
      if (isdigit(grid[i][j])) {
        possiblePartNumber.push_back(grid[i][j]);
        if (neighborContainsSymbol(grid, i, j)) {
          validPartNumber = true;
        }
      } else {
        if (validPartNumber && possiblePartNumber.size() > 0){
          sum += stoi(possiblePartNumber);
          cout << "Sum1 " << sum << endl;
          cout << "Part number: " << possiblePartNumber << endl;
        }
        possiblePartNumber.clear();
        validPartNumber = false;
      }
    }
    if (validPartNumber && possiblePartNumber.size() > 0){
      sum += stoi(possiblePartNumber);
      cout << "Sum2 " << sum << endl;
    }
    possiblePartNumber.clear();
    validPartNumber = false;
  }
  cout << "Sum of all valid part numbers: " << sum << endl;
}

bool neighborContainsSymbol(vector<vector<char>> grid, int i, int j) {
  int rows[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int cols[8] = {-1, 0, 1, 1, 0, -1, 0, 1};
  for (int k = 0; k < 8; k++) {
    if (isSafeToCheckNeighbor(i + rows[k], j + cols[k], grid)) {
      if (isSymbol(grid[i + rows[k]][j + cols[k]])) {
        return true;
      }
    }
  }
  return false;
}

bool isSafeToCheckNeighbor(int i, int j, vector<vector<char>> grid) {
  if (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size()) {
    return true;
  }
  return false;
}

bool isSymbol(char c) {
  if (!isdigit(c) && c != '.') {
    return true;
  }
  return false;
}
