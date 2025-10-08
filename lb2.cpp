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

    Point p1, p2;

    cout << "Точка 1:" << endl;
    p1.Read();

    cout << "Точка 2:" << endl;
    p2.Read();

    cout << "\nРезультати:" << endl;
    cout << "Точка 1: ";
    p1.Display();
    cout << "Точка 2: ";
    p2.Display();

    cout << "Рядкове представлення точки 1: " << p1.toString() << endl;

    cout << "Відстань від точки 1 до початку координат: " << p1.distanceToOrigin() << endl;
    cout << "Відстань між точкою 1 і точкою 2: " << p1.distanceTo(p2) << endl;

    double r, theta;
    p1.toPolar(r, theta);
    cout << "Полярні координати точки 1: r = " << r << ", θ = " << theta << " радіан" << endl;

    cout << "Точки " << (p1.isEqual(p2) ? "збігаються" : "не збігаються") << endl;

    p1.moveX(2.5);
    p1.moveY(-1.5);
    cout << "Точка 1 після переміщення: ";
    p1.Display();

    return 0;
}