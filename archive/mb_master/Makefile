
CROSS_COMPILE ?= arm-none-eabi

AOPS = --warn --fatal-warnings 
COPS = -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding 




keyboard_poll.gba : keyboard_poll.mb copyjump rommap
	./copyjump keyboard_poll.mb
	$(CROSS_COMPILE)-as $(AOPS) keyboard_poll.mb.s -o keyboard_poll.mb.o
	$(CROSS_COMPILE)-ld -T rommap keyboard_poll.mb.o -o keyboard_poll.mb.elf
	$(CROSS_COMPILE)-objdump -D keyboard_poll.mb.elf > keyboard_poll.mb.list
	$(CROSS_COMPILE)-objcopy keyboard_poll.mb.elf -O binary keyboard_poll.gba

copyjump : copyjump.c
	gcc copyjump.c -o copyjump

keyboard_poll.mb : startup.o hello.o video.o memmap
	$(CROSS_COMPILE)-ld startup.o hello.o video.o -T memmap -o keyboard_poll.elf
	$(CROSS_COMPILE)-objdump -D keyboard_poll.elf > keyboard_poll.list
	$(CROSS_COMPILE)-objcopy keyboard_poll.elf -O binary keyboard_poll.mb
	cp keyboard_poll.mb 02000000.bin

startup.o : startup.s
	$(CROSS_COMPILE)-as $(AOPS) startup.s -o startup.o

hello.o : hello.c video.h 
	$(CROSS_COMPILE)-gcc -c $(COPS) hello.c -o hello.o

video.o : video.c video.h
	$(CROSS_COMPILE)-gcc -c $(COPS) video.c -o video.o

clean :
	rm -f *.o
	rm -f *.elf
	rm -f *.bin
	rm -f *.list
	rm -f *.gba
	rm -f *.bin.s
	rm -f *.mb.s
	rm -f *.mb
	rm -f copyjump

