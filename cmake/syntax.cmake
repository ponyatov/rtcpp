find_package(RAGEL REQUIRED)
find_package(FLEX  REQUIRED)
find_package(BISON REQUIRED)

# file(GLOB L CONFIGURE_DEPENDS ${SRC}/lib/cli/src/*.lex)
file(GLOB Y CONFIGURE_DEPENDS ${SRC}/lib/cli/src/*.yacc)

file(GLOB_RECURSE L ${SRC}/lib *.lex)
file(GLOB_RECURSE Y ${SRC}/lib *.yacc)

# get_filename_component(lex  ${L} NAME_WE)
# get_filename_component(yacc ${Y} NAME_WE)

message("--     lexer: " ${L} "\t-> " ${lex})
message("--    parser: " ${Y} "\t-> " ${yacc})

#  FLEX_TARGET(lex  ${L} ${TMP}/${lex}.lexer.cpp)
# BISON_TARGET(yacc ${Y} ${TMP}/${yacc}.parser.cpp
#           DEFINES_FILE ${TMP}/${yacc}.parser.hpp)
