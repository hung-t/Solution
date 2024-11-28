#include <iostream>
#include "Student.hpp"
#include "App.cpp"
#include "StudentManagement.hpp"
using namespace std;
int main()
{
    try
    {
        StudentManagement studentManagement;
        App app(studentManagement);
        app.Main();
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
        std::cout << "\nBam phim bat ky de thoat";
        _getch();
    }
    return 0;
}
