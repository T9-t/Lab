#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Human.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

int count_file(string file);

void save_in_file(int stat, vector<Student>& students, vector<Teacher>& teachers);

void write_in_vect(int stat, vector<Student>& students, vector<Teacher>& teachers);

int main()
{
	int func = 0, stud_or_teach;
	vector<Student> students; vector<Teacher> teachers;
	vector<double> st1{ 3,5,5 }, st2{ 2,3,2 }, st3{ 5 }, st4{ 2,3,4 }, 
		st5{ 5,4 }, st6{ 2,2,2 }, st7{ 4,3,5 }, st8{ 2 }, st9{ 3,3 }, st10{ 3,2,4 };
	vector<string> teach1{"Computer science"}, teach2{ "Literature","Russian_language" },
		teach3{ "Natural_sciences","Biology" }, teach4{ "Physics" },
		teach5{ "Mathematics","Natural_sciences","Physics" }, teach6{ "Databases" },
		teach7{ "Culture_of_speech" }, teach8{ "Literature" },
		teach9{ "Linguistics" }, teach10{ "Databases","Computer science"};
	
	Student Josh(st1, "Joshua", "Brock", "Tomson"); students.push_back(Josh);
	Student Stew(st2, "Steve", "Bradley", "Joshua"); students.push_back(Stew); 
	Student Gilb(st3, "Gilbert", "Gary", "Lopez"); students.push_back(Gilb);
	Student Pet(st4, "Peter", "Scott", "Daniels"); students.push_back(Pet);
	Student Andr(st5, "Andrew", "Fowler", "Garcia"); students.push_back(Andr);
	Student Mi(st6, "Mike", "Taylor", "Joshua"); students.push_back(Mi);
	Student Dav(st7, "David", "Gray", "Tucker"); students.push_back(Dav);
	Student Adam(st8, "Adam", "Grant", "Johnson"); students.push_back(Adam);
	Student Ad(st9, "Adrian", "Bradley", "Johnson"); students.push_back(Ad);
	Student Hil(st10, "Gilbert", "Richard", "Hill"); students.push_back(Hil);

	Teacher Nick('A', teach1, "Nick", "Mike", "Taylor"); teachers.push_back(Nick);
	Teacher Enton('O', teach2, "Enton", "Dley", "Joshua"); teachers.push_back(Enton);
	Teacher S('P', teach3, "Steve", "Bradley", "Tomson"); teachers.push_back(S);
	Teacher Ga('S', teach4, "Gary", "Lopez", "Joshua"); teachers.push_back(Ga);
	Teacher Dv('A', teach5, "Nick", "David", "Gray"); teachers.push_back(Dv);
	Teacher DL('O', teach6, "Enton", "Dley", "Joshua"); teachers.push_back(DL);
	Teacher Nk('S', teach7, "Scott", "Daniels", "Tomson"); teachers.push_back(Nk);
	Teacher Jo('P', teach8, "Adam", "Grant", "Joshua"); teachers.push_back(Jo);
	Teacher Fo('P', teach9, "Fowler", "Brock", "Tomson"); teachers.push_back(Fo);
	Teacher Ri('O', teach10, "Richard", "Hill", "Joshua"); teachers.push_back(Ri);
	
	cout << "**********************************************************************************" << endl;
	cout << "Function" << endl;
	cout << "Save vectors to file - 1" << endl;
	cout << "Write vector from file - 2" << endl;
	cout << "Brief information about all students with a GPA greater than '4' - 3" << endl;
	cout << "Brief information about all students with an average score less than '3' - 4" << endl;
	cout << "Full details of the student with the most marks - 5" << endl;
	cout << "Brief information about all associate professors - 6" << endl;
	cout << "Full details of the professor who has the most subjects - 7" << endl;
	cout << "Full information about all teachers who teach computer science - 8" << endl;
	cout << "Show full information about students and teachers - 9" << endl;
	cout << "Terminate the program - 10" << endl;
	cout << "**********************************************************************************" << endl;

	while (func != 10) {
		cout << "****************************************************" << endl;
		cout << "Select function: ";
		cin >> func;

		if (func == 1) {

			cout << "Select vector(1-teacher, 2-students): ";
			cin >> stud_or_teach;
	
			save_in_file(stud_or_teach, students, teachers);
		}
		else if (func == 2) {

			cout << "Select vector(1-teacher, 2-students): ";
			cin >> stud_or_teach;

			write_in_vect(stud_or_teach, students, teachers);
		}
		else if (func == 3) {

			for (int i = 0; i < students.size(); i++) {

				if (students[i].get_average_score() > 4) {

					students[i].get_short_student_info();
				}
			}
		}
		else if (func == 4) {

			for (int i = 0; i < students.size(); i++) {
				
				if (students[i].get_average_score() < 3) {

					students[i].get_short_student_info();
				}
			}
		}
		else if (func == 5) {

			int max_vect = 0, max_size = 0;

			for (int i = 0; i < students.size(); i++) {

				if (students[i].size_score() > max_size) {

					max_size = students[i].size_score();
					max_vect = i;
				}
			}
			students[max_vect].get_full_student_info();
		}
		else if (func == 6) {

			for (int i = 0; i < teachers.size(); i++) {

				if (teachers[i].title() == 'O') {

					teachers[i].get_short_teacher_info();
				}
			}
		}
		else if (func == 7) {

			int max_vect = 0, max_size = 0;

			for (int i = 0; i < teachers.size(); i++) {

				if (teachers[i].size_subjects() > max_size) {

					max_size = teachers[i].size_subjects();
					max_vect = i;
				}
			}
			teachers[max_vect].get_full_teacher_info();
		}
		else if (func == 8) {

			for (int i = 0; i < teachers.size(); i++) {
				for (int j = 0; j < teachers[i].size_subjects(); j++) {

					if (teachers[i].subjects(j) == "Computer science") {

						teachers[i].get_full_teacher_info();
					}
				}
			}
		}
		else if (func == 9) {

			cout << "--List of teachers" << endl;
			for (int i = 0; i < teachers.size(); i++) {

				teachers[i].get_full_teacher_info();
			}cout << endl;

			cout << "--List of students" << endl;
			for (int i = 0; i < students.size(); i++) {

				students[i].get_full_student_info();
			}cout << endl;
		}
	}
	return 0;
}

