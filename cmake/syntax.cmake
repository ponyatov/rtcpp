find_package(RAGEL REQUIRED)
find_package(FLEX  REQUIRED)
find_package(BISON REQUIRED)

# file(GLOB L CONFIGURE_DEPENDS ${SRC}/lib/cli/src/*.lex)
file(GLOB Y CONFIGURE_DEPENDS ${SRC}/lib/cli/src/*.yacc)

file(GLOB_RECURSE L ${SRC}/lib *.lex)
file(GLOB_RECURSE Y ${SRC}/lib *.yacc)

# 
# get_filename_component(yacc ${Y} NAME_WE)

foreach(lex ${L})
get_filename_component(lexer ${lex} NAME_WE)
message("--     lexer: " ${lexer} "\t:" ${lex})
FLEX_TARGET(${lexer} ${lex} ${TMP}/${lexer}.lexer.cpp)
list(APPEND C ${TMP}/${lexer}.lexer.cpp)
endforeach()

# message("-- lexer.cpp: " ${FLEX_lex_OUTPUTS})

# message("--    parser: " ${Y} "\t-> " ${yacc})

# BISON_TARGET(yacc ${Y} ${TMP}/${yacc}.parser.cpp
#           DEFINES_FILE ${TMP}/${yacc}.parser.hpp)
