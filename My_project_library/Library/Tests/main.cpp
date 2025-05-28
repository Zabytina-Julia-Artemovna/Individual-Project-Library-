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
    Tvector<int> vector;
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
    size_t size = 10;
    Tvector<int> vector(size);
    bool expected_result = true;
    bool actual_result =
        vector.get_size() == size
        && vector.get_capacity() == 25
        && vector.get_data() != nullptr
        && vector.get_states() != nullptr
        && vector.get_deleted() == 0;
    return TestSystem::check(expected_result, actual_result);
}
bool test_3_constructor_with_array_and_size() {
    int data[3] = {1,2,3};
    size_t size = 3;
    Tvector<int> vector(data, size);
    bool expected_result = true;
    bool actual_result =
        vector.get_size() == size
        && vector.get_capacity() == 18
        && vector.get_data() != nullptr
        && vector.get_states() != nullptr
        && vector.get_data()[0] == data[0]
        && vector.get_data()[1] == data[1]
        && vector.get_data()[2] == data[2]
        && vector.get_deleted() == 0;
    return TestSystem::check(expected_result, actual_result);
}
bool test_4_copy_constructor() {
    int data[3] = { 1,2,3 };
    size_t size = 3;
    Tvector<int> old_vector (data, size);
    Tvector<int> new_vector(old_vector);
    bool expected_result = true;
    bool actual_result = old_vector == new_vector;
    return TestSystem::check(expected_result, actual_result);
}
bool test_5_is_empty() {
    Tvector<int> vector;
    bool expected_result = true;
    bool actual_result = vector.is_empty();
    return TestSystem::check(expected_result, actual_result);
}
bool test_6_get_data() {
    int data[3] = { 1,2,3 };
    size_t size = 3;
    Tvector<int> vector(data, size);
    int* data_ptr = data; 
    bool expected_result = true;
    bool different_pointers = data_ptr != vector.get_data();
    bool same_data = 
        data[0] == vector.get_data()[0]
        && data[1] == vector.get_data()[1]
        && data[2] == vector.get_data()[2];
    bool actual_result = different_pointers && same_data;
    return TestSystem::check(expected_result, actual_result);
}
bool test_7_front() {
    int data[3] = { 1,2,3 };
    size_t size = 3;
    Tvector<int> vector(data, size);
    bool expected_result = true;
    bool actual_result = vector.front() == vector.get_data()[0];
    return TestSystem::check(expected_result, actual_result);
}
bool test_8_back() {
    int data[3] = { 1,2,3 };
    size_t size = 3;
    Tvector<int> vector(data, size);
    bool expected_result = true;
    bool actual_result = vector.back() == vector.get_data()[vector.get_size() - 1];
    return TestSystem::check(expected_result, actual_result);
}

int main() {
    set_color(11, 0);
    std::cout << "TESTS FOR CLASS TVECTOR:" << std::endl;
    set_color(7, 0);
    TestSystem::start_test(test_1_default_constructor, " test_1_default_constructor");
    TestSystem::start_test(test_2_constructor_with_size, " test_2_constructor_with_size");
    TestSystem::start_test(test_3_constructor_with_array_and_size, " test_3_constructor_with_array_and_size");
    TestSystem::start_test(test_4_copy_constructor, " test_4_copy_constructor");
    TestSystem::start_test(test_5_is_empty, " test_5_is_empty");
    TestSystem::start_test(test_6_get_data, " test_6_get_data");
    TestSystem::start_test(test_7_front, " test_7_front");
    TestSystem::start_test(test_8_back, " test_8_back");


    TestSystem::print_final_info();
    system("pause");

    return 0;
}