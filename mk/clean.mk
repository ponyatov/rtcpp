clean:
	cmake --build --preset linux --target clean_all
	rm $(TMP)/*.lexer.* $(TMP)/*.parser.*
