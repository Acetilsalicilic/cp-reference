#include <iostream>
using namespace std;
int main() {
    string line;
    // Stores the whole line in "line",
    // without tne newline \n
    getline(cin, line);
    // ignore the newline in the buffer
    cin.ignore();
}
