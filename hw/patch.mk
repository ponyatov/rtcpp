#!/usr/bin/make -f

PATCH = $(wildcard *.patch)
FILES = $(subst .patch,,$(PATCH))
FIXES = $(subst .patch,.fix,$(PATCH))

.PHONY: all
all: $(FIXES)
%.fix: %
	dos2unix $<
	patch -u $< $<.patch
	touch $@