int count_file(string file) {

	int cout_word = 0;
	
	ifstream List(file);

	if (!List) {
		cout << "--File not found" << endl;
	}
	else {
		while (!List.eof()) {

			string word;
			List >> word;
			cout_word++;
		}
	}
	return cout_word;
}

void save_in_file(int stat, vector<Student>& students, vector<Teacher>& teachers) {

	if (stat == 1) {

		ofstream Teachers_list("Teachers_list.txt");

		if (!Teachers_list) {
			cout << "--File not found" << endl;
		}
		else {
			for (int i = 0; i < teachers.size(); i++) {

				Teachers_list << teachers[i].title() << " ";

				for (int j = 0; j < teachers[i].size_subjects(); j++) {

					Teachers_list << teachers[i].subjects(j) << " ";
				}
				Teachers_list << teachers[i].get_name() << " ";
				Teachers_list << teachers[i].get_last_name() << " ";
				Teachers_list << teachers[i].get_surmame() << endl;
			}
		}
		Teachers_list.close();
		cout << "--The list of teachers has been saved to file" << endl;
	}
	else {

		ofstream Students_list("Students_list.txt");

		if (!Students_list) {
			cout << "--File not found" << endl;
		}
		else {
			for (int i = 0; i < students.size(); i++) {

				for (int j = 0; j < students[i].size_score(); j++) {

					Students_list << students[i].score_num(j) << " ";
				}
				Students_list << students[i].get_name() << " ";
				Students_list << students[i].get_last_name() << " ";
				Students_list << students[i].get_surmame() << endl;
			}
		}
		Students_list.close();
		cout << "--The list of students has been saved to a file" << endl;
	}
}

void write_in_vect(int stat, vector<Student>& students, vector<Teacher>& teachers) {

	vector<Teacher> teacher_cop; vector<Student> student_cop;
	vector<string> subjects_vec; vector<double> score_vec;
	string in_list, Name, Last_name, Surmame;
	char title; double score;
	
	if (stat == 1) {

		ifstream Teachers_list("Teachers_list_read.txt");

		if (!Teachers_list) {
			cout << "--File not found" << endl;
		}
		else {
			for (int i = 0; i < (count_file("Teachers_list_read.txt")/5); i++) {

				Teachers_list >> title;

				Teachers_list >> in_list;
				subjects_vec.push_back(in_list);

				Teachers_list >> Name;
				Teachers_list >> Last_name;
				Teachers_list >> Surmame;

				Teacher teacher(title, subjects_vec, Name, Last_name, Surmame);
				teacher_cop.push_back(teacher);
				subjects_vec.clear();
			}
			teachers = teacher_cop;
		}
		Teachers_list.close();
		cout << "--The list of teachers is copied from the file" << endl;
	}
	else {

		ifstream Students_list("Students_list_read.txt");

		if (!Students_list) {
			cout << "--File not found" << endl;
		}
		else {
			for (int i = 0; i < (count_file("Students_list_read.txt")/6); i++) {

				for (int i = 0; i < 3; i++) {

					Students_list >> score;
					score_vec.push_back(score);
				}

				Students_list >> Name;
				Students_list >> Last_name;
				Students_list >> Surmame;

				Student student(score_vec, Name, Last_name, Surmame);
				student_cop.push_back(student);
				score_vec.clear();
			}
			students = student_cop;

		}
		Students_list.close();
		cout << "--The list of students is copied from the file" << endl;
	}
}