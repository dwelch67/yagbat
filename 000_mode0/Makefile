
CROSS_COMPILE ?= arm-none-eabi

AOPS = --warn --fatal-warnings 
COPS = -mcpu=arm7tdmi -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding 

all : notmain.gba

startup.o : startup.s
	$(CROSS_COMPILE)-as $(AOPS) startup.s -o startup.o

notmain.o : notmain.c
	$(CROSS_COMPILE)-gcc -c $(COPS) notmain.c -o notmain.o

notmain.gba : notmain.mb copyjump rommap
	./copyjump notmain.mb
	$(CROSS_COMPILE)-as $(AOPS) notmain.mb.s -o notmain.mb.o
	$(CROSS_COMPILE)-ld -T rommap notmain.mb.o -o notmain.mb.elf
	$(CROSS_COMPILE)-objdump -D notmain.mb.elf > notmain.mb.list
	$(CROSS_COMPILE)-objcopy notmain.mb.elf -O binary notmain.gba

copyjump : copyjump.c
	gcc copyjump.c -o copyjump

notmain.mb :               memmap startup.o notmain.o
	$(CROSS_COMPILE)-ld -T memmap startup.o notmain.o -o notmain.elf
	$(CROSS_COMPILE)-objdump -D notmain.elf > notmain.list
	$(CROSS_COMPILE)-objcopy notmain.elf -O binary notmain.mb

clean :
	rm -f *.o
	rm -f *.elf
	rm -f *.bin
	rm -f *.list
	rm -f *.gba
	rm -f *.bin.s
	rm -f *.mb
	rm -f *.mb.s
	rm -f copyjump

