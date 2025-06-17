#pragma once

#include <cstdint>
#include <iostream>

class Core {

public:

    explicit Core(const uint8_t x) : internal_val(x) {};

    ~Core() = default;

    void initialize_core() {
        std::cout << "Core initialized!" << std::endl;
    };

private:
    bool init_flag;
    uint8_t internal_val;
};
