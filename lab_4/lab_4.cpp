
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>


using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;

list<string> ReturnCourse(string name, vector<list<string>> theirCourses);

void coursePrint(vector<list<string>> theCourses);

// reading a list from a fileName
void readRoster(list<string>& roster, string fileName);

// printing a list out
void printRoster(const list<string>& roster);


int main(int argc, char* argv[]) {

    if (argc <= 1) {

        cout << "usage: " << argv[0]
            << " list of courses, dropouts last"
            << endl; exit(1);
    }

    // vector of courses of students
    vector <list<string>> courseStudents;

    vector <list<string>> theCourses;

    for (int i = 1; i < argc - 1; ++i) {
        list<string> roster;
        readRoster(roster, argv[i]);
        courseStudents.push_back(move(roster));
    }

    // reading in dropouts
    list<string> dropouts;
    readRoster(dropouts, argv[argc - 1]);


    // master list of students
    list<string> allStudents;

    for (auto& lst : courseStudents)
        allStudents.insert(allStudents.end(), lst.begin(), lst.end());

    //sorting master list
        allStudents.sort();

    // eliminating duplicates
    allStudents.unique();


    // removing individual dropouts
    for (const auto& str : dropouts)
        allStudents.remove(str);


    for (const auto& studentName:allStudents)
    {
        list<string> theList = ReturnCourse(studentName, courseStudents);

        theCourses.push_back(move(theList));
    }

    coursePrint(theCourses);
}

// reading in a file of names into a list of strings
void readRoster(list<string>& roster, string fileName) {
    ifstream course(fileName);
    string first, last;
    while (course >> first >> last)
        roster.push_back(move(first + ' ' + last));
    course.close();

// printing a list out
void printRoster(const list<string>& roster) {
    for (const auto& str : roster)
        cout << str << endl;
}


list<string> ReturnCourse(string studentName, vector <list<string>> courseStudents)
{
    list<string> studentCourseList;
    studentCourseList.push_back(studentName);

    for (vector<int>::size_type i = 0; i < courseStudents.size(); ++i)
    {
        list<string> studentList = courseStudents[i];
        if (studentList.end() != find(studentList.begin(), studentList.end(), studentName))
            studentCourseList.push_back("cs" + std::to_string(i + 1));
    }
    return studentCourseList;
}


// this is to print out all of the students
void coursePrint(vector <list<string>> theCourses)
{
    cout << "All students" << endl;
    cout << "last name, first name: courses enrolled" << endl;

    for (list<string>& studentCourseList : theCourses)
    {
        list<string>::iterator it = studentCourseList.begin();
        it++;
        cout << *it << ": ";

        while (it != studentCourseList.end())
        {
            ++it;
            cout << *it << " ";
        }

        cout << endl;
    }

