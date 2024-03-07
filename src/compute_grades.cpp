
#include "compute_grades.hpp"


#include <algorithm>
#include <numeric>
#include <cmath>
#include <compare>
#include <iomanip>
#include <iosfwd>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;





void Student::validate() const {
	auto check = [](int i){ if (i < 0 || i > 100) throw domain_error("Error: invalid percentage " + i);};

	for_each(quiz.begin(), quiz.end(), check);
	for_each(hw.begin(), quiz.end(), check);
	check(final_score);
	}



strong_ordering Student::operator <=> (const Student& other) const
{
    return (last_name+first_name) <=> (other.last_name+other.first_name);
}





bool Student::operator==(const Student& other) const{ 
	return last_name == other.last_name && first_name == other.first_name; 
	}




istream& operator>>(istream& in, Student& s){
	string line;
	while(getline(in, line) && !line.empty()){
		getline(in, line);
		istringstream stream(line);
		string head;
		stream >> head;
		if (head == "Name"){
			stream >> s.first_name;
			stream >> s.last_name;
			string rest;
			while(stream >> rest){
				s.last_name = s.last_name + "" + rest;
				}
			}
		else if(head == "Quiz")
			for_each(istream_iterator<string>(stream), istream_iterator<string>(), [&](string quiz){s.quiz.push_back(stoi(quiz));});
		else if(head == "HW")
			for_each(istream_iterator<string>(stream), istream_iterator<string>(), [&](string hh) {s.hw.push_back(stoi(hh));});
		else if(head == "Final")
			stream >> s.final_score;
	}
	return in;

	}



ostream& operator<<(ostream& out, const Student& s) {
    out << left << setw(8) << "Name: " << s.first_name << s.last_name << '\n'
        << setw(8) << "HW Ave: " << s.hw_avg << '\n'
        << setw(8) << "QZ Ave: " << s.quiz_avg << '\n'
        << setw(8) << "Final: " << s.final_score << '\n'
        << setw(8) << "Total: " << s.course_score << '\n'
        << setw(8) << "Grade: " << s.course_grade << endl;
    return out;
}



void Student::compute_quiz_avg(){
	if (!quiz.size()) quiz_avg = 0;
    else if (quiz.size() == 1) quiz_avg = quiz[0];
    else { 
		int min = *std::min_element(quiz.begin(), quiz.end());
        double total = accumulate(quiz.begin(), quiz.end(), 0.0);
        quiz_avg = (total - min)/(quiz.size() - 1);
	
	}
	}

void Student::compute_hw_avg(){
	if (!hw.size()) hw_avg = 0;
    else if (hw.size() == 1) hw_avg = hw[0];
	else{
		double sum = accumulate(hw.begin(), hw.end(), 0.0);
        hw_avg = sum / hw.size();
	}
	}

void Student::compute_course_score(){
	compute_quiz_avg();
    compute_hw_avg();
	course_score = round(0.4 * quiz_avg + 0.3 * hw_avg + 0.3 * final_score);

	}


void Student::compute_grade() {
    compute_quiz_avg();
    compute_hw_avg();
    compute_course_score();
    
    if (97 <= course_score) course_grade = "A+";
    else if (93 <= course_score) course_grade = "A";
    else if (90 <= course_score) course_grade = "A-";
    else if (87 <= course_score) course_grade = "B+";
    else if (83 <= course_score) course_grade = "B";
    else if (80 <= course_score) course_grade = "B-";
    else if (77 <= course_score) course_grade = "C+";
    else if (73 <= course_score) course_grade = "C";
    else if (70 <= course_score) course_grade = "C-";
    else if (67 <= course_score) course_grade = "D+";
    else if (63 <= course_score) course_grade = "D";
    else if (60 <= course_score) course_grade = "D-";
    else course_grade = "F";
}






void Gradebook::validate() const {
    for_each(students.begin(), students.end(), [&](const Student& s){s.validate();});
}


void Gradebook::compute_grades() {
    for_each(students.begin(), students.end(), [&](Student& s){s.compute_grade();});
}


void Gradebook::sort() {
    std::sort(students.begin(), students.end());
}





istream& operator>>(istream& in, Gradebook& b)
{
    Student s;
    while(in >> s)
    {
        b.students.push_back(s);
    }
    return in;
}


ostream& operator<<(std::ostream& out, const Gradebook& b) {
    for_each(b.students.begin(), b.students.end(), [&](Student s){out << s << '\n';});
    return out;
}
