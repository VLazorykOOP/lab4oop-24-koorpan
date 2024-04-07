#include <iostream>
using namespace std;
class Vector3D {
private:
    double x;
    double y;
    double z; 
       
public:
    enum State { NORMAL, ZERO_VECTOR };
    //конструктор без параметрів
    Vector3D() : x(0), y(0), z(0) {}
    // конструктор з одним параметром
    Vector3D(double x_val, double y_val, double z_val) : x(x_val), y(y_val), z(z_val) {}
    //деструктор
    ~Vector3D() {
        cout << "Об*єкт Vector3D знищено" << std::endl;
    } 
    //перевантаження операції присвоєння
    Vector3D& operator=(const Vector3D& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }
    //перевантаження арифметичних операцій
    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }
    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }
    Vector3D operator*(double scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }
    Vector3D operator/(double scalar) const {
        if (scalar != 0) {
            return Vector3D(x / scalar, y / scalar, z / scalar);
        }
        else {
            std::cerr << "Помилка: Дылення на нуль." << std::endl;
            return *this;
        }
    }
    Vector3D operator%(int divisor) const {
        if (divisor != 0) {
            return Vector3D(fmod(x, divisor), fmod(y, divisor), fmod(z, divisor));
        }
        else {
            std::cerr << "Помилка: Дылення на нуль." << std::endl;
            return *this;
        }
    }
    //перевантаження операцій порівняння
    bool operator==(const Vector3D& other) const {
        return (x == other.x && y == other.y && z == other.z);
    }
    bool operator!=(const Vector3D& other) const {
        return !(*this == other);
    } 
    //перевантаження функції виклику ()
    void operator()() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
    //перевантаження операцій порівняння
    bool operator>(const Vector3D& other) const {
        return (magnitude() > other.magnitude());
    }
    bool operator>=(const Vector3D& other) const {
        return (magnitude() >= other.magnitude());
    }
    bool operator<(const Vector3D& other) const {
        return (magnitude() < other.magnitude());
    }
    bool operator<=(const Vector3D& other) const {
        return (magnitude() <= other.magnitude());
    }
    //публічний метод для отримання модуля вектора
    double magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }
};
int main() {
    setlocale(LC_CTYPE, "Ukr");
    //стартові дані
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);
    //перевірка роботи
    Vector3D result1 = v1 + v2;
    Vector3D result2 = v1 - v2;
    Vector3D result3 = v1 * 2;
    Vector3D result4 = v1 / 2;
    Vector3D result5 = v1 % 2;
    //виведення про роботу деструктора(знищив результати)
    result1(); 
    result2();
    result3();
    result4();
    result5();
    return 0;
}




/*
#include <iostream>
#include <map>
#include <string>
using namespace std;
class AssociativeMap {
public:
    int getCodeError() const {
        return CodeError;
    }
private:
    map<int, string> data;
    int CodeError; //код помилки( 0 це немає помилки, 1 це немає відповідної сутності)
public:
    AssociativeMap() : CodeError(0) {}
    //додавання асоціативної сутності
    void add(int index, const string& entity) {
        data[index] = entity;
    }
    //операція індексації []
    string& operator[](int index) {
        if (data.find(index) != data.end()) {
            CodeError = 0; // запис, якщо нема помилк
            return data[index];
        }
        else {
            CodeError = 1; // запис, якщо є помилки
            static string emptyString; //повертаємо пустий рядок
            return emptyString;
        }
    }
    //перевантаження дружньої операції виведення <<
    friend ostream& operator<<(ostream& out, const AssociativeMap& am) {
        for (const auto& pair : am.data) {
            out << pair.first << ": " << pair.second << endl;
        }
        return out;
    }
    //перевантаження дружньої операції введення >>
    friend istream& operator>>(istream& in, AssociativeMap& am) {
        int index;
        string entity;
        cout << "Введіть індекс нового елементу масиву: ";
        in >> index;
        cout << "Введіть новий елемент масиву: ";
        cin.ignore(); // очищення буфера вводу, щоб уникнути впливу залишених символів нового рядка
        getline(in, entity); // зчитування всієї лінії, включаючи пробіли
        am.add(index, entity);
        return in;
    }

};

int main() {
    setlocale(LC_CTYPE, "Ukr");
    AssociativeMap am;
    //додавання асоціативних сутностей
    am.add(1, "Korpan Vitalii Igorovich");
    am.add(2, "Roshka Oleskandr Oleksandrovich");
    //використання операції індексації []
    cout << "Елемент за індексом 1: " << am[1] << endl; //виведення асоціативних сутностей, що зберігаються під індексами 
    cout << "Елемент за індексом 2: " << am[2] << endl; //1 та 2 
    cout << "Елемент за індексом 3: " << am[3];
    if (am.getCodeError() == 1) {
        cout << "Помилка: Елементу за таким індексом не знайдено" << endl;
    }
    else {
        cout << "Елемент за індексом 3: " << am[999] << endl;
    }
    //використання дружньої операції введення >>
    cin >> am;
    //виведення асоціативного масиву
    cout << "Асоціативний масив:" << endl;
    cout << am;
    return 0;
}
*/