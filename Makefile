CFLAGS ?= -O2 -g

CFLAGS += -std=gnu99

CFLAGS += -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self \
	-Wswitch-default -Wpointer-arith -Wtype-limits -Wempty-body \
	-Wstrict-prototypes -Wold-style-declaration -Wold-style-definition \
	-Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs \
	-Wstack-usage=4096 -Wmissing-prototypes -Wfloat-equal -Wabsolute-value

CFLAGS += -fsanitize=undefined -fsanitize-undefined-trap-on-error

CC += -m32 -no-pie -fno-pie

LDLIBS = -lm

.PHONY: all clear

all: integral

integral: integral.o one.o
	$(CC) $(CFLAGS) -o $@ integral.o one.o $(LDLIBS)

integral.o: integral.c
	$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS)

NASM = nasm -f elf

one.o: one.asm
	$(NASM) $< -o $@


clear:
	rm -rf integral *.o
