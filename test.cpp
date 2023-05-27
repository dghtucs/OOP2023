#include <iostream>
using namespace std;
constexpr int square(int x) {
    return x + x;
}

int main() {
    constexpr int num = 5;
    constexpr int result = square(num); // 编译时计算 square(num)

    std::cout << "Result: " << result << std::endl; // 编译时已知结果，输出 "Result: 25"

    int i;
    cin >> i;
    int two = 2*i;
    cout << two << endl;
    //bianyishi
    return 0;
}
