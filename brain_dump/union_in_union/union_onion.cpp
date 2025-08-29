#include <spdlog/spdlog.h>

struct Vector2 {
    union {
        struct {
            union {
                float x;
                float width;
            };
            union {
                float y;
                float height;
            };

        };
        float coordinate[2];
    };

    // TODO (Khalid): Do assertions that it is a reasonable type
    // template<typename T>
    inline Vector2(const double p_x, const double p_y) {
        coordinate[0] = p_x;
        coordinate[1] = p_y;
    };

    inline void print_info() {
        spdlog::info("test.x, {}; test.width, {}; test.coordinate[0], {}", x, width, coordinate[0]);
        spdlog::info("test.y, {}; test.height, {}; test.coordinate[1], {}", y, height, coordinate[1]);
    }

};

int main() {
    Vector2 vec(1, 2);
    vec.print_info();

    vec.coordinate[0] = 10;
    vec.coordinate[1] = 11;
    vec.print_info();

    return  0;
}