#include <fstream>
#include <iostream>
#include <locale.h>
#include <windows.h>
#include <string>
using namespace std;

class figure
{
protected:
    string name = "Фигура";
public:
    string getName()
    {
        return name;
    }
    virtual void printSides()
    {}
    virtual void printCorners()
    {}
};

class triangle: public figure
{ // ==========================================база 3угольника
    int aside = 0;
    int bside = 0;
    int cside = 0;

    int acorner = 0;
    int bcorner = 0;
    int ccorner = 0;
public:
    triangle(int aside_, int bside_, int cside_, int acorner_, int bcorner_, int ccorner_)
    {
        name = "Треугольник";
        aside = aside_;
        bside = bside_;
        cside = cside_;
        acorner = acorner_;
        bcorner = bcorner_;
        ccorner = ccorner_;
    }      
    void printSides()override
    {
        cout << "Стороны: " << " a = " << aside << " b = " << bside << " c = " << cside << endl;
    }
    void printCorners()override
    {
        cout << "Углы: " << " A = " << acorner << " B = " << bcorner << " C = " << ccorner << endl;
    }
};

class rightTriangle: public triangle
{
public:
    rightTriangle(int aside_, int bside_, int cside_, int acorner_, int bcorner_)
        :triangle(aside_, bside_, cside_, acorner_, bcorner_, 90)
    {
        triangle::name = "Прямоугольный треугольник";
    }
};

class isoscelesTriangle: public triangle
{
public: 
    isoscelesTriangle(int aside_, int bside_, int cside_, int acorner_, int bcorner_, int ccorner_)
        :triangle(aside_, bside_, cside_, acorner_, bcorner_, ccorner_)
    {
        triangle::name = "Равнобедренный треугольник";//а как равенство показать?
    }
};

class equilateralTriangle: public triangle
{
public:
    equilateralTriangle(int aside_, int bside_, int cside_, int acorner_, int bcorner_, int ccorner_)
        :triangle(aside_, bside_, cside_, 60, 60, 60)
    {
        triangle::name = "Равносторонний треугольник"; 
    }
};

class rectangle : public figure
{ // ==========================================база 4угольника
private:
    int aside = 0;
    int bside = 0;
    int cside = 0;
    int dside = 0;

    int acorner = 0;
    int bcorner = 0;
    int ccorner = 0;
    int dcorner = 0;
public:
    rectangle(int aside_, int bside_, int cside_, int dside_, int acorner_, int bcorner_, int ccorner_, int dcorner_)
    {
        name = "четырехугольник";
        aside = aside_;
        bside = bside_;
        cside = cside_;
        dside = dside_;
        acorner = acorner_;
        bcorner = bcorner_;
        ccorner = ccorner_;
        dcorner = dcorner_;
    }
    void printSides()override
    {
        cout << "Стороны: " << " a = " << aside << " b = " << bside << " c = " << cside << " d = " << dside << endl;
    }
    void printCorners()override
    {
        cout << "Углы: " << " A = " << acorner << " B = " << bcorner << " C = " << ccorner << " D = " << dcorner << endl;
    }
};

class rightCorner : public rectangle
{ 
public:
    rightCorner(int aside_, int bside_, int cside_, int dside_)
        :rectangle(aside_, bside_, cside_, dside_, 90, 90, 90, 90)
    {
        rectangle::name = "прямоугольник";
    }
};

class square : public rectangle
{
public:
    square(int aside_, int bside_, int cside_, int dside_)
        :rectangle(aside_, bside_, cside_, dside_, 90, 90, 90, 90)
    {
        rectangle::name = "квадрат";
    }
};

class parallelogram : public rectangle
{
public:
    parallelogram(int aside_, int bside_, int cside_, int dside_, int acorner_, int bcorner_, int ccorner_, int dcorner_)
        :rectangle(aside_, bside_, cside_, dside_, acorner_, bcorner_, ccorner_, dcorner_)
    {
        rectangle::name = "параллелограмм";
    }
};

class rhomb : public rectangle
{
public:
    rhomb(int aside_, int bside_, int cside_, int dside_, int acorner_, int bcorner_, int ccorner_, int dcorner_)
        :rectangle(aside_, bside_, cside_, dside_, acorner_, bcorner_, ccorner_, dcorner_)
    {
        rectangle::name = "ромб";
    }
};


void print_info(figure &f)
{
    cout << f.getName() << ": " << endl;

    f.printSides();
    f.printCorners();

    cout << endl;
}
int main()
{
    setlocale(0, "");
    SetConsoleCP(1251); //перевод на русский
    SetConsoleOutputCP(1251);

    triangle t1(10, 20, 30, 50, 60, 70);
    print_info(t1);
    rightTriangle t2(10, 20, 30, 50, 60);
    print_info(t2);
    isoscelesTriangle t3(10, 20, 10, 50, 60, 50);
    print_info(t3);
    equilateralTriangle t4(30, 30, 30, 60, 60, 60);
    print_info(t4);
    rectangle r1(10, 20, 30, 40, 50, 60, 70, 80);
    print_info(r1);
    rightCorner r2(10, 20, 10, 20);//не работает
    print_info(r2);
    square r3(20, 20, 20, 20);//не работает
    print_info(r3);
    parallelogram r4(20, 30, 20, 30, 30, 40, 30, 40);
    print_info(r4);
    rhomb r5(30, 30, 30, 30, 30, 40, 30, 40);
    print_info(r5);
}

