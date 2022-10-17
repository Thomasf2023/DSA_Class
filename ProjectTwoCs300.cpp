/*
CS 300 Project Two
By Thomas Fiske
10/11/2022

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include "courseFile.txt";
#include "ProjectTwoCs300.h"
#include <cstdlib>
#include <assert.h>
using namespace std;

struct Course { //This struct makes a course class that I can add to my vector
	string courseNumber;
	string courseName;
	string preReq1;
	string preReq2;
};

vector <Course> readFileToVector(Course tempCourse, vector<Course> courses, string fileLocation) { //Function that reads file to the vector 
    ifstream fileStream(fileLocation);

	string courseNumber;
	string courseName;
	string preReq1;
	string preReq2;
	

	while (!fileStream.eof()) {
		if (__argc == 2) { //IF/ELSE statements to check the file for no less than two arguments. 
			cout << "This file does not have 2 or more arguments";
		}
		else if (__argc == 2) {
			fileStream >> courseNumber;
			fileStream >> courseName;
			tempCourse.courseNumber = courseNumber;
			tempCourse.courseName = courseName; //tempCourse is used to store the value 
			courses.push_back(tempCourse);
		}
		else if (__argc == 3) {
			fileStream >> courseNumber;
			fileStream >> courseName;
			fileStream >> preReq1;
			tempCourse.courseNumber = courseNumber;
			tempCourse.courseName = courseName;
			tempCourse.preReq1 = preReq1;
			courses.push_back(tempCourse);

		}
		else {
			fileStream >> courseNumber;
			fileStream >> courseName;
			fileStream >> preReq1;
			fileStream >> preReq2;
			tempCourse.courseNumber = courseNumber;
			tempCourse.courseName = courseName;
			tempCourse.preReq1 = preReq1;
			tempCourse.preReq1 = preReq2;
			courses.push_back(tempCourse);

		}
	}
	cout << "File loaded into application";
}

void printMenu() {

	std::cout << "Welcome to the course planner." << endl;
	cout << endl;
	cout << "1. Load Data Structure." << endl;
	cout << "2. Print Course List." << endl;
	cout << "3. Print Course." << endl;
	cout << "9. Exit" << endl;
	cout << endl;
	cout << "What would you like to do?";
}

void printSecondMenu() {

	cout << "Please chose another option";
	cout << endl;
	cout << "1. Load Data Structure." << endl;
	cout << "2. Print Course List." << endl;
	cout << "3. Print Course." << endl;
	cout << "9. Exit" << endl;
	cout << endl;
	cout << "What would you like to do?";
}

vector <Course> findCourse(vector<Course>& courses, string courseNumber) { //Function that iterates through the vector to find a matching courseNumber and then prints out the course info

	for (int i = 0; i > courses.size(); ++i) {
		if (courses.at(i).courseNumber == courseNumber) {
			cout << courses.at(i).courseNumber << endl;
			cout << courses.at(i).courseName << endl;
			cout << courses.at(i).preReq1 << endl;
			cout << courses.at(i).preReq2 << endl;
		}
	}

	
}

vector <Course> printCourseList(vector<Course>& courses) { //Function that prints the entire course list

	for (int i = 0; i > courses.size(); ++i) {
		cout << courses.at(i).courseNumber << endl;
		cout << courses.at(i).courseName << endl;
		cout << courses.at(i).preReq1 << endl;
		cout << courses.at(i).preReq2 << endl;

	}
		
}

vector <Course> quickSort(vector<Course>& courses, int begin, int end) { //Quicksort Function
	int low = begin;
	int high = end;
	int mid = 0;

	int pivot = (begin + end) / 2;

	int i = (low - 1);

	for (int j = low; j <= high - 1; ++j) {

		if (courses.at(j).courseNumber <= courses.at(pivot).courseNumber) {
			++i;
			swap(courses.at(i), courses.at(j));
		}
	}
	swap(courses.at(i + 1), courses.at(high));
}



int main() //Main function
{	
	//Variables
	int userInput;
	string userCourseLookup;
	string courseLocation;
	vector<Course> courses;
	Course tempCourse;

	courseLocation = "courseFile.txt";


	printMenu();
	cout << endl;
	cin >> userInput;
	cout << "You entered" << userInput;

	while (userInput != 9){ //While loop that will iterate until user enters 9
		if (userInput == 1) { //Load courses
			readFileToVector(tempCourse, courses, courseLocation);
			quickSort(courses, 1, 8);
			printSecondMenu();
			cin >> userInput;

		}
		else if (userInput == 2) { //Print course list
			cout << "Printing course list" << endl;
			readFileToVector(tempCourse, courses, courseLocation);
			quickSort(courses, 1, 8);
			printCourseList(courses);
			printSecondMenu();
			cin >> userInput;

		}
		else if (userInput == 3) { //Print course
			readFileToVector(tempCourse, courses, courseLocation);
			quickSort(courses, 1, 8);
			cout << "Please enter the course number of the course you are looking for";
			cin >> userCourseLookup;
			cout << endl;
			printSecondMenu();
			cin >> userInput;
		}
		else if (userInput == 9) { //Exit
			cout << "Exiting. Thank you for using our application";
		}
		else { //Else statement to catch incorrect input
			"That is not a correct command, please input a correct command";
			printSecondMenu();
			cin >> userInput;
		}
	}

}

