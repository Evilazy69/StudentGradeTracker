#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

struct Students{
	string name;
	int age;
	
	float mathGrade;
	float englishGrade;
	float sportGrade;
	float itGrade;
	float bioGrade;
	float averageGrade;
};

void addStudent(vector<Students> &studentlist);
void getStudentList(vector<Students> &studentlist);
void showBestStudents(vector<Students> &studentlist);
float gradeValidation();
int ageValidation();

int main(){
	cout << fixed << setprecision(1); // Making that all float number output will be truncated to 2 decimals after floating point within int main() scope
	
	vector<Students> studentlist;
	
	char option;
	
	while (option != 'x'){
		cout << "\n~ Options ~\n\n";
		cout << "[a] - Add a student\n";
		cout << "[b] - Show student list\n";
		cout << "[c] - Show best students\n\n";
		
		cout << "[x] - Exit program\n";
		cin >> option;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		switch(option){
			case 'a': addStudent(studentlist); break;
			case 'b': getStudentList(studentlist); break;
			case 'c': showBestStudents(studentlist); break;
		}
	}
}

void addStudent(vector<Students> &studentlist){
	Students student;
	
	cout << "Enter student's name\n";
	getline(cin, student.name);
	
	cout << "Enter " << student.name << "'s age\n";
	student.age = ageValidation();

	
	cout << "Enter " << student.name << "'s grades\n";
	cout << "Math:\n";
	student.mathGrade = gradeValidation();
	
	cout << "English:\n";
	student.englishGrade = gradeValidation();

	cout << "Sport:\n";
	student.sportGrade = gradeValidation();
	
	cout << "IT:\n";
	student.itGrade = gradeValidation();
	
	cout << "Biology:\n";
	student.bioGrade = gradeValidation();
	
	float avgGrade = (student.mathGrade + student.englishGrade + student.sportGrade + student.itGrade + student.bioGrade) / 5;
	student.averageGrade = avgGrade;
	
	studentlist.push_back(student);
}
void getStudentList(vector<Students> &studentlist){
	if (studentlist.empty()){
		cout << "\n=========================\n";
		cout << "~ Student List is empty ~";
		cout << "\n=========================\n\n";
	}
	
	cout << "\n========================\n";
	
	for (unsigned int i = 0; i < studentlist.size(); i++){
		
		string promotionStatus;
		
		if (studentlist.at(i).averageGrade >= 4){
			promotionStatus = "Promoted";
		}
		else{
			promotionStatus = "Unpromoted";
		}
		
		cout << "******* " << studentlist.at(i).name << " *******\n";
		cout << "Age: " << studentlist.at(i).age << "\n\n";
		
		cout << "~~~~~~Grades~~~~~~\n";
		cout << "Math: " << studentlist.at(i).mathGrade << '\n';
		cout << "English: " << studentlist.at(i).englishGrade << '\n';
		cout << "Sport: " << studentlist.at(i).sportGrade << '\n';
		cout << "IT: " << studentlist.at(i).itGrade << '\n';
		cout << "Biology: " << studentlist.at(i).bioGrade << "\n\n";
		
		cout << "Average: " << studentlist.at(i).averageGrade << '\n';
		cout << "Status: " << promotionStatus << "\n\n\n";
	}
	cout << "=========================\n\n";
}
void showBestStudents(vector<Students> &studentlist){
	cout << "~~ Students leaderbord by highest average mark ~~\n\n";
	partial_sort(studentlist.begin(), studentlist.begin() + 3, studentlist.end(), [](const Students&a, const Students&b){
		return a.averageGrade > b.averageGrade;
	});
	
	for (unsigned int i = 0; i < studentlist.size(); i++){
		cout << "Top " << i+1 << " student is " << studentlist.at(i).name << " which has an average mark of " << studentlist.at(i).averageGrade << '\n';
		
		if (i > 1){
			break;
		}
	}
}
float gradeValidation(){
	float grade;
	cin >> grade;
	
	while (grade > 6 || grade < 1.5 || !cin || (int)(grade*2) != grade*2){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Grades can only range from 1.5 to 6.0 (and are a multiple of 0.5)\n";
		cin >> grade;
	}
	return grade;
}
int ageValidation(){
	float age;
	cin >> age;
	
	while (age > 40 || age < 20 || !cin){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Student's age have to be from 20 to 40 years old\n";
		cin >> age;
	}
	return age;
}

