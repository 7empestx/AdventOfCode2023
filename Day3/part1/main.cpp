#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool neighborContainsSymbol(const vector<vector<char>>&, int, int);
bool isSafeToCheckNeighbor(int, int, const vector<vector<char>>&);
bool isSymbol(char);

int main() {
  vector<vector<char>> matrix;
  string line;
  string possiblePartNumber;

  while (getline(cin, line)) {
    matrix.push_back(vector<char>(line.begin(), line.end()));
  }

  int potentialSum = 0;
  int sum = 0;
  bool symbolFound = false;

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (isdigit(matrix[i][j])) {
        possiblePartNumber += matrix[i][j];
        if (neighborContainsSymbol(matrix, i, j)) {
          symbolFound = true;
          sum += potentialSum;
          potentialSum = 0;
        } 
      } else {
        // matrix[i][j]  is not a digit, must be symbol or .
        if(matrix[i][j] == '.' || isSymbol(matrix[i][j])) {
          if (possiblePartNumber != "" && symbolFound) {
            cout << "Adding " << possiblePartNumber << " to sum" << endl;
            sum += stoi(possiblePartNumber);
          }
          // matrix[i][j] is a .
          potentialSum = 0;
          symbolFound = false;
          possiblePartNumber = "";
        }
      }
    }
  }
  cout << "Sum: " << sum << endl;
  return 0;
}

bool neighborContainsSymbol(const vector<vector<char>>& grid, int i, int j) {
    int rows[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int cols[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    for (int k = 0; k < 8; k++) {
        int newRow = i + rows[k];
        int newCol = j + cols[k];
        if (isSafeToCheckNeighbor(newRow, newCol, grid) && isSymbol(grid[newRow][newCol])) {
            return true;
        }
    }
    return false;
}

bool isSafeToCheckNeighbor(int i, int j, const vector<vector<char>>& grid) {
    return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size();
}

bool isSymbol(char c) {
  if (!isdigit(c) && c != '.') {
    return true;
  } else {
    //cout << c << " is not a symbol!!" << endl;
  }
  return false;
}
