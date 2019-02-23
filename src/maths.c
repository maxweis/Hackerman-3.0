#include "maths.h"
#include <ctime>
#include <cstdlib>

void init_random() {
    std::srand(std::time(nullptr));
}

int random_int(int begin, int last) {
    int random = std::rand();
    return random % (last - begin + 1) + begin;
}
