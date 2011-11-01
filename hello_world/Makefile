
CROSS_COMPILE ?= arm-none-eabi

AOPS = --warn --fatal-warnings 
COPS = -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding 




hello_world.gba : hello_world.bin copyjump rommap
	./copyjump hello_world.bin
	$(CROSS_COMPILE)-as $(AOPS) hello_world.bin.s -o hello_world.bin.o
	$(CROSS_COMPILE)-ld -T rommap hello_world.bin.o -o hello_world.bin.elf
	$(CROSS_COMPILE)-objdump -D hello_world.bin.elf > hello_world.bin.list
	$(CROSS_COMPILE)-objcopy hello_world.bin.elf -O binary hello_world.gba

copyjump : copyjump.c
	gcc copyjump.c -o copyjump

hello_world.bin : startup.o hello.o video.o memmap
	$(CROSS_COMPILE)-ld startup.o hello.o video.o -T memmap -o hello_world.elf
	$(CROSS_COMPILE)-objdump -D hello_world.elf > hello_world.list
	$(CROSS_COMPILE)-objcopy hello_world.elf -O binary hello_world.bin

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
	rm -f copyjump

