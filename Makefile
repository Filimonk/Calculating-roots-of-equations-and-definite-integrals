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

all: area

area: area.o f1.o f2.o f3.o df1.o df2.o df3.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

area.o: area.c
	$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS)


NASM = nasm -f elf

f1.o: f1.asm
	$(NASM) $< -o $@

f2.o: f2.asm
	$(NASM) $< -o $@

f3.o: f3.asm
	$(NASM) $< -o $@


df1.o: df1.asm
	$(NASM) $< -o $@

df2.o: df2.asm
	$(NASM) $< -o $@

df3.o: df3.asm
	$(NASM) $< -o $@



clear:
	rm -rf integral *.o
