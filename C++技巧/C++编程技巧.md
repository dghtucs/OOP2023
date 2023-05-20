
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


## IO
`#define fast ios::sync_with_stdio(false); cin.tie(0);`
：这是一个用于提高C++的输入/输出效率的宏

这行代码定义了一个预处理器宏，名为fast。这个宏涉及两个C++的输入/输出流库(iostream库)的特性，其目的是提升C++的输入/输出速度。

`ios::sync_with_stdio(false);`

这个调用会取消C++中的cin和stdout的同步。默认情况下，C++的cin和cout总是和C的stdin和stdout同步的，这种同步会使得C++的输入/输出操作有一些额外的开销。当我们知道在程序中不会同时使用C和C++的输入/输出操作时，可以关闭这种同步，以提高效率。

`cin.tie(0);`

这个调用将cin和cout的绑定取消。默认情况下，cin和cout是绑定在一起的，这意味着每次在用cin读取输入之前，都会先刷新cout的缓冲区，以保证在读取输入之前，所有待输出的内容都已经输出了。当我们知道在程序中不需要这种严格的输入/输出顺序时，可以取消这种绑定，以提高效率。

当你在代码中写fast;，预处理器会将其替换为ios::sync_with_stdio(false); cin.tie(0);。这种方式使得你在任何需要快速输入/输出的场景下，都可以简单地写fast;，而不是写完整的两行代码。

然后你可能会问，为什么fast后面还要跟一个分号？这是因为宏替换只是简单的文本替换，预处理器不会自动为你在宏替换后的代码添加分号。因此，你需要在使用fast时，像正常的C++语句一样在其后添加分号。

例如，你在代码中写fast;，预处理器替换后的代码将变为：

`ios::sync_with_stdio(false); cin.tie(0);;`
虽然这里看起来有两个连续的分号，但这并不会影响代码的正确性，因为C++允许空语句，即一个单独的分号。

## 循环
up
`#define foru(i, k, n) for (int i = k; i < n; i++)`
：这是一个用于简化代码的宏，用于创建从k开始，到n结束的for循环。
dowm
`#define ford(i, k, n) for (int i = k; i >= n; i--)`
：同样是一个用于简化代码的宏，用于创建从k开始，到n结束的倒序for循环。

这行代码的意思是，每当你在代码中写 foru(i, k, n)，预处理器都会在编译代码之前，将其替换为 for (int i = k; i < n; i++)。这种方式可以简化代码，并提高代码的可读性。

宏 foru(i, k, n) 的参数是 i（循环变量的名称），k（循环的起始值），和 n（循环的终止值）。循环变量 i 的初始值是 k，并在每次迭代后递增1，直到达到 n 时循环结束。请注意，这个 for 循环是半开区间的，即包括起始值 k，但不包括终止值 n。
ex:
```c
foru(i, 0, 5) {
    cout << i << " ";
}
```

## typedef
`typedef long long ll;` 
`typedef unsigned long long ull;` 
这些都是类型别名，为了编程方便和简洁。

```c
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
```

如果你有一个复杂的嵌套数据类型，如
`std::map<std::string, std::vector<std::pair<int, int>>>`
，那么你可能会希望为这个类型创建一个更简洁的别名。使用typedef，你可以这样做：
```cpp
typedef std::map<std::string, std::vector<std::pair<int, int>>> MyComplexType;

MyComplexType myMap;

```


再来聊聊为什么#define后面不加分号，typedef后面加分号

#define是C和C++预处理器指令，用于定义宏，而typedef是C和C++关键字，用于定义类型别名。这两者在语法上有所不同。

#define：在C和C++中，预处理器将在编译过程开始之前处理所有的预处理器指令。#define就是一种预处理器指令，用于定义宏。预处理器会在编译过程开始之前替换所有宏定义。由于这些替换是在编译阶段之前完成的，因此#define不遵循C++的语法规则，不需要加分号。

typedef：在C和C++中，typedef是一个关键字，用于为类型定义别名。由于typedef是在编译阶段处理的，因此它必须遵循C++的语法规则，也就是说，必须在声明后面添加分号。

这就是为什么#define后面不加分号，而typedef后面要加分号的原因。

























