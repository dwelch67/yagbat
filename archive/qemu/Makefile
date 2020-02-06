
CROSS_COMPILE ?= arm-none-eabi

AOPS = --warn --fatal-warnings 
COPS = -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding 

hello_world.bin : startup.o hello.o uart.o memmap
	$(CROSS_COMPILE)-ld startup.o hello.o uart.o -T memmap -o hello_world.elf
	$(CROSS_COMPILE)-objdump -D hello_world.elf > hello_world.list
	$(CROSS_COMPILE)-objcopy hello_world.elf -O binary hello_world.bin

startup.o : startup.s
	$(CROSS_COMPILE)-as $(AOPS) startup.s -o startup.o

hello.o : hello.c 
	$(CROSS_COMPILE)-gcc -c $(COPS) hello.c -o hello.o

uart.o : uart.c
	$(CROSS_COMPILE)-gcc -c $(COPS) -mthumb uart.c -o uart.o
	

clean :
	rm -f *.o
	rm -f *.elf
	rm -f *.bin
	rm -f *.list
	rm -f *.gba
	rm -f *.bin.s
	rm -f *.mb
	rm -f copyjump

