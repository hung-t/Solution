#pragma once
#include <list>
#include <vector>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <sstream>
#include <fstream>
#include "StudentManagement.hpp"
#include "App.cpp"

bool StudentManagement::isValidId(const std::string str)
{
    if (str.empty())
    {
        errorMessage = "Ma dinh danh khong duoc de trong";
        return false;
    }
    if (str.size() >= 17)
    {
        errorMessage = "Ma dinh danh qua lon";
        return false;
    }
    for (char c : str)
    {
        if (!std::isdigit(c))
        {
            errorMessage = "Ma dinh danh chi chua ky tu so tu 0 - 9";
            return false;
        }
    }
    if (std::stoi(str) > 1000000000000000 || std::stoi(str) < 1000000)
    {
        errorMessage = "Ma dinh danh chi nam trong gia tri tu 1000000 den 1000000000000000";
        return false;
    }
    return true;
}

bool StudentManagement::isValidName(const std::string str)
{
    if (str.empty())
    {
        errorMessage = "Ten khong duoc de trong";
        return false;
    }
    if (str.size() > 40)
    {
        errorMessage = "Ten chi co gioi han duoi hoac bang 40 ky tu";
        return false;
    }
    for (char c : str)
    {
        if (!isalpha(c) && c != ' ')
        {
            errorMessage = "Ten chi gom cac ky tu tu a -> z hoac tu A -> Z hoac ' '";
            return false;
        }
    }
    return true;
}
bool StudentManagement::isValidAge(const std::string str)
{
    if (str.empty())
    {
        errorMessage = "Tuoi khong duoc de trong";
        return false;
    }
    if (str.size() >= 4)
    {
        errorMessage = "Tuoi qua lon. Tuoi chi nam trong gia tri tu 0 den 150";
        return false;
    }
    for (char c : str)
    {
        if (!std::isdigit(c))
        {
            errorMessage = "Tuoi chi chua ky tu so tu 0 - 9";
            return false;
        }
    }
    if (std::stoi(str) > 150 || std::stoi(str) < 0)
    {
        errorMessage = "Tuoi chi nam trong gia tri tu 0 den 150";
        return false;
    }
    return true;
}

bool StudentManagement::isValidPoint(const std::string str)
{
    size_t demicalPointCount = 0;
    if (str.empty())
    {
        errorMessage = "Diem khong duoc de trong";
        return false;
    }
    if (str.size() >= 6)
    {
        errorMessage = "Diem qua lon. Diem chi nam trong gia tri tu 0 den 10";
        return false;
    }
    for (char c : str)
    {
        if (c == '.')
        {
            demicalPointCount++;
        }
        else if (!std::isdigit(c))
        {
            errorMessage = "Diem chi chua ky tu so tu 0 - 9 hoac nhieu nhat 1 dau '.'";
            return false;
        }
    }
    if (demicalPointCount >= 2)
    {
        errorMessage = "Diem chi co nhieu nhat 1 dau '.'";
        return false;
    }
    if (std::stod(str) > 10 || std::stod(str) < 0)
    {
        errorMessage = "Diem chi nam trong gia tri tu 0 den 10";
        return false;
    }
    return true;
}

StudentManagement::StudentManagement()
{
}

