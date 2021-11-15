file(GLOB_RECURSE STACK_FILES *.cpp *.hpp)
add_custom_target(
    clang_format
    COMMAND clang-format -i ${STACK_FILES}
)