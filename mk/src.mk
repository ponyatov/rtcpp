C += $(wildcard src/*.c*)
H += $(wildcard inc/*.h*)

S += $(wildcard lib/*.ini) $(wildcard lib/*.f)

C += $(wildcard   hw/$(HW)/src/*.c*)
H += $(wildcard   hw/$(HW)/inc/*.h*)
C += $(wildcard  cpu/$(CPU)/src/*.c*)
H += $(wildcard  cpu/$(CPU)/inc/*.h*)
C += $(wildcard arch/$(ARCH)/src/*.c*)
H += $(wildcard arch/$(ARCH)/inc/*.h*)
C += $(wildcard   os/$(OS)/src/*.c*)
H += $(wildcard   os/$(OS)/inc/*.h*)

H += $(shell find lib/* -type f -regex '.+\.hpp$$')
H += $(shell find lib/* -type f -regex '.+\.h$$')
C += $(shell find lib/* -type f -regex '.+\.cpp$$')
C += $(shell find lib/* -type f -regex '.+\.c$$')

LL = $(shell find $(SRC) $(LIB) -type f -regex '.+\.lex$$')
LC = $(foreach i,$(LP),$(TMP)/$(subst  .lex,.lexer.cpp,$(notdir $(i))))
YY = $(shell find $(SRC) $(LIB) -type f -regex '.+\.yacc$$')
YC = $(foreach i,$(YY),$(TMP)/$(subst .yacc,.parser.cpp,$(notdir $(i))))
