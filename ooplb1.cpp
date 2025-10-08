#include <iostream>
#include <Windows.h>
using namespace std;

struct Pair {
    double first;   
    double second;  

    bool Init(double a, double b) {
        if (a > b) {
            cout << "Помилка: ліва межа більша за праву!" << endl;
            return false;
        }
        first = a;
        second = b;
        return true;
    }

    void Read() {
        double a, b;
        cout << "Введіть ліву межу діапазону: ";
        cin >> a;
        cout << "Введіть праву межу діапазону: ";
        cin >> b;
        while (!Init(a, b)) {
            cout << "Повторіть введення!" << endl;
            cout << "Введіть ліву межу діапазону: ";
            cin >> a;
            cout << "Введіть праву межу діапазону: ";
            cin >> b;
        }
    }
    void Display() {
        cout << "Діапазон: [" << first << " ; " << second << "]" << endl;
    }

    void rangecheck(double x) {
        if (x >= first && x <= second)
            cout << x << " належить діапазону." << endl;
        else
            cout << x << " не належить діапазону." << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Pair r;
    r.Read();
    r.Display();

    double x;
    cout << "Введіть число для перевірки: ";
    cin >> x;

    r.rangecheck(x);

    return 0;
}
