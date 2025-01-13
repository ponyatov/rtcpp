#!/usr/bin/make -f

PATCH = $(wildcard *.patch)
FILES = $(subst .patch,,$(PATCH))

.PHONY: all
all: $(LDS).fix
$(LDS).fix: $(LDS)
	dos2unix *
	$(MAKE) -f $(MAKEFILE_LIST) $(FILES)

%.fix: %
	patch -u $< $<.patch
	touch $@
