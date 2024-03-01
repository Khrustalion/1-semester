/*
Реализоват функцию swap для произвольных типов данных без использования шаблонов
*/
#include <iostream>
#include <string>


// void swap(void* a, void* b, const size_t size) {
//     char* a_ = reinterpret_cast<char*>(a);
//     char* b_ = reinterpret_cast<char*>(b);
//     for (int i = 0; i < size; ++i) {
//         std::swap(a_[i], b_[i]);
//     }
// }

template<class T>
void swap(T & lhs, T & rhs) {
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

int main() {
    std::string a = "Hello ";
    std::string b = " world!";
    swap(a, b);
    std::cout << a << " " << b;
    return 0;
}