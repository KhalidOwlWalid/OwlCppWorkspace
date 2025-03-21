#include <iostream>
#include "utils/logger.hpp"

void say_hello(){
    std::cout << "Hello, from example!\n";
}

int main() {
    say_hello();
    LOG("Inside log");
    return 0;
}
