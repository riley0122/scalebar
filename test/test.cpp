#include "test_lib.hpp"

bool test() {
    return 1 + 1 == 2;
}

int main() {
    return run_tests({
        test()
    }, {
        "Test if maths are being done correctly."
    });
}
