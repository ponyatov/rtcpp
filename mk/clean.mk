clean:
	cmake --build --preset $(OS) --target clean
	rm -rf $(BIN)/$(BINFILE) $(BIN)/$(OS) $(TMP)/$(OS) $(TMP)/$(MODULE)*
