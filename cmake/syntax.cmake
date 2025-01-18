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
#    COMPILE_FLAGS "-P ${lexer}_")
list(APPEND C ${TMP}/${lexer}.lexer.cpp)
endforeach()

foreach(yacc ${Y})
get_filename_component(parser ${yacc} NAME_WE)
message("--    parser: " ${parser} "\t:" ${yacc})
BISON_TARGET(${parser} ${yacc} ${TMP}/${parser}.parser.cpp
                  DEFINES_FILE ${TMP}/${parser}.parser.hpp)
#   COMPILE_FLAGS "-p ${parser}_")
# ADD_FLEX_BISON_DEPENDENCY(${parser} ${parser})
list(APPEND C ${TMP}/${parser}.parser.cpp)
endforeach()
