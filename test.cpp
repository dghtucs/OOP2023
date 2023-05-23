// #include <iostream>
#include <iosfwd>

// 前置声明，无需包含完整的头文件
class MyClass;

// 使用前置声明的函数
void printValue(const MyClass& obj);

// 定义 MyClass 类
class MyClass {
public:
    MyClass(int value) : value_(value) {}

private:
    int value_;

    // 友元函数，需要访问 MyClass 的私有成员
    friend void printValue(const MyClass& obj);
};

// 使用完整的 MyClass 定义的函数
void printValue(const MyClass& obj) {
    std::cout << "Value: " << obj.value_ << std::endl;
}

int main() {
    MyClass obj(42);
    printValue(obj);

    return 0;
}
