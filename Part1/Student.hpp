#pragma once

#include <string>
class Student
{
private:
    unsigned long long id;
    std::string name;
    int age;
    double point;

public:
    Student();
    Student(unsigned long long id);
    Student(unsigned long long id, std::string name, int age, double point);
    unsigned long long GetId();
    std::string GetName();
    int GetAge();
    double GetPoint();
    void SetName(std::string name);
    void SetAge(int age);
    void SetPoint(double point);
    friend std::istream &operator>>(std::istream &is, Student &s);
    friend std::ostream &operator<<(std::ostream &os, Student s);
    friend bool operator>(Student a, Student b);
    friend bool operator>=(Student a, Student b);
    friend bool operator<(Student a, Student b);
    friend bool operator<=(Student a, Student b);
    friend bool operator==(Student a, Student b);
};

#include "Student.cpp"
