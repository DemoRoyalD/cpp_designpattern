add_executable(abstract_factory_pattern_main abstract_factory_pattern_main.cpp)
add_subdirectory(fruit_factory)
add_subdirectory(computer_factory)
target_include_directories(abstract_factory_pattern_main PRIVATE fruit_factory)
target_include_directories(abstract_factory_pattern_main PRIVATE computer_factory)
target_link_libraries(abstract_factory_pattern_main PRIVATE fruit_factory)
target_link_libraries(abstract_factory_pattern_main PRIVATE computer_factory)

