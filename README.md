# ShmoLALib
This lightweight and free header-based library contains several types and utility functions used for linear algebra. The library is intended to be used in computer-graphics contexts and projects. All you need to get started is the contents of the "include" directory.

## Dependencies
Requires code to be compiled for C++20 (for use of the `std::format()` function. Feel free to not include or modify `string_utils.hpp` if you want to use earlier versions of C++).

## Example Usage
```cpp
#include <shmo/math.hpp>

void main() 
{
  using shmo::math::vec2;
  vec2 v1 = { 2, 4 };
  vec2 v2 = { 3.5, 14 };
  vec2 v3 = v1 + v2;
  
  std::cout << "The value of my vector is: " << v3 << '\n'; 
  // OUTPUT: The value of my vector is: ( 5.50000 18.0000 ) 
}
```
