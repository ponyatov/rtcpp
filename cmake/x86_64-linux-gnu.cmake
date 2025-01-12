# host compiler
set(CMAKE_SYSTEM_NAME Linux)
set(TOOLCHAIN_PREFIX  ${ARCH}-${OS}-gnu)

include(cmake/any_toolchain.cmake)

add_definitions(
    # "PC", "I5", "X86_64", "LINUX"
)
