
CROSS_COMPILE ?= arm-none-eabi

AOPS = --warn --fatal-warnings 
COPS = -mcpu=arm7tdmi -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding 

all : notmain.gba

startup.o : startup.s
	$(CROSS_COMPILE)-as $(AOPS) startup.s -o startup.o

notmain.o : notmain.c
	$(CROSS_COMPILE)-gcc -c $(COPS) notmain.c -o notmain.o

rom.h : bintoc.c notmain.mb
	gcc bintoc.c -o bintoc
	./bintoc notmain.mb rom.h

flash.o : flash.s
	$(CROSS_COMPILE)-as $(AOPS) flash.s -o flash.o

copyjump.o : copyjump.c rom.h
	$(CROSS_COMPILE)-gcc -c $(COPS) copyjump.c -o copyjump.o

notmain.gba :              rommap flash.o copyjump.o 
	$(CROSS_COMPILE)-ld -T rommap flash.o copyjump.o -o copyjump.elf
	$(CROSS_COMPILE)-objdump -D copyjump.elf > copyjump.list
	$(CROSS_COMPILE)-objcopy copyjump.elf -O binary notmain.gba
	cp notmain.gba 901_bssdata.gba

notmain.mb :               memmap startup.o notmain.o
	$(CROSS_COMPILE)-ld -T memmap startup.o notmain.o -o notmain.elf
	$(CROSS_COMPILE)-objdump -D notmain.elf > notmain.list
	$(CROSS_COMPILE)-objcopy notmain.elf -O binary notmain.mb
	cp notmain.mb 901_bssdata.mb

clean :
	rm -f *.o
	rm -f *.elf
	rm -f *.bin
	rm -f *.list
	rm -f *.gba
	rm -f *.mb
	rm -f rom.h
	rm -f bintoc

