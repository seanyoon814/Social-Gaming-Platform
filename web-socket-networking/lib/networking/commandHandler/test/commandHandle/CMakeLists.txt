add_executable(commandHandleTest testcommand.cpp)
target_link_libraries(commandHandleTest PUBLIC commandHandle GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(commandHandleTest)