# rule
$(BIN)/$(BINFILE): $(C) $(H) $(LC) $(YC)
	cmake         --preset linux
	cmake --build --preset linux -j

# $(BIN)/$(BINFILE): $(C) $(H) $(LC) $(YC)
# 	$(CXX) $(CFLAGS) -o $@ $(C) $(LC) $(YC) $(L)

$(LC): $(LL)
	$(foreach i,$?,flex  -o $(TMP)/$(subst  .lex,.lexer.cpp,$(notdir $(i))) $(i))
$(YC): $(YY)
	$(foreach i,$?,bison -o $(TMP)/$(subst .yacc,.parser.cpp,$(notdir $(i))) $(i))

.PHONY: src
src: $(LC) $(YC)
