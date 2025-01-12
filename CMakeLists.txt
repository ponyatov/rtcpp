# "CMAKE_VERBOSE_MAKEFILE": true
cmake_minimum_required(VERSION 3.22)
get_filename_component(PROJECT_NAME ${CMAKE_SOURCE_DIR} NAME_WE)
project(${PROJECT_NAME} LANGUAGES C CXX ASM)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
include(version)

set(CWD ${CMAKE_SOURCE_DIR})
set(BIN ${CWD}/bin)
set(DOC ${CWD}/doc)
set(LIB ${CWD}/lib)
set(INC ${CWD}/inc)
set(SRC ${CWD}/src)
set(TMP ${CWD}/tmp)

file(GLOB_RECURSE LD
    "${CWD}/hw/${HW}/*.ld"
)
file(GLOB_RECURSE A
    "${CWD}/src/*.s*"
    "${CWD}/hw/${HW}/*.s"
)
file(GLOB_RECURSE C
    "${CWD}/src/*.c*"
    "${CWD}/hw/${HW}/src/*.c*"
    "${CWD}/os/${OS}/src/*.c*"
    "${CWD}/libc/*.c*"
    "${CWD}/rtos/*.c*"
    "${LIB}/led/src/*.c*"
)
file(GLOB_RECURSE H
    "${CWD}/inc/*.h*"
    "${CWD}/hw/${HW}/inc/*.h*"
    "${CWD}/os/${OS}/inc/*.h*"
    "${CWD}/inc/libc/*.h*"
    "${CWD}/inc/rtos/*.h*"
    "${LIB}/led/inc/*.h*"
)

include_directories(
    ${INC} ${TMP} ${SRC}
    "${CWD}/hw/${HW}/inc"
    "${CWD}/os/${OS}/inc"
    "${CWD}/inc/libc"
    "${CWD}/inc/rtos"
    "${LIB}/led/inc"
)

find_package(FLEX  REQUIRED)
find_package(BISON REQUIRED)

file(GLOB L CONFIGURE_DEPENDS ${SRC}/*.lex)
file(GLOB Y CONFIGURE_DEPENDS ${SRC}/*.yacc)
get_filename_component(lex  ${L} NAME_WE)
get_filename_component(yacc ${Y} NAME_WE)
 FLEX_TARGET(lex  ${L} ${TMP}/${lex}.lexer.cpp)
BISON_TARGET(yacc ${Y} ${TMP}/${yacc}.parser.cpp
          DEFINES_FILE ${TMP}/${yacc}.parser.hpp)

message("-- toolchain: " ${CMAKE_CXX_COMPILER} " @ " ${CMAKE_TOOLCHAIN_FILE})
message("--  hardware: " ${HW} "/" ${CPU} "/" ${ARCH})
message("--        os: " ${OS})
message("--   startup: " ${A})
message("--    binary: " ${BIN_OUTPUT_NAME})

add_executable(${CMAKE_PROJECT_NAME}
    ${C} ${H} ${A} ${LD}
    ${FLEX_lex_OUTPUTS} ${BISON_yacc_OUTPUTS}
)

target_link_libraries(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${BIN_OUTPUT_NAME})
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})
# install(
#     PROGRAMS ${TMP}/${HW}/${CMAKE_PROJECT_NAME}.elf
#     DESTINATION ${CMAKE_INSTALL_PREFIX}
#     RENAME ${BIN_OUTPUT_NAME})

add_custom_target(clean_all
    COMMAND ${CMAKE_BUILD_TOOL} clean
)
