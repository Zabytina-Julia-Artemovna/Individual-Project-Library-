#include <iostream>
#include <Windows.h>
#include "../Include/tvector.h"
void set_color(int text_color, int bg_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bg_color << 4) | text_color);
}
namespace TestSystem {
    int count_success = 0, count_failed = 0;

    void start_test(bool(*test)(), const char* name_of_test) {
        set_color(2, 0);
        std::cout << "[ RUN      ]";
        set_color(7, 0);
        std::cout << name_of_test << std::endl;
        bool status = test();
        if (status == true) {
            set_color(2, 0);
            std::cout << "[       OK ]" << std::endl;
            count_success++;
        }
        else {
            set_color(4, 0);
            std::cout << "[  FAILED  ]" << std::endl;
            count_failed++;
        }
        set_color(7, 0);
    }

    template <class T>
    bool check(const T& expected, const T& actual) {
        if (expected == actual) {
            return true;
        }
        else {
            std::cerr << "Expected result is " << expected << " but actual is " << actual << std::endl;
            return false;
        }
    }

    void print_final_info() {
        set_color(2, 0);
        std::cout << "[==========] ";
        set_color(7, 0);
        std::cout << count_success + count_failed << " test" << (count_success + count_failed > 1 ? "s" : "") << " ran." << std::endl;
        set_color(2, 0);
        std::cout << "[  PASSED  ] ";
        set_color(7, 0);
        std::cout << count_success << " test" << (count_success > 1 ? "s" : "") << std::endl;
        if (count_failed > 0) {
            set_color(4, 0);
            std::cout << "[  FAILED  ] ";
            set_color(7, 0);
            std::cout << count_failed << " test" << (count_failed > 1 ? "s." : ".") << std::endl;
        }
    }
};
bool test_1_default_constructor() {
    Tvector<int> vector{};
    bool expected_result = true;
    bool actual_result =
        vector.get_size() == 0
        && vector.get_deleted() == 0
        && vector.get_capacity() == 0
        && vector.get_data() == nullptr
        && vector.get_states() == nullptr;
    return TestSystem::check(expected_result, actual_result);
}
bool test_2_constructor_with_size() {
    Tvector<int> vector(10);
    bool expected_result = true;
    bool actual_result =
        vector.get_size() == 10
        && vector.get_capacity() == 25;
    return TestSystem::check(expected_result, actual_result);
}

int main() {
    set_color(11, 0);
    std::cout << "TESTS FOR CLASS TVECTOR:" << std::endl;
    set_color(7, 0);
    TestSystem::start_test(test_1_default_constructor, " test_1_default_constructor");
    TestSystem::start_test(test_2_constructor_with_size, " test_2_constructor_with_size");

    TestSystem::print_final_info();
    system("pause");

    return 0;
}