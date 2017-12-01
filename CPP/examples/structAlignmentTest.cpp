#include <iostream>
#include <cstdint>

struct X {
    int8_t a;
    int64_t b;
    int8_t c;
    int16_t d;
    int64_t e;
    float f;
};

struct Y {
    int8_t a, pad_a[7];
    int64_t b;
    int8_t c, pad_c[1];
    int16_t d, pad_d[2];
    int64_t e;
    float f, pad_f[1];
};

struct Z {
    int64_t b;
    int64_t e;
    float f;
    int16_t d;
    int8_t a;
    int8_t c;
};

int main(){

  std::cout << "X size: " << sizeof(X) << std::endl;
  std::cout << "Y size: " << sizeof(Y) << std::endl;
  std::cout << "Z size: " << sizeof(Z) << std::endl;

  return 0;
}
