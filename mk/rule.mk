# rule
# $(BIN)/$(BINFILE): $(C) $(H)
# 	cmake         --preset $(OS)
# 	cmake --build --preset $(OS) -j

$(BIN)/$(BINFILE): $(C) $(H) $(CP) $(HP)
	$(CXX) $(CFLAGS) -o $@ $(C) $(CP) $(L)
$(TMP)/%.lexer.cpp: $(SRC)/%.lex
	flex -o $@ $<
$(TMP)/%.parser.cpp: $(SRC)/%.yacc
	bison -o $@ $<
