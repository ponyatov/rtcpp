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
    # CortexM/CubeMX
    "${CWD}/hw/${HW}/*.s"
)
file(GLOB_RECURSE C
    "${CWD}/src/*.c*"
    "${CWD}/hw/${HW}/src/*.c*"
    "${CWD}/os/${OS}/src/*.c*"
    "${CWD}/libc/*.c*"
    "${CWD}/rtos/*.c*"
    "${LIB}/led/src/*.c*"
    # CortexM/CubeMX
    "${CWD}/hw/${HW}/Core/Src/*.c*"
    "${CWD}/hw/${HW}/Drivers/CMSIS/Device/ST/${SERIES}xx/Source/*.c*"
    "${CWD}/hw/${HW}/Drivers/${SERIES}xx_HAL_Driver/Src/*.c*"
)
file(GLOB_RECURSE H
    "${CWD}/inc/*.h*"
    "${CWD}/hw/${HW}/inc/*.h*"
    "${CWD}/os/${OS}/inc/*.h*"
    "${CWD}/inc/libc/*.h*"
    "${CWD}/inc/rtos/*.h*"
    "${LIB}/led/inc/*.h*"
    # CortexM/CubeMX
    "${CWD}/hw/${HW}/Core/Inc/*.h*"
    "${CWD}/hw/${HW}/Drivers/CMSIS/Include/*.h*"
    "${CWD}/hw/${HW}/Drivers/CMSIS/Device/ST/${SERIES}xx/Include/*.h*"
    "${CWD}/hw/${HW}/Drivers/${SERIES}xx_HAL_Driver/Inc/*.h*"
)

include_directories(
    ${INC} ${TMP} ${SRC}
    "${CWD}/hw/${HW}/inc"
    "${CWD}/os/${OS}/inc"
    "${CWD}/inc/libc"
    "${CWD}/inc/rtos"
    "${LIB}/led/inc"
    # CortexM/CubeMX
    "${CWD}/hw/${HW}/Core/Inc"
    "${CWD}/hw/${HW}/Drivers/CMSIS/Include"
    "${CWD}/hw/${HW}/Drivers/CMSIS/Device/ST/${SERIES}xx/Include"
    "${CWD}/hw/${HW}/Drivers/${SERIES}xx_HAL_Driver/Inc"
)

message("-- toolchain: " ${CMAKE_CXX_COMPILER} " @ " ${CMAKE_TOOLCHAIN_FILE})
message("--    target: " "hw:" ${HW} " cpu:" ${CPU} "/" ${ARCH})
message("--        os: " ${OS})
message("--   startup: " ${A})
message("--    binary: " ${BIN_OUTPUT_NAME})

add_executable(${CMAKE_PROJECT_NAME}
    ${C} ${H} ${A} ${LD}
    ${FLEX_lex_OUTPUTS} ${BISON_yacc_OUTPUTS}
)

target_link_libraries(${CMAKE_PROJECT_NAME})

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES OUTPUT_NAME ${BIN_OUTPUT_NAME})
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})
# install(
#     PROGRAMS ${TMP}/${HW}/${CMAKE_PROJECT_NAME}.elf
#     DESTINATION ${CMAKE_INSTALL_PREFIX}
#     RENAME ${BIN_OUTPUT_NAME})

set(ELF ${CMAKE_INSTALL_PREFIX}/${BIN_OUTPUT_NAME}.elf)
set(DFU ${CMAKE_INSTALL_PREFIX}/${BIN_OUTPUT_NAME}.dfu)

add_custom_target(clean_all
    COMMAND rm -rf
        ${ELF} ${DFU}
        ${TMP}/${PROJECT_NAME}*
        ${CMAKE_BINARY_DIR}
)

add_custom_command(
    OUTPUT  ${DFU}
    DEPENDS ${ELF}
    COMMAND ../elf2dfuse/bin/elf2dfuse ${ELF} ${DFU}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
add_custom_target(dfu DEPENDS ${DFU})

add_custom_command(
    OUTPUT ${ELF}
    DEPENDS ${PROJECT_NAME}
)
add_custom_target(elf DEPENDS ${ELF})
