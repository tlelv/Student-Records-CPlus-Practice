#include <iostream>
using namespace std;

typedef struct Record {
    struct Record *next;
    int userID;
    string userName;
    char userAverage;
    string userMajor;
    int userTitle;
    string userDepartment;
} Record;
Record *head = nullptr;

class Person {
public:
    string userName;
    int userID;

    Record * addPerson() {
        auto student = static_cast<Record *>(malloc(sizeof(Record)));

        cout << ("Enter name: ");
        cin >> userName;
        cout << ("Enter ID: ");
        cin >> userID;
        student->userID = userID;
        student->userName = userName;
        if (findRecord(*student) == 1) {
            student = nullptr;
        }
        return student;
    }

    void printAbout() {
        printf("\nNo records found\n");
        printf("\n");
    }

private:
    int findRecord(Record node) {
        Record *student = head;
        int checkStatus = 0;

        while (student != nullptr) {
            if (node.userID == student->userID) {
                checkStatus = 1;
            }
            student = student->next;
        }
        return checkStatus;
    }
};

class Student : Person {
public:
    char userAverage;
    string userMajor;

    void addStudentRecord() {
        Record *student = addPerson();

        if (student == nullptr) {
            printf("Record already exists\n");
            printf("\n");
        }
        else {
            cout << ("Enter average: ");
            cin >> userAverage;
            cout << ("Enter major: ");
            cin >> userMajor;

            student->userAverage = userAverage;
            student->userMajor = userMajor;
            student->next = head;
            head = student;
        }
    }
    void printAbout(char major, Record Student) {
            cout << Student.userAverage << ", ";
            cout << Student.userMajor << endl;
    }
};

class Teacher : Person {
public:
    int userTitle;
    string userDepartment;

    void addTeacherRecord() {
        Record *teacher = addPerson();

        if (teacher == nullptr) {
            printf("Record already exists\n");
            printf("\n");
        }
        else {
            cout << ("Enter title: (1 if lecturer ; 2 if assistant professor ; 3 if associate professor.)");
            cin >> userTitle;
            while (userTitle < 1 || userTitle > 3) {
                cout << ("That is not a valid choice\n Enter your Title: \n");
                cin >> userTitle;
            }
            cout << ("Enter department: ");
            cin >> userDepartment;

            teacher->userTitle = userTitle;
            teacher->userDepartment = userDepartment;
            teacher->next = head;
            head = teacher;
        }
    }

    void printAbout(int title, Record Teacher) {

        if (Teacher.userTitle == 1) {
            cout << "Lecturer, ";
        }
        else if (Teacher.userTitle == 2) {
            cout << "Assistant Professor, ";
        }
        else {
            cout << "Associate Professor, ";
        }
        cout << Teacher.userDepartment << endl;
    }
};

int displayMenu() {
    int myNum;
    cout << ("        Welcome to RU Record Management\n\n");
    cout << ("    Press\n");
    cout << ("    1 to create a new Student Record\n");
    cout << ("    2 to create a new Teacher Record\n");
    cout << ("    3 to view all records\n");
    cout << ("    4 to exit\n\n");

    cout << ("Enter your Choice (ONLY DIGITS): \n");
    cin >> myNum;
    while (myNum < 1 || myNum > 4) {
        printf("That is not a valid choice\n Enter your Choice: \n");
        cin >> myNum;
    }
    return myNum;
}

int main() {
    int myNum;
    Student myStudent;
    Teacher myTeacher;
    Person myPerson;

    myNum = displayMenu();
    while (myNum != 4) {
        if (myNum == 3) {
            Record *person = head;
            char letter = 'A';
            int number = 0;

            printf("\n");
            if (person == nullptr) {
                myPerson.printAbout();
            }
            while (person != nullptr) {
                cout << person->userName << ", ";
                cout << person->userID << ", ";
                if (person->userTitle == 0) {
                    myStudent.printAbout(letter, *person);
                }
                else {
                    myTeacher.printAbout(number, *person);
                }
                person = person->next;
            }
            printf("\n");
            myNum = displayMenu();
        }
        else if (myNum == 1){
            myStudent.addStudentRecord();
            myNum = displayMenu();
        }
        else {
            myTeacher.addTeacherRecord();
            myNum = displayMenu();
        }
    }
    free(head);
    return 0;
}