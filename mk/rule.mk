# rule
$(BIN)/$(BINFILE): $(C) $(H) $(CP) $(HP)
	cmake --preset         $(OS)
	cmake --build   $(TMP)/$(OS)
	cmake --install $(TMP)/$(OS)

$(TMP)/%.lexer.cpp: $(SRC)/%.lex
	flex -o $@ $<
$(TMP)/%.parser.cpp: $(SRC)/%.yacc
	bison -o $@ $<
