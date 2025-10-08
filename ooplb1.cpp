#include <iostream>
#include <Windows.h>
using namespace std;

struct Pair {
    double first;   
    double second;  

    bool Init(double a, double b) {
        if (a > b) {
            cout << "�������: ��� ���� ����� �� �����!" << endl;
            return false;
        }
        first = a;
        second = b;
        return true;
    }

    void Read() {
        double a, b;
        cout << "������ ��� ���� ��������: ";
        cin >> a;
        cout << "������ ����� ���� ��������: ";
        cin >> b;
        while (!Init(a, b)) {
            cout << "�������� ��������!" << endl;
            cout << "������ ��� ���� ��������: ";
            cin >> a;
            cout << "������ ����� ���� ��������: ";
            cin >> b;
        }
    }
    void Display() {
        cout << "ĳ������: [" << first << " ; " << second << "]" << endl;
    }

    void rangecheck(double x) {
        if (x >= first && x <= second)
            cout << x << " �������� ��������." << endl;
        else
            cout << x << " �� �������� ��������." << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Pair r;
    r.Read();
    r.Display();

    double x;
    cout << "������ ����� ��� ��������: ";
    cin >> x;

    r.rangecheck(x);

    return 0;
}
