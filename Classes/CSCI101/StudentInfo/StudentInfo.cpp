/*
 *  Program name: Student Info Formatter
 *  Author: Jeffrey Harmon
 *  Date created: May. 04, 2020
 *  Date last updated: May. 04, 2020
 *  Purpose: Format entered student data
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <regex>

#define NUM_PROGRAMS 5

struct FullName {
  std::string first;
  char middleInitial;
  std::string last;
};

enum ProgramType { CSCI, DBMS, INFM, SDEV, OTHER };
std::string ProgramName[NUM_PROGRAMS] = {"CSCI", "DBMS", "INFM", "SDEV",
                                         "Other"};

struct StudentInfo {
  FullName name;
  std::string ID;
  std::string email;
  std::string SSN;
  ProgramType program;
};

void DisplayStudentInfo(StudentInfo student);
bool isValidEmail(std::string email);
bool isValidID(std::string ID);
bool isValidSSN(std::string SSN);

int main() {
  StudentInfo student;

  std::cout << "Please enter your full name including your middle initial: ";
  std::cin >> student.name.first >> student.name.middleInitial >>
      student.name.last;

  std::cout << "Please enter your student ID: ";

  while (!(std::cin >> student.ID) || !isValidID(student.ID)) {
    std::cout << "Invalid student id! Must follow pattern Cxxxxxxxx: ";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  std::cout << "Please enter your email address: ";

  while (!(std::cin >> student.email) || !isValidEmail(student.email)) {
    std::cout << "Invalid email! Must follow pattern ***@***.***: ";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  std::cout << "Please enter your social security number: ";

  while (!(std::cin >> student.SSN) || !isValidSSN(student.SSN)) {
    std::cout << "Invalid SSN! Must follow pattern xxx-xx-xxxx: ";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  // Definining as double to prevent infininite loop bug
  double selection;

  std::cout << "Please select your program:" << std::endl;

  for (int i = 0; i < NUM_PROGRAMS; i++) {
    std::cout << i + 1 << ": " << ProgramName[i] << std::endl;
  }

  while (!(std::cin >> selection) || selection <= 0 ||
         selection > NUM_PROGRAMS) {
    std::cout << "Invalid selection! Please enter again: " << std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  student.program = (ProgramType)((int)selection - 1);

  std::cout << std::endl;

  DisplayStudentInfo(student);

  return 0;
}

void DisplayStudentInfo(StudentInfo student) {
  std::cout << "Student Info:" << std::endl;
  std::cout << "Name: " << student.name.first << " "
            << student.name.middleInitial << ". " << student.name.last
            << std::endl;
  std::cout << "ID: " << student.ID << std::endl;
  std::cout << "Email: " << student.email << std::endl;
  std::cout << "SSN: " << student.SSN << std::endl;
  std::cout << "Program: " << ProgramName[student.program] << std::endl;
}

/*
 * All three of these functions use regex (regular expressions) to check
 * whether they match a pattern.
 */

bool isValidEmail(std::string email) {
  // .+ means more than one of any character, \\. is just looking for a .
  // This is the patter an email address needs to follow
  std::regex emailPattern(".+@.+\\..+");

  // Checks the string against the pattern and returns true if it matches
  return std::regex_match(email, emailPattern);
}

bool isValidID(std::string ID) {
  // \\d means any digit (0-9)
  // {num} means that many of the previous type of character
  std::regex idPattern("C\\d{8}");

  return std::regex_match(ID, idPattern);
}

bool isValidSSN(std::string SSN) {
  // \\d means any digit (0-9)
  // {num} means that many of the previous type of character
  std::regex ssnPattern("\\d{3}-\\d{2}-\\d{4}");

  return std::regex_match(SSN, ssnPattern);
}