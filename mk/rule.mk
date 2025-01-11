# rule
$(BIN)/$(BINFILE): $(C) $(H) $(CP) $(HP)
	cmake         --preset $(OS)
	cmake --build --preset $(OS) -j

$(TMP)/%.lexer.cpp: $(SRC)/%.lex
	flex -o $@ $<
$(TMP)/%.parser.cpp: $(SRC)/%.yacc
	bison -o $@ $<
