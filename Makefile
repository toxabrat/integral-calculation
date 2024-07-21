CFLAGS ?= -O2 -g

CFLAGS += -std=gnu99

CFLAGS += -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self \
	-Wswitch-default -Wpointer-arith -Wtype-limits -Wempty-body \
	-Wstrict-prototypes -Wold-style-declaration -Wold-style-definition \
	-Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs \
	-Wstack-usage=4096 -Wmissing-prototypes -Wfloat-equal -Wabsolute-value

CFLAGS += -fsanitize=undefined -fsanitize-undefined-trap-on-error

CC += -m32 -no-pie -fno-pie #-m32 - генерирует 32 битный код  -no-pie - позиционно не зависимый код на этапе линковки
# -fno-pie - позиционно не зависимы код на этапе компиляции

LDLIBS = -lm # -lm - линковка математической библиотеки

.PHONY: all

all: integral

integral: counting_functions.o Source/main.c Source/math_operation.c Source/ArgParse.c 
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS) 

test: Source/test_functions.c Source/math_operation.c Source/test_main.c 
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS) 
	@./test
	@rm test

counting_functions.o: Source/counting_functions.asm
	nasm -f elf32 -o $@ $<

# $@ - подставляет текущую цель $^ - подставляет все параметры $< - подставляет первый параметр
# -f -elf32 - показывает формат выходного файла (формат 32 битный ELF)

.PHONY: clean
clean:
	@rm -rf *.o integral test