#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void saveToFile(const string& name, const vector<string>& input) {
    ofstream file(name);
    for (const auto& word : input) file << word << endl;
    file.close();
}

void loadFromFile(const string& name, vector<string>& output) {
    ifstream file(name);
    string curline;
    while (getline(file, curline)) output.push_back(curline);
    file.close();
}
