#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool neighborContainsSymbol(const vector<vector<char>>&, int, int);
bool isSafeToCheckNeighbor(int, int, const vector<vector<char>>&);
bool isSymbol(char);
string findSymbol(const vector<vector<char>>&, int, int);

int main() {
  vector<vector<char>> matrix;
  string line;
  string possiblePartNumber;
  unordered_map<string, vector<string>> map;

  while (getline(cin, line)) {
    matrix.push_back(vector<char>(line.begin(), line.end()));
  }

  int sum = 0;
  bool symbolFound = false;
  string symbolCat = "";

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (isdigit(matrix[i][j])) {
        possiblePartNumber += matrix[i][j];
        if (neighborContainsSymbol(matrix, i, j)) {
          symbolCat = findSymbol(matrix, i, j);
          symbolFound = true;
        } else {
          // cout << "Neighbor does not contain symbol " << matrix[i][j] << endl; 
        }
      } else {
        if(matrix[i][j] == '.' || isSymbol(matrix[i][j])) {
          if (possiblePartNumber != "" && symbolFound && symbolCat != "") {
            map[symbolCat].push_back(possiblePartNumber);
          }
          symbolFound = false;
          possiblePartNumber = "";
          symbolCat = "";
        }
        symbolCat = "";
      }
    }
  }

  for (auto it = map.begin(); it != map.end(); it++) {
    int valueCount = 0;
    int potentialMultiplier = 1;
    cout << "Key: " << it->first << endl;
    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      valueCount++;
      potentialMultiplier *= stoi(*it2);
      cout << "Value: " << *it2 << endl;
    }
    cout << endl;
    if(valueCount == 2) {
      cout << "Potential Multiplier: " << potentialMultiplier << endl;
      sum += potentialMultiplier;
    }
  }

  cout << "Sum: " << sum << endl;
  return 0;
}

string findSymbol(const vector<vector<char>>& grid, int i, int j) {
  int rows[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int cols[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  string symbol = "";
  
  for (int k = 0; k < 8; k++) {
    int newRow = i + rows[k];
    int newCol = j + cols[k];
    if (isSafeToCheckNeighbor(newRow, newCol, grid) && isSymbol(grid[newRow][newCol])) {
      cout << "Symbol found at " << newRow << "," << newCol << endl;
      symbol = to_string(newRow) + "," + to_string(newCol);
    }
  }
  return symbol;
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
  if (c == '*') {
    return true;
  } else {
    //cout << c << " is not a symbol!!" << endl;
  }
  return false;
}
