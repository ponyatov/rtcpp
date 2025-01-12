find_package(FLEX  REQUIRED)
find_package(BISON REQUIRED)

file(GLOB L CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.lex)
file(GLOB Y CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.yacc)
get_filename_component(lex  ${L} NAME_WE)
get_filename_component(yacc ${Y} NAME_WE)
 FLEX_TARGET(lex  ${L} ${CMAKE_SOURCE_DIR}/tmp/${lex}.lexer.cpp)
BISON_TARGET(yacc ${Y} ${CMAKE_SOURCE_DIR}/tmp/${yacc}.parser.cpp
          DEFINES_FILE ${CMAKE_SOURCE_DIR}/tmp/${yacc}.parser.hpp)

# add_executable(${CMAKE_PROJECT_NAME}
#     ${FLEX_lex_OUTPUTS} ${BISON_yacc_OUTPUTS}
# )
