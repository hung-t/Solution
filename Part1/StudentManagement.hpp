#pragma once

#include <list>
#include <vector>
#include <iostream>
#include "App.cpp"
#include "Student.hpp"
class StudentManagement
{
private:
    std::list<Student> studentList;
    std::vector<Student> studentVector;
    std::string fileDirectory;
    std::string errorMessage;
    bool isValidId(const std::string str);
    bool isValidName(const std::string str);
    bool isValidAge(const std::string str);
    bool isValidPoint(const std::string str);

public:
    StudentManagement();
    StudentManagement(const std::string fileDirectory);
    ~StudentManagement();
    void Search();
    void Modify();
    void Delete();
    void Add();
    void ShowListStudent();
    void ShowSortedStudentList();
    void ReadWrite();
};

#include "StudentManagement.cpp"