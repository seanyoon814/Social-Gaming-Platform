add_executable(arithmeticTest testArithmetic.cpp)
target_link_libraries(arithmeticTest PUBLIC arythmTest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(arithmeticTest)