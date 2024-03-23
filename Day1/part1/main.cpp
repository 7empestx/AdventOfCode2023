#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    char digits[] = "0123456789";
    int sum = 0;

    while (getline(cin, line)) {
        size_t firstDigitPos = line.find_first_of(digits);
        size_t lastDigitPos = line.find_last_of(digits);

        // Check if both first and last digits are found
        if (firstDigitPos != string::npos && lastDigitPos != string::npos) {
            string temp;
            temp.push_back(line[firstDigitPos]); // Add first digit
            // Add last digit only if it's different from the first
            if (lastDigitPos != firstDigitPos) {
                temp.push_back(line[lastDigitPos]);
            }
            sum += stoi(temp);
        }
    }
    cout << sum << endl;
}
