# rule
$(BIN)/$(BINFILE): $(C) $(H)
	cmake         --preset $(OS)
	cmake --build --preset $(OS) -j

# $(CP) $(HP)
$(TMP)/%.lexer.cpp: $(SRC)/%.lex
	flex -o $@ $<
$(TMP)/%.parser.cpp: $(SRC)/%.yacc
	bison -o $@ $<
