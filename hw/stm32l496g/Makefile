#!/usr/bin/make -f

# LDS = STM32L496AGIx_FLASH.ld
LDS = $(wildcard *.ld)

.PHONY: all
all: $(LDS).fix
$(LDS).fix: $(LDS)
	dos2unix *
	patch -u $(LDS) $(LDS).patch
	touch $@

.PHONY: x
x: $(LDS)
	echo $<
