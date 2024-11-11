#pragma once
#include "Student.hpp"
#include <iostream>

Student::Student()
{
    id = 0;
    name = "";
    age = 0;
    point = 0;
}

Student::Student(unsigned long long id)
{
    this->id = id;
}

Student::Student(unsigned long long id, std::string name, int age, double point)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->point = point;
}

unsigned long long Student::GetId()
{
    return id;
}

std::string Student::GetName()
{
    return name;
}
int Student::GetAge()
{
    return age;
}
double Student::GetPoint()
{
    return point;
}
void Student::SetName(std::string name)
{
    this->name = name;
}
void Student::SetAge(int age)
{
    this->age = age;
}
void Student::SetPoint(double point)
{
    this->point = point;
}

std::istream &operator>>(std::istream &is, Student &s)
{
    std::string readString;
    std::cout << "Nhap ten: ";
    getline(is, s.name);
    std::cout << "Nhap tuoi: ";
    getline(is, readString);
    s.age = std::stoi(readString);
    std::cout << "Nhap diem: ";
    getline(is, readString);
    s.point = std::stod(readString);
    return is;
}

std::ostream &operator<<(std::ostream &os, Student s)
{
    os << "Dinh danh: " << s.id << "; Ten: " << s.name << "; Tuoi: " << s.age << "; Diem: " << s.point;
    return os;
}

bool operator>(Student a, Student b)
{
    return a.point > b.point;
}

bool operator>=(Student a, Student b)
{
    return a.point >= b.point;
}

bool operator<(Student a, Student b)
{
    return a.point < b.point;
}

bool operator<=(Student a, Student b)
{
    return a.point <= b.point;
}

bool operator==(Student a, Student b)
{
    return a.point == b.point;
}
