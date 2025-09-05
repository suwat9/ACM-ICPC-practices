#include <iostream>
#include <string>
using namespace std;

// Define a struct template
struct Student {
    string name;
} stu1;

int main() {
    Student stu2;
    stu1.name = "Alice";
    cout << "Student Name: " << stu1.name << endl;
    return 0;
}
