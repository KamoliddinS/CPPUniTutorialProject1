#include <iostream>
#include <vector>
#include <string>
#include <fstream> // Include the file stream library
using namespace std;

// Structures to hold student data
struct Student
{
    string name;
    int grade;
};

// Function prototypes
void addStudent(vector<Student> &students);
void displayStudents(const vector<Student> &students);
int calculateAverage(const vector<Student> &students);
int findHighestGrade(const vector<Student> &students);
int findLowestGrade(const vector<Student> &students);
void deleteStudent(vector<Student> &students, const string &name);
void updateStudent(vector<Student>& students);
void searchStudents(const vector<Student>& students);
void saveStudentData(const vector<Student> &students);
void loadStudentData(vector<Student> &students);
int main()
{
    vector<Student> students;
    int choice;

    do
    {
        cout << "GradeBook Manager\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Calculate Average Grade\n";
        cout << "4. Display Highest Grade\n";
        cout << "5. Display Lowest Grade\n";
        cout << "6. Delete Student\n";
        cout << "7. Update Student\n";
        cout << "8. Search Students\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        // choice = 1;
        string nameToDelete;
        switch (choice)
        {
        case 1:
            addStudent(students);
            break;
        case 2:
            displayStudents(students);
            break;
        case 3:
            cout << "Average Grade: " << calculateAverage(students) << endl;
            break;
        case 4:
            cout << "Highest Grade: " << findHighestGrade(students) << endl;
            break;
        case 5:
            cout << "Lowest Grade: " << findLowestGrade(students) << endl;
            break;
        case 6:
            cout << "Enter the name of the student to delete: ";
            cin >> nameToDelete;
            deleteStudent(students, nameToDelete);
            break;
        case 7:
            updateStudent(students);
            break;
        case 8:
            searchStudents(students);
            break;
        case 9:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice != 9);

    return 0;
}

void addStudent(vector<Student> &students)
{
    Student newStudent;
    cout << "Enter student's name: ";
    cin >> newStudent.name;
    // newStudent.name = "John";
    cout << "Enter student's grade: ";
    cin >> newStudent.grade;
    // newStudent.grade = 100;
    students.push_back(newStudent);
}

void displayStudents(const vector<Student> &students)
{
    for (const Student &s : students)
    {
        cout << s.name << ": " << s.grade << endl;
    }
}

int calculateAverage(const vector<Student> &students)
{
    int total = 0;
    for (const Student &s : students)
    {
        total += s.grade;
    }
    return students.empty() ? 0 : total / students.size();
}

int findHighestGrade(const vector<Student> &students)
{
    int highest = INT_MIN;
    for (const Student &s : students)
    {
        if (s.grade > highest)
        {
            highest = s.grade;
        }
    }
    return highest;
}

int findLowestGrade(const vector<Student> &students)
{
    int lowest = INT_MAX;
    for (const Student &s : students)
    {
        if (s.grade < lowest)
        {
            lowest = s.grade;
        }
    }
    return lowest;
}
void deleteStudent(vector<Student> &students, const string &name)
{
    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->name == name)
        {
            students.erase(it);
            cout << "Student '" << name << "' has been deleted." << endl;
            return;
        }
    }
    cout << "Student '" << name << "' not found." << endl;
}

void updateStudent(vector<Student>& students) {
    string nameToUpdate;
    cout << "Enter the name of the student to update: ";
    cin >> nameToUpdate;

    for (Student& student : students) {
        if (student.name == nameToUpdate) {
            int updateChoice;
            cout << "What would you like to update?\n";
            cout << "1. Update Name\n";
            cout << "2. Update Grade\n";
            cout << "Enter your choice: ";
            cin >> updateChoice;

            if (updateChoice == 1) {
                cout << "Enter the new name: ";
                cin >> student.name;
                cout << "Name updated successfully." << endl;
            } else if (updateChoice == 2) {
                cout << "Enter the new grade: ";
                cin >> student.grade;
                cout << "Grade updated successfully." << endl;
            } else {
                cout << "Invalid choice." << endl;
            }
            return;
        }
    }
    cout << "Student '" << nameToUpdate << "' not found." << endl;
}

void searchStudents(const vector<Student>& students) {
    int searchChoice;
    cout << "Search Students by:\n";
    cout << "1. Name\n";
    cout << "2. Grade\n";
    cout << "Enter your choice: ";
    cin >> searchChoice;

    if (searchChoice == 1) {
        string nameToSearch;
        cout << "Enter the name of the student: ";
        cin >> nameToSearch;

        bool found = false;
        for (const Student& student : students) {
            if (student.name == nameToSearch) {
                cout << "Student found:\n";
                cout << "Name: " << student.name << "\nGrade: " << student.grade << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student with name '" << nameToSearch << "' not found." << endl;
        }
    } else if (searchChoice == 2) {
        int gradeToSearch;
        cout << "Enter the grade: ";
        cin >> gradeToSearch;

        bool found = false;
        for (const Student& student : students) {
            if (student.grade == gradeToSearch) {
                cout << "Student found:\n";
                cout << "Name: " << student.name << "\nGrade: " << student.grade << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No student with grade " << gradeToSearch << " found." << endl;
        }
    } else {
        cout << "Invalid choice." << endl;
    }
}

// Function to load student data from a file
void loadStudentData(vector<Student> &students) {
    ifstream inputFile("student_data.txt"); // Open the file for reading

    if (!inputFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    Student student;
    while (inputFile >> student.name >> student.grade) {
        students.push_back(student);
    }

    inputFile.close(); // Close the file
}
#include <fstream> // Include the file stream library

// Function to save student data to a file
void saveStudentData(const vector<Student> &students) {
    ofstream outputFile("student_data.txt"); // Open the file for writing

    if (!outputFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (const Student &student : students) {
        outputFile << student.name << " " << student.grade << endl;
    }

    outputFile.close(); // Close the file
}
