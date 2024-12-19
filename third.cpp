#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    string Name;
    int Year;
    map<string, Score> RecordBook;
};

using Groups = map<string, vector<Student>>;

void saveToFile(const string& name, const Groups& groups) {
    ofstream file(name);
    for (const auto& gr : groups) {
        const string& groupName = gr.first;
        const vector<Student>& students = gr.second;
        file << groupName << endl; 
        file << students.size() << endl;
        for (const Student& student : students) {
            file << student.Name << endl;
            file << student.Year << endl;
            file << student.RecordBook.size() << endl;
            for (const auto& rec : student.RecordBook) {
                file << rec.first << ' ' << (rec.second) << endl;
            }
        }
    }
    outFile.close();
}
void loadFromFile(const string& name, Groups& outGroups)
{
    ifstream file (name);
    string groupName;
    while (getline(file, groupName)) {
        
        size_t numStudents;
        file >> numStudents;
        file.ignore(); 

        vector<Student> students;
        students.reserve(numStudents);

        for (size_t i = 0; i < numStudents; ++i) {
            Student student;
            getline(inFile, student.Name);
            file >> student.Year;
            file.ignore(); 
            size_t numRec;
            file >> numRec;
            file.ignore(); 
            for (size_t j = 0; j < numRec; ++j) {
                string subject;
                int scoreInt;
                getline(inFile, subject);
                file >> scoreInt;
                file.ignore(); 
                student.RecordBook[subject] = static_cast<Score>(scoreInt);
            }
            students.push_back(student);
        }
        outGroups[groupName] = students;
    }
    file.close();
}