StudentManagement::StudentManagement(const std::string fileDirectory)
{
    this->fileDirectory = fileDirectory;
    std::string readString;
    unsigned long long id;
    std::string name;
    int age;
    double point;
    std::ifstream file(fileDirectory, std::ifstream::in);
    if (!file.is_open())
    {
        std::cout << "Bam phim bat ky de tiep tuc";
        _getch();

        return;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    while (getline(buffer, readString, '\n'))
    {
        id = std::stoull(readString);
        getline(buffer, name, '\n');
        getline(buffer, readString, '\n');
        age = std::stoi(readString);
        getline(buffer, readString, '\n');
        point = std::stod(readString);
        if (id % 2 == 0)
        {
            studentVector.push_back(Student(id, name, age, point));
        }
        else
        {
            studentList.push_back(Student(id, name, age, point));
        }
    }
    file.close();
    system("cls");
}

StudentManagement::~StudentManagement()
{
    std::ofstream file(fileDirectory, std::ofstream::out | std::ofstream::trunc);
    for (auto &student : studentList)
    {
        file << student.GetId() << "\n"
             << student.GetName() << "\n"
             << student.GetAge() << "\n"
             << student.GetPoint() << "\n";
    }
    for (auto &student : studentVector)
    {
        file << student.GetId() << "\n"
             << student.GetName() << "\n"
             << student.GetAge() << "\n"
             << student.GetPoint() << "\n";
    }
    file.close();
}

void StudentManagement::Search()
{
    system("cls");
    std::string readString;
    unsigned long long searchId;
    bool isFound = false;
    std::cout << "Nhap ma sinh vien tim kiem sinh vien: ";
    getline(std::cin, readString);
    while (!isValidId(readString))
    {
        std::cout << "Ma sinh vien nhap khong hop le: " << errorMessage << std::endl;
        std::cout << "Bam esc de quay lai trang chinh hoac bam phim khac de tiep tuc: ";
        if (_getch() == 27)
        {
            return;
        }
        std::cout << "\nNhap ma sinh vien lai: ";
        getline(std::cin, readString);
    }
    searchId = std::stoull(readString);
    if (searchId % 2 == 0)
    {
        for (auto student : studentVector)
        {
            if (searchId == student.GetId())
            {
                std::cout << "Da tim thay sinh vien" << std::endl;
                std::cout << "Ma dinh danh: " << student.GetId() << std::endl;
                std::cout << "Ten: " << student.GetName() << std::endl;
                std::cout << "Tuoi: " << student.GetAge() << std::endl;
                std::cout << "Diem: " << student.GetPoint() << std::endl;
                isFound = true;
                break;
            }
        }
    }
    else
    {
        for (auto &student : studentList)
        {
            if (searchId == student.GetId())
            {
                std::cout << "Da tim thay sinh vien" << std::endl;
                std::cout << "Ma dinh danh: " << student.GetId() << std::endl;
                std::cout << "Ten: " << student.GetName() << std::endl;
                std::cout << "Tuoi: " << student.GetAge() << std::endl;
                std::cout << "Diem: " << student.GetPoint() << std::endl;
                isFound = true;
                break;
            }
        }
    }
    if (!isFound)
        std::cout << "Khong tim thay sinh vien" << std::endl;
    std::cout << "Bam phim bat ky de quay ve trang chinh";
    _getch();
}

void StudentManagement::Modify()
{
    system("cls");
    std::string readString;
    unsigned long long searchId;
    bool isFound = false;
    std::cout << "Nhap ma sinh vien de chinh sua: ";
    getline(std::cin, readString);
    while (!isValidId(readString))
    {
        std::cout << "Ma sinh vien nhap khong hop le: " << errorMessage << std::endl;
        std::cout << "Bam esc de quay lai trang chinh hoac bam phim khac de tiep tuc: ";
        if (_getch() == 27)
        {
            return;
        }
        std::cout << "\nNhap ma sinh vien lai: ";
        getline(std::cin, readString);
    }
    searchId = std::stoull(readString);
    if (searchId % 2 == 0)
    {
        for (auto &student : studentVector)
        {
            if (searchId == student.GetId())
            {
                std::cout << "Da tim thay sinh vien" << std::endl;
                std::cout << "Ma dinh danh: " << student.GetId() << std::endl;
                std::cout << "Ten: " << student.GetName() << std::endl;
                std::cout << "Tuoi: " << student.GetAge() << std::endl;
                std::cout << "Diem: " << student.GetPoint() << std::endl;
                isFound = true;
                std::string name;
                int age;
                double point;
                std::cout << "Nhap ten sinh vien can chinh: ";
                getline(std::cin, readString, '\n');
                while (!isValidName(readString))
                {
                    std::cout << "Ten sinh vien nhap khong hop le: " << errorMessage << std::endl;
                    std::cout << "Bam esc de quay lai trang chinh hoac bam phim khac de tiep tuc: ";
                    if (_getch() == 27)
                    {
                        return;
                    }
                    std::cout << "\nNhap ten sinh vien lai: ";
                    getline(std::cin, readString);
                }
                name = readString;
                std::cout << "Nhap tuoi sinh vien can chinh: ";
                getline(std::cin, readString, '\n');
                while (!isValidAge(readString))
                {
                    std::cout << "Tuoi sinh vien nhap khong hop le: " << errorMessage << std::endl;
                    std::cout << "Bam esc de quay lai trang chinh hoac bam phim khac de tiep tuc: ";
                    if (_getch() == 27)
                    {
                        return;
                    }
                    std::cout << "\nNhap tuoi sinh vien lai: ";
                    getline(std::cin, readString);
                }
                age = std::stoi(readString);
                std::cout << "Nhap diem sinh vien can chinh: ";
                getline(std::cin, readString, '\n');
                while (!isValidPoint(readString))
                {
                    std::cout << "Diem sinh vien nhap khong hop le: " << errorMessage << std::endl;
                    std::cout << "Bam esc de quay lai trang chinh hoac bam phim khac de tiep tuc: ";
                    if (_getch() == 27)
                    {
                        return;
                    }
                    std::cout << "\nNhap diem sinh vien lai: ";
                    getline(std::cin, readString);
                }
                point = std::stod(readString);
                std::cout << "Ban co dong y chinh sua khong" << std::endl;
                std::cout << "Goc >> Chinh sua" << std::endl;
                std::cout << "Ten: " << student.GetName() << " >> " << name << std::endl;
                std::cout << "Tuoi: " << student.GetAge() << " >> " << age << std::endl;
                std::cout << "Diem: " << student.GetPoint() << " >> " << point << std::endl;
                std::cout << "Bam phim Y de dong y chinh sua" << std::endl;
                std::cout << "Bam phim con lai de tu choi chinh sua" << std::endl;
                char c = getch();
                if (c == 'y' || c == 'Y')
                {
                    student.SetName(name);
                    student.SetAge(age);
                    student.SetPoint(point);
                    std::cout << "Da chinh sua thanh cong" << std::endl;
                }
                else
                {
                    std::cout << "Chua chinh sua" << std::endl;
                }
                break;
            }
        }
    }
    else
    {
        for (auto &student : studentList)
        {
            if (searchId == student.GetId())
            {
                std::cout << "Da tim thay sinh vien" << std::endl;
                std::cout << "Ma dinh danh: " << student.GetId() << std::endl;
                std::cout << "Ten: " << student.GetName() << std::endl;
                std::cout << "Tuoi: " << student.GetAge() << std::endl;
                std::cout << "Diem: " << student.GetPoint() << std::endl;
                isFound = true;
                std::string name;
                int age;
                double point;
                std::cout << "Nhap ten sinh vien can chinh: ";
                getline(std::cin, readString, '\n');
                while (!isValidName(readString))
                {
                    std::cout << "Ten sinh vien nhap khong hop le: " << errorMessage << std::endl;
                    std::cout << "Bam esc de quay lai trang chinh hoac bam phim khac de tiep tuc: ";
                    if (_getch() == 27)
                    {
                        return;
                    }
                    std::cout << "\nNhap ten sinh vien lai: ";
                    getline(std::cin, readString);
                }
                name = readString;
                std::cout << "Nhap tuoi sinh vien can chinh: ";
                getline(std::cin, readString, '\n');
                while (!isValidAge(readString))
                {
                    std::cout << "Tuoi sinh vien nhap khong hop le: " << errorMessage << std::endl;
                    std::cout << "Bam esc de quay lai trang chinh hoac bam phim khac de tiep tuc: ";
                    if (_getch() == 27)
                    {
                        return;
                    }
                    std::cout << "\nNhap tuoi sinh vien lai: ";
                    getline(std::cin, readString);
                }
                age = std::stoi(readString);
                std::cout << "Nhap diem sinh vien can chinh: ";
                getline(std::cin, readString, '\n');
                while (!isValidPoint(readString))
                {
                    std::cout << "Diem sinh vien nhap khong hop le: " << errorMessage << std::endl;
                    std::cout << "Bam esc de quay lai trang chinh hoac bam phim khac de tiep tuc: ";
                    if (_getch() == 27)
                    {
                        return;
                    }
                    std::cout << "\nNhap diem sinh vien lai: ";
                    getline(std::cin, readString);
                }
                point = std::stod(readString);
                std::cout << "Ban co dong y chinh sua khong" << std::endl;
                std::cout << "Goc >> Chinh sua" << std::endl;
                std::cout << "Ten: " << student.GetName() << " >> " << name << std::endl;
                std::cout << "Tuoi: " << student.GetAge() << " >> " << age << std::endl;
                std::cout << "Diem: " << student.GetPoint() << " >> " << point << std::endl;
                std::cout << "Bam phim Y de dong y chinh sua" << std::endl;
                std::cout << "Bam phim con lai de tu choi chinh sua" << std::endl;
                char c = getch();
                if (c == 'y' || c == 'Y')
                {
                    student.SetName(name);
                    student.SetAge(age);
                    student.SetPoint(point);
                    std::cout << "Da chinh sua thanh cong" << std::endl;
                }
                else
                {
                    std::cout << "Chua chinh sua" << std::endl;
                }
                break;
            }
        }
    }

    if (!isFound)
        std::cout << "Khong tim thay sinh vien\n";
    std::cout << "Bam phim bat ky de quay ve trang chinh";
    _getch();
}

void StudentManagement::Delete()
{
    system("cls");
    std::string readString;
    unsigned long long searchId;
    bool isFound = false;
    std::cout << "Nhap ma sinh vien de xoa sinh vien: ";
    getline(std::cin, readString);
    while (!isValidId(readString))
    {
        std::cout << "Ma sinh vien nhap khong hop le: " << errorMessage << std::endl;
        std::cout << "Bam esc de quay lai trang chinh hoac bam phim khac de tiep tuc: ";
        if (_getch() == 27)
        {
            return;
        }
        std::cout << "\nNhap ma sinh vien lai: ";
        getline(std::cin, readString);
    }
    searchId = std::stoull(readString);
    if (searchId % 2 == 0)
    {
        int it = 0;
        for (auto &student : studentVector)
        {
            if (searchId == student.GetId())
            {
                isFound = true;
                std::cout << "Da tim thay sinh vien" << std::endl;
                std::cout << "Ma dinh danh: " << student.GetId() << std::endl;
                std::cout << "Ten: " << student.GetName() << std::endl;
                std::cout << "Tuoi: " << student.GetAge() << std::endl;
                std::cout << "Diem: " << student.GetPoint() << std::endl;
                std::cout << "Ban co muon xoa sinh vien nay khong?" << std::endl;
                std::cout << "Bam phim Y de dong y xoa" << std::endl;
                std::cout << "Bam phim con lai de tu choi xoa" << std::endl;
                char c = getch();
                if (c == 'y' || c == 'Y')
                {
                    // studentVector.remove(student);
                    studentVector.erase(studentVector.begin() + it);
                    std::cout << "Da xoa thanh cong" << std::endl;
                }
                else
                    std::cout << "Sinh vien nay chua xoa" << std::endl;
                break;
            }
            it++;
        }
    }
    else
    {
        for (auto &student : studentList)
        {
            if (searchId == student.GetId())
            {
                isFound = true;
                std::cout << "Da tim thay sinh vien" << std::endl;
                std::cout << "Ma dinh danh: " << student.GetId() << std::endl;
                std::cout << "Ten: " << student.GetName() << std::endl;
                std::cout << "Tuoi: " << student.GetAge() << std::endl;
                std::cout << "Diem: " << student.GetPoint() << std::endl;
                std::cout << "Ban co muon xoa sinh vien nay khong?" << std::endl;
                std::cout << "Bam phim Y de dong y xoa" << std::endl;
                std::cout << "Bam phim con lai de tu choi xoa" << std::endl;
                char c = getch();
                if (c == 'y' || c == 'Y')
                {
                    studentList.remove(student);
                    std::cout << "Da xoa thanh cong" << std::endl;
                }
                else
                    std::cout << "Sinh vien nay chua xoa" << std::endl;
                break;
            }
        }
    }
    if (!isFound)
        std::cout << "Khong tim thay sinh vien" << std::endl;
    std::cout << "Bam phim bat ky de quay ve trang chinh";
    _getch();
}

void StudentManagement::Add()
{
    system("cls");
    // Get createId
    unsigned createId = 1000000;
    for (auto &student : studentList)
    {
        createId = (createId > student.GetId()) ? createId : student.GetId();
    }
    for (auto &student : studentVector)
    {
        createId = (createId > student.GetId()) ? createId : student.GetId();
    }
    createId++;
    std::string readString;
    std::string name;
    int age;
    double point;
    std::cout << "Nhap ten sinh vien: ";
    getline(std::cin, readString, '\n');
    while (!isValidName(readString))
    {
        std::cout << "Ten sinh vien nhap khong hop le: " << errorMessage << std::endl;
        std::cout << "Bam esc de quay lai trang chinh hoac bam phim khac de tiep tuc: ";
        if (_getch() == 27)
        {
            return;
        }
        std::cout << "\nNhap ten sinh vien lai: ";
        getline(std::cin, readString);
    }
    name = readString;
    std::cout << "Nhap tuoi sinh vien: ";
    getline(std::cin, readString, '\n');
    while (!isValidAge(readString))
    {
        std::cout << "Tuoi sinh vien nhap khong hop le: " << errorMessage << std::endl;
        std::cout << "Bam esc de quay lai trang chinh hoac bam phim khac de tiep tuc: ";
        if (_getch() == 27)
        {
            return;
        }
        std::cout << "\nNhap tuoi sinh vien lai: ";
        getline(std::cin, readString);
    }
    age = std::stoi(readString);
    std::cout << "Nhap diem sinh vien: ";
    getline(std::cin, readString, '\n');
    while (!isValidPoint(readString))
    {
        std::cout << "Diem sinh vien nhap khong hop le: " << errorMessage << std::endl;
        std::cout << "Bam esc de quay lai trang chinh hoac bam phim khac de tiep tuc: ";
        if (_getch() == 27)
        {
            return;
        }
        std::cout << "\nNhap diem sinh vien lai: ";
        getline(std::cin, readString);
    }
    point = std::stod(readString);
    if (createId % 2 == 0)
    {
        studentVector.push_back(Student(createId, name, age, point));
    }
    else
    {
        studentList.push_back(Student(createId, name, age, point));
    }
    std::cout << "Da them thanh cong" << std::endl;
    std::cout << "Bam phim bat ky de quay ve trang chinh";
    _getch();
}

void StudentManagement::ShowListStudent()
{
    system("cls");
    std::cout << std::setw(15) << "Ma dinh danh" << "|" << std::setw(40)
              << "Ten" << "|" << std::setw(5)
              << "Tuoi" << "|" << std::setw(8)
              << "Diem" << "\n";
    if (studentList.empty() && studentVector.empty())
    {
        std::cout << "----------------     Khong co hoc sinh nao     ----------------\n";
    }
    for (auto &student : studentList)
    {
        std::cout << std::setw(15) << student.GetId() << "|" << std::setw(40)
                  << student.GetName() << "|" << std::setw(5)
                  << student.GetAge() << "|" << std::setw(8)
                  << student.GetPoint() << "\n";
    }
    for (auto &student : studentVector)
    {
        std::cout << std::setw(15) << student.GetId() << "|" << std::setw(40)
                  << student.GetName() << "|" << std::setw(5)
                  << student.GetAge() << "|" << std::setw(8)
                  << student.GetPoint() << "\n";
    }
    std::cout << "Bam phim bat ky de quay ve trang chinh";
    _getch();
}

void StudentManagement::ShowSortedStudentList()
{
    system("cls");
    std::list<Student> sortedStudentList;
    for (auto student : studentList)
    {
        sortedStudentList.push_back(student);
    }
    for (auto student : studentVector)
    {
        sortedStudentList.push_back(student);
    }
    int key;
    std::cout << "Nhan phim 'y' hoac 'Y' de sap xep theo diem tang dan hoac bam phim bat ki de sap xep theo diem giam dan: " << std::endl;
    key = _getch();
    if (key == 'y' || key == 'Y')
    {
        // Increase sort
        std::cout << std::setw(15) << "Ma dinh danh" << "|" << std::setw(40)
                  << "Ten" << "|" << std::setw(5)
                  << "Tuoi" << "|" << std::setw(8)
                  << "Diem" << "\n";
        if (sortedStudentList.empty())
        {
            std::cout << "----------------     Khong co hoc sinh nao     ----------------\n";
        }
        sortedStudentList.sort();
        for (auto &student : sortedStudentList)
        {
            std::cout << std::setw(15) << student.GetId() << "|" << std::setw(40)
                      << student.GetName() << "|" << std::setw(5)
                      << student.GetAge() << "|" << std::setw(8)
                      << student.GetPoint() << "\n";
        }
    }
    else
    {
        std::cout << std::setw(15) << "Ma dinh danh" << "|" << std::setw(40)
                  << "Ten" << "|" << std::setw(5)
                  << "Tuoi" << "|" << std::setw(8)
                  << "Diem" << "\n";
        if (sortedStudentList.empty())
        {
            std::cout << "----------------     Khong co hoc sinh nao     ----------------\n";
        }
        sortedStudentList.sort(std::greater<Student>());
        for (auto &student : sortedStudentList)
        {
            std::cout << std::setw(15) << student.GetId() << "|" << std::setw(40)
                      << student.GetName() << "|" << std::setw(5)
                      << student.GetAge() << "|" << std::setw(8)
                      << student.GetPoint() << "\n";
        }
    }
    std::cout << "Bam phim bat ky de quay ve trang chinh";
    _getch();
}

void StudentManagement::ReadWrite()
{
    system("cls");
    std::string readString;
    std::cout << "Nhap dia chi file: ";
    getline(std::cin, readString);
    unsigned long long id;
    std::string name;
    int age;
    double point;
    std::ifstream file(readString, std::ifstream::in);
    while (!file.is_open())
    {
        std::cout << "Khong ton tai file." << std::endl;
        std::cout << "Bam esc de quay lai trang chinh hoac bam phim khac de tiep tuc";
        if (_getch() == 27)
        {
            return;
        }
        std::cout << "\nNhap ten file lai: ";
        getline(std::cin, readString);
        file.open(readString);
    }
    // Output
    std::ofstream oFile(fileDirectory, std::ofstream::out | std::ofstream::trunc);
    for (auto &student : studentList)
    {
        oFile << student.GetId() << "\n"
              << student.GetName() << "\n"
              << student.GetAge() << "\n"
              << student.GetPoint() << "\n";
    }
    for (auto &student : studentVector)
    {
        oFile << student.GetId() << "\n"
              << student.GetName() << "\n"
              << student.GetAge() << "\n"
              << student.GetPoint() << "\n";
    }
    oFile.close();
    studentVector.clear();
    studentList.clear();
    // Input
    this->fileDirectory = readString;
    std::stringstream buffer;
    buffer << file.rdbuf();
    while (getline(buffer, readString, '\n'))
    {
        id = std::stoull(readString);
        getline(buffer, name, '\n');
        getline(buffer, readString, '\n');
        age = std::stoi(readString);
        getline(buffer, readString, '\n');
        point = std::stod(readString);
        if (id % 2 == 0)
        {
            studentVector.push_back(Student(id, name, age, point));
        }
        else
        {
            studentList.push_back(Student(id, name, age, point));
        }
    }
    file.close();
    std::cout << "Doc thanh cong" << std::endl;
    std::cout << "Bam phim bat ky de quay ve trang chinh";
    _getch();
}