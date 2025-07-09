#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Course {
    string name;
    float grade;
    int creditHours;
};
int main() {
    int numCourses;
    vector<Course> courses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    for (int i = 0; i < numCourses; ++i) {
        Course c;
        cout << "Enter name of course " << i + 1 << ": ";
        cin >> ws; 
        getline(cin, c.name);
        cout << "Enter grade (on a 10-point scale) for " << c.name << ": ";
        cin >> c.grade;
        cout << "Enter credit hours for " << c.name << ": ";
        cin >> c.creditHours;
        courses.push_back(c);
    }
    float totalGradePoints = 0;
    int totalCredits = 0;
    for (const auto& course : courses) {
        totalGradePoints += course.grade * course.creditHours;
        totalCredits += course.creditHours;
    }
    float semesterGPA = totalGradePoints / totalCredits;
    cout << "Course Grades:";
    for (const auto& course : courses) {
        cout << course.name << ": Grade = " << course.grade 
             << ", Credit Hours = " << course.creditHours << endl;
    }
    cout << fixed << setprecision(2); 
    cout << "Total Credit Hours: " << totalCredits << endl;
    cout << "Semester GPA (CGPA): " << semesterGPA << endl;
}