#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t size;
    static int objectCount; 

public:
    String() : String(80) {}

    String(size_t s) {
        size = s;
        data = new char[size + 1];  
        data[0] = '\0';
        objectCount++;
    }

    String(const char* str) {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
        objectCount++;
    }

    ~String() {
        delete[] data;
        objectCount--;
    }

    void input() {
        std::cout << "Введите строку (макс " << size << " символов): ";
        std::cin.getline(data, size + 1);
    }

    void print() const {
        std::cout << "Строка: " << data << std::endl;
    }

    static int getObjectCount() {
        return objectCount;
    }
};

int String::objectCount = 0;

int main() {
    String s1;
    String s2(50);
    String s3("Пример строки");

    s1.input();
    s1.print();
    s2.input();
    s2.print();
    s3.print();

    std::cout << "Количество объектов String: " << String::getObjectCount() << std::endl;

    return 0;
}
