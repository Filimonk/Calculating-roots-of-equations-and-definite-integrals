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

area: area.o f.o df.o root.o integral.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

area.o: src/area.c
	$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS)

root.o: src/root.c
	$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS)

integral.o: src/integral.c
	$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS)


NASM = nasm -f elf

f.o: src/f.asm
	$(NASM) $< -o $@

df.o: src/df.asm
	$(NASM) $< -o $@


test: test.o root.o integral.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

test.o: tests/test.c
	$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS)


clear:
	rm -rf area root integral test *.o
