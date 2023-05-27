#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
    string name;
    int course;
    int id;

public:
    // Конструктор за замовчуванням
    Student() : name(""), course(0), id(0) {}

    // Конструктор з параметрами
    Student(string n, int c, int i) : name(n), course(c), id(i) {}

    // Деструктор
    ~Student() {
        cout << "Виклик деструктора для студента " << name << endl;
    }

    // Функція друку
    void print() {
        cout << "ПІБ: " << name << endl;
        cout << "Курс: " << course << endl;
        cout << "Ідентифікаційний номер: " << id << endl;
    }
};

class DiplomaStudent : public Student {
private:
    string thesis;

public:
    // Конструктор за замовчуванням
    DiplomaStudent() : Student(), thesis("") {}

    // Конструктор з параметрами
    DiplomaStudent(string n, int c, int i, string t) : Student(n, c, i), thesis(t) {}

    // Деструктор
    ~DiplomaStudent() {
        cout << "Виклик деструктора для студента-дипломника " << name << endl;
    }

    // Функція друку (перевизначення базової функції)
    void print() {
        cout << "ПІБ: " << name << endl;
        cout << "Курс: " << course << endl;
        cout << "Ідентифікаційний номер: " << id << endl;
        cout << "Тема диплома: " << thesis << endl;
    }

    // Функція перепризначення назви диплома
    void setThesis(string t) {
        thesis = t;
    }

    // Функція перепризначення ідентифікаційного номера
    void setId(int i) {
        id = i;
    }
};

int main() {
    // Створення об'єкту класу "Студент"
    Student student1("Іваненко Іван Іванович", 3, 123456);
    cout << "Інформація про студента:" << endl;
    student1.print();
    cout << endl;

    // Створення об'єкту класу "Студент-дипломник"
    DiplomaStudent diplomaStudent1("Петренко Петро Петрович", 4, 654321, "Тема диплома");
    cout << "Інформація про студента-дипломника:" << endl;
    diplomaStudent1.print();
    cout << endl;

    // Перепризначення назви диплома
    diplomaStudent1.setThesis("Нова тема диплома");
    cout << "Інформація про студента-дипломника після перепризначення назви диплома:" << endl;
    diplomaStudent1.print();
    cout << endl;

    // Перепризначення ідентифікаційного номера
    diplomaStudent1.setId(999999);
    cout << "Інформація про студента-дипломника після перепризначення ідентифікаційного номера:" << endl;
    diplomaStudent1.print();
    cout << endl;

    return 0;
}

