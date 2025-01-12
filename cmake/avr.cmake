# host compiler
set(CMAKE_SYSTEM_NAME AVR)
set(CMAKE_BUILD_TYPE  Debug)
set(TOOLCHAIN_PREFIX  avr)

include(cmake/any_toolchain.cmake)

add_definitions(
    # "PC", "I5", "AVR", "BARE"
)
