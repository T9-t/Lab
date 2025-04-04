#include <iostream>
#include <vector>
#include "Human.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

int main()
{
	vector<int> joshua{ 3,5,5 }, stev{ 2,3,2 };

	vector<string> nick_teach{"Computer science", "Mathematics","Physics" }, enton_teach{ "Literature","History of Arts" };

	Student Josh(joshua, "Joshua", "Brock", "Tomson");
	Student Stew(stev, "Steve", "Bradley", "Joshua");

	Teacher Nick('A', nick_teach, "Nick", "Brock", "Tomson");
	Teacher Enton('O', enton_teach, "Enton", "Dley", "Joshua");

	Josh.get_full_student_info();
	cout << endl;
	Stew.get_short_student_info();
	cout << endl;

	Nick.get_full_teacher_info();
	cout << endl;
	Enton.get_short_teacher_info();
	cout << endl;
	
	return 0;
}