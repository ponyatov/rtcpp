CFLAGS += -I$(INC) -I$(TMP) -O0 -ggdb

CFLAGS += -I$(CWD)/hw/$(HW)/inc
CFLAGS += -I$(CWD)/cpu/$(CPU)/inc
CFLAGS += -I$(CWD)/arch/$(ARCH)/inc
CFLAGS += -I$(CWD)/os/$(OS)/inc
CFLAGS += -I$(CWD)/lib/led/inc
