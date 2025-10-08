#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <windows.h>

using namespace std;

class Point {
private:
    double x, y;

public:
    Point() {
        x = 0.0;
        y = 0.0;
    }

 
    Point(double x_val, double y_val) {
        x = x_val;
        y = y_val;
    }

    Point(const Point& other) {
        x = other.x;
        y = other.y;
    }

    Point() {
        cout << "Об'єкт Point знищено" << endl;
    }

    void Init(double x_val, double y_val) {
        x = x_val;
        y = y_val;
    }

    void Read() {
        cout << "Введіть координату x: ";
        cin >> x;
        cout << "Введіть координату y: ";
        cin >> y;
    }

    void Display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    string toString() {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }

    void moveX(double dx) {
        x += dx;
    }

    void moveY(double dy) {
        y += dy;
    }

    double distanceToOrigin() {
        return sqrt(x * x + y * y);
    }

    double distanceTo(Point other) {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    void toPolar(double& r, double& theta) {
        r = distanceToOrigin();
        theta = atan2(y, x);
    }

    bool isEqual(Point other) {
        return (x == other.x) && (y == other.y);
    }

    bool isNotEqual(Point other) {
        return !isEqual(other);
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Ukrainian");

    
    cout << "Демонстрація конструкторів:" << endl;

    Point p1;
    cout << "Точка 1 (за замовчуванням): ";
    p1.Display();

    
    Point p2(3.0, 4.0);
    cout << "Точка 2 (з параметрами): ";
    p2.Display();

    Point p3(p2);
    cout << "Точка 3 (копія точки 2): ";
    p3.Display();

    cout << "\nРобота з методами:" << endl;

    Point p4, p5;

    cout << "Точка 4:" << endl;
    p4.Read();

    cout << "Точка 5:" << endl;
    p5.Read();

    cout << "\nРезультати:" << endl;
    cout << "Точка 4: ";
    p4.Display();
    cout << "Точка 5: ";
    p5.Display();

    cout << "Рядкове представлення точки 4: " << p4.toString() << endl;

    cout << "Відстань від точки 4 до початку координат: " << p4.distanceToOrigin() << endl;
    cout << "Відстань між точкою 4 і точкою 5: " << p4.distanceTo(p5) << endl;

    double r, theta;
    p4.toPolar(r, theta);
    cout << "Полярні координати точки 4: r = " << r << ", θ = " << theta << " радіан" << endl;

    cout << "Точки " << (p4.isEqual(p5) ? "збігаються" : "не збігаються") << endl;

    p4.moveX(2.5);
    p4.moveY(-1.5);
    cout << "Точка 4 після переміщення: ";
    p4.Display();

    return 0;
}