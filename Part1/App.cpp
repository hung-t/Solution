#pragma once

#include "StudentManagement.hpp"
#include "Student.hpp"
class App
{
private:
    StudentManagement *_studentManagement;

public:
    App(StudentManagement &studentManagement);
    void Main();
};

App::App(StudentManagement &studentManagement)
{
    _studentManagement = &studentManagement;
}

void App::Main()
{
    system("cls");
    std::cout << "************************************************************" << std::endl;
    std::cout << "*            Chao mung den voi quan ly sinh vien           *" << std::endl;
    std::cout << "* Vui long bam cac phim so tu 1 - 7 de thuc hien yeu cau   *" << std::endl;
    std::cout << "* Hoac bam phim khac de thoat chuong trinh                 *" << std::endl;
    std::cout << "* 1. Xuat ra cac thong tin sinh vien                       *" << std::endl;
    std::cout << "* 2. Tim kiem sinh vien                                    *" << std::endl;
    std::cout << "* 3. Them sinh vien                                        *" << std::endl;
    std::cout << "* 4. Xoa sinh vien                                         *" << std::endl;
    std::cout << "* 5. Sua sinh vien                                         *" << std::endl;
    std::cout << "* 6. Sap xep va xuat thong tin sinh vien                   *" << std::endl;
    std::cout << "* 7. Cau hinh co so du lieu                                *" << std::endl;
    std::cout << "*                                                          *" << std::endl;
    std::cout << "************************************************************" << std::endl;
    switch (_getch())
    {
    case '1':
        _studentManagement->ShowListStudent();
        Main();
        break;
    case '2':
        _studentManagement->Search();
        Main();
        break;
    case '3':
        _studentManagement->Add();
        Main();
        break;
    case '4':
        _studentManagement->Delete();
        Main();
        break;
    case '5':
        _studentManagement->Modify();
        Main();
        break;
    case '6':
        _studentManagement->ShowSortedStudentList();
        Main();
        break;
    case '7':
        _studentManagement->setConnectionString();
        Main();
        break;
    default:
        std::cout << "Thoat chuong trinh\n\n\n\n";
        break;
    }
}