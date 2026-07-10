#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("sample_log.txt");
    ofstream outputFile("rotated_log.txt");

    if (!inputFile) {
        cout << "Error: sample_log.txt not found!" << endl;
        return 1;
    }

    if (!outputFile) {
        cout << "Error: Cannot create rotated_log.txt!" << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line)) {
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Reading sample_log.txt..." << endl;
    cout << "Writing to rotated_log.txt..." << endl;
    cout << "Log rotation completed successfully!" << endl;

    return 0;
}