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

    ~Point() {
    }

    void Init(double x_val, double y_val) {
        x = x_val;
        y = y_val;
    }

    void Read() {
        cout << "¬вед≥ть координату x: ";
        cin >> x;
        cout << "¬вед≥ть координату y: ";
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

    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) {
        return Point(x - other.x, y - other.y);
    }

    bool operator==(const Point& other) {
        return (x == other.x) && (y == other.y);
    }

    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    friend istream& operator>>(istream& is, Point& p) {
        cout << "¬вед≥ть x: ";
        is >> p.x;
        cout << "¬вед≥ть y: ";
        is >> p.y;
        return is;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Ukrainian");

    cout << "ƒемонстрац≥€ перевантажених операц≥й:" << endl;

    Point p1, p2, p3;

    cout << "¬вед≥ть точку p1:" << endl;
    cin >> p1;

    cout << "¬вед≥ть точку p2:" << endl;
    cin >> p2;

    cout << "–езультати:" << endl;
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    p3 = p1 + p2;
    cout << "p1 + p2 = " << p3 << endl;

    p3 = p1 - p2;
    cout << "p1 - p2 = " << p3 << endl;

    if (p1 == p2) {
        cout << "p1 == p2: точки зб≥гаютьс€" << endl;
    }
    else {
        cout << "p1 == p2: точки не зб≥гаютьс€" << endl;
    }

    Point p4;
    p4 = p1;
    cout << "ѕ≥сл€ p4 = p1: p4 = " << p4 << endl;

    Point p5 = p1 + p2 - p4;
    cout << "p1 + p2 - p4 = " << p5 << endl;

    return 0;
}