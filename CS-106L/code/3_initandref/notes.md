Initialization
- Using auto,if u use auto properly,it will be much easier
- References
- If time: Const 

# Initialization: 
How we provide initial values to variables

# Uniform initialization:
curly
bracket initialization. Available
for all types, immediate
initialization on declaration!

```
int t{5};
vector<int> v{1,2,3};
```
# vector 2 inits
```
vector<int> v(3,5);
vector<int> v1{3,5};
```
# auto
// What types are these?
auto a = 3; // int
auto b = 4.3; // double
auto c = ‘X’; // char
auto d = “Hello”; // char* (a C string)
auto e = std::make_pair(3, “Hello”);
// std::pair<int, char*>

auto does not mean that the variable doesn't have a type,it means that the type is deduced by the compiler

# Structured Binding
```
auto [a,b] = std::make_pair(5,"dgh");
cout << a << endl;
```

# Reference: 
An alias
(another name) for a
named variable

## References to variables
```
vector<int> origin{1,2,3};
    vector<int> equal = origin;
    vector<int> &ref = origin;
    origin.push_back(9);
```
# l-values vs r-values
l-values can appear on the left of =
r-values can ONLY appear on the right of =
r-values can't be referenced

```
int& thisWontWork = 5; // This doesn't work!
```

# Const and Const References
```
const std::vector<int> c_vec{7, 8}; // a const variable
// BAD - can't declare non-const ref to const vector
std::vector<int>& bad_ref = c_vec;
```

























