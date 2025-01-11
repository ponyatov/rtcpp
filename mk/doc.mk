.PHONY: doxy
doxy: .doxygen doc/DoxygenLayout.xml doc/logo.png
	rm -rf doc/html ; doxygen $< 1>/dev/null

.PHONY: doc
doc: \
	$(DOC)/libc/Plauger_The_Standard_C_Library_1991.pdf \
	$(DOC)/cpp/Kormanyos_RealTime_Cpp.pdf
