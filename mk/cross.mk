# HW ?= pc
# HW ?= retro
HW ?= arduino2560

include   hw/$(HW).mk
include  cpu/$(CPU).mk
include arch/$(ARCH).mk
include   os/$(OS).mk

CC      = $(TARGET)-gcc
CXX     = $(TARGET)-g++
LD      = $(TARGET)-ls
SIZE    = $(TARGET)-size
OBJDUMP = $(TARGET)-objdump
