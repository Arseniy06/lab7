#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct Book
{
    string Author;
    string Title;
    int Year;
};

void saveToFile(const string& name, const vector<Book>& input) {
    ofstream file(name);
    for (const auto& book : input) file << book.Author << endl << book.Title << endl << book.Year << endl;
    file.close();
}

void loadFromFile(const string& name, vector<Book>& output)
{
    ifstream file(name);
    Book book;
    while (getline(file, book.Author) && getline(file, book.Title) && file >> book.Year)
    {
        file.ignore(); 
        output.push_back(book);
    }
    file.close();
}
