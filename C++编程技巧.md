
# 预处理器类

## 运行速度
`#pragma GCC optimize("O3,unroll-loops")`
这是编译器指令，告诉GCC编译器使用最大优化级别(O3)和循环展开(unroll-loops)进行编译，以提高程序的运行速度
例如：

```cpp
#pragma GCC optimize("Ofast")
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    for(int i = 0; i < 5; i++){
        sum += arr[i];
    }
    cout << "The sum is " << sum << endl;
    return 0;
}
```
这会告诉编译器尽可能地优化代码以提高运行速度，有时候甚至会牺牲浮点数的精度。这里的程序是计算一个整型数组的所有元素的和，然后输出。

如果我们将其与没有优化指令的版本比较，可能会在大型数据集或者复杂的计算中看到明显的运行速度的差异。不过在小型程序和简单的计算中，可能看不出明显的区别。

## 指定CPU指令集
`#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")`
：这个编译器指令指定编译目标的特性，例如avx2，bmi，bmi2，lzcnt，popcnt等都是特定的CPU指令集。这些指令能够提升一些特定运算的效率。
ex:
```c
#pragma GCC target("sse4.2")
```
在这个例子中，#pragma GCC target("sse4.2")告诉GCC编译器生成的代码应当优化以利用SSE4.2指令集。SSE4.2是一种在现代x86处理器上用来加速某些类型的计算的指令集。

需要注意的是，如果你的程序运行的处理器不支持这些指令集，那么这个指令就可能会导致程序运行出错。因此，在使用这个指令时，你需要确保你的程序将要运行在支持这些指令集的处理器上。


















































