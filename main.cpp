#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//DONE
typedef struct Record {
    struct Record *next;
} Record;

Record *head = nullptr;

int findRecord(Record node) {
    Record *student = head;
    int checkStatus = 0;

    while (student != nullptr) {
        if (this->node.userID == student->userID) {
            checkStatus = 1;
        }
        student = student->next;
    }
    return checkStatus;
}


//FIX
class Person {
public:
    string userName;
    int userID;

    Person(int userID, string userName) {
        this->userID = userID;
        this->userName = userName;
    }
    void addPerson() {
        cout << ("Enter name: ");
        cin >> userName;
        cout << ("Enter ID: )");
        cin >> userID;
    }

    void printAbout() {
        Record *student = head;
        printf("\n");
        if (student == nullptr) {
            printf("\nNo records found\n");
        }
        while (student != nullptr) {
            cout << "%s " << student.userName << endl;
            cout << "%d " << student.userID << endl;
            printf("%c, ", student->userAverage);
            printf("%s.\n", student->userMajor);
            student = student->next;
        }
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

    //FIX
class Student : Person {
public:
    char userAverage;
    string userMajor;

    void addStudentRecord() {
        Record *student = static_cast<Record *>(malloc(sizeof(Record)));

        addPerson();

        cout << ("Enter average: ");
        cin >> userAverage;
        cout << ("Enter major: )");
        cin >> userMajor;

        student->next = head;
        head = student;
    }
         void printAbout() {
            Record *student = head;
            printf("\n");
            if (student == nullptr) {
                printf("\nNo records found\n");
            }
            while (student != nullptr) {
                cout << "%c " << student.userAverage << endl;
                cout << "%s. \n" << student.userMajor << endl;
                student = student->next;
            }
            printf("\n");
        }
    }
};

//FIX
class Teacher : Person {
public:
    int userTitle;
    string userDepartment;

    void addTeacherRecord() {

        Record *teacher = static_cast<Record *>(malloc(sizeof(Record)));

        addPerson();

        cout << ("Enter title: ");
        cin >> userTitle;
        while (userTitle < 1 || userTitle > 3) {
            printf("That is not a valid choice\n Enter your Title: \n");
            scanf("%d", &userTitle);
        }
            cout << ("Enter department: )");
            cin >> userDepartment;

            teacher->next = head;
            head = teacher;
        }
            void printAbout() {
                Record *student = head;
                printf("\n");
                if (student == nullptr) {
                    printf("\nNo records found\n");
                }
                while (student != nullptr) {
                    cout << "%d. \n" << student.userTitle << endl;
                    cout << "%s " << student.userDepartment << endl;
                    student = student->next;
                }
                printf("\n");
            }

                teacher->userTitle = userTitle;

                printf("Enter Department: ");
                scanf(" %s", userDepartment);
                strcpy (teacher->userDepartment, userDepartment);

                printf("\n");
                teacher->next = head;
                head = teacher;
            }
        }
};


//DONE
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

//FIX
int main() {
    int myNum;
    Person individual;


    myNum = displayMenu();
    while (myNum != 4) {
        if (myNum == 1) {

            myNum = displayMenu();
        }
        if (myNum == 2) {
            addTeacherRecord();
            myNum = displayMenu();
        }
        if (myNum == 3) {
            displayRecord();
            myNum = displayMenu();
        }
    }
    free(head);
    return 0;
}
