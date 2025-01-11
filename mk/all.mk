.PHONY: all run
all: $(BIN)/$(MODULE) $(S)
run: $(BIN)/$(MODULE) $(S)
	$^
