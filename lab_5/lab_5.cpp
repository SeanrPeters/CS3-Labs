
#include <map>
#include <utility>
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>

using std::map
using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;


class Student {
public:
        Student(string firstName, string lastName) :
                firstName_(firstName), lastName_(lastName) {}


        Student(Student&& org) :
                firstName_(move(org.firstName_)),
                lastName_(move(org.lastName_))
        {}


        // force generation of default copy constructor
        Student(const Student& org) = default;

        string print() const { return firstName_ + ' ' + lastName_; }

        // needed for unique() and for remove()
        friend bool operator== (Student left, Student right) {
                return left.lastName_ == right.lastName_ &&
                        left.firstName_ == right.firstName_;
        }

        // needed for sort()
        friend bool operator< (Student left, Student right) {
                        (left.lastName_ == right.lastName_ &&
                                left.firstName_ < right.firstName_);
        }

private:
        string firstName_;
        string lastName_;
};




// reading a list from a fileName
void readRoster(map<Student, list<string>>& roster, string fileName);
// printing a list out
void printRoster(const map<Student, list<string>>& roster);

int main(int argc, char* argv[]) {

        if (argc <= 1) {
                cout << "usage: " << argv[0]
                        << " list of courses, dropouts last" << endl; exit(1);
        }

        // vector of courses of students
        map<Student, list<string>> roster;

        for (int i = 1; i < argc - 1; ++i) {

                readRoster(roster, argv[i]);
        }
        printRoster(roster);


        /*
                // reading in dropouts
                list<Student> dropouts;
                readRoster(dropouts, argv[argc - 1]);
                cout << "\n\n dropouts \n"; printRoster(dropouts);
                list<Student> allStudents;  // master list of students
                for (auto& lst : courseStudents)
                        allStudents.splice(allStudents.end(), lst);
                cout << "\n\n all students unsorted \n";
              allStudents.sort(); // sorting master list
                cout << "\n\n all students sorted \n"; printRoster(allStudents);
                allStudents.unique(); // eliminating duplicates
                cout << "\n\n all students, duplicates removed \n"; printRoster(allStudents);
                for (const auto& str : dropouts)  // removing individual dropouts
                        allStudents.remove(str);
                cout << "\n\n all students, dropouts removed \n"; printRoster(allStudents);
                */
}


void readRoster(map<Student, list<string>>& roster, string fileName) {
        ifstream course(fileName);
        string first, last;

        string theClass = fileName;

        theClass.erase(theClass.end() -4, theClass.end());
        while (course >> first >> last)
        {
                auto it = roster.find(Student(first, last));
                if (it == roster.end())
                        roster.insert(std::pair<Student, list<string>>(Student(first, last),$

                else
                        (it->second).push_back(theClass);
        }
        course.close();
}

void printRoster(const map<Student, list<string>>& roster)
 {
        for (const auto& it : roster)
        {
                cout << it.first.print() << ": ";

                for (auto courses : it.second)
                        cout << courses << " ";

                cout << endl;

        }
}

