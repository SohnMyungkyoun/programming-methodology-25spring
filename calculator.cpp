#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    int max=std::numeric_limits<int>::max(); 
    int min=std::numeric_limits<int>::min();
    if (b>0 && a>max-b){
        throw std::overflow_error("Overflow");
    }
    else if (b<0 && a<min-b){
        throw std::overflow_error("Underflow");
    }
    return a+b;
}

int Calculator::sub(int a, int b) {
    int max=std::numeric_limits<int>::max(); 
    int min=std::numeric_limits<int>::min();
    if (b<0 && a>max+b){
        throw std::overflow_error("Overflow");
    }
    else if (b>0 && a<min+b){
        throw std::overflow_error("Underflow");
    }
    return a-b;
}

int Calculator::mul(int a, int b) {
    int max=std::numeric_limits<int>::max(); 
    int min=std::numeric_limits<int>::min();
    if (a>max/b){
        throw std::overflow_error("Overflow");
    }
    else if (a<min/b){
        throw std::overflow_error("Underflow");
    }
    return a*b;
}

int Calculator::div(int a, int b) {
    if (b==0){
        throw std::invalid_argument("Zero division");
    }
    else if (a==std::numeric_limits<int>::min() && b==-1){
        throw std::overflow_error("Overflow");
    }
    return a/b;
}