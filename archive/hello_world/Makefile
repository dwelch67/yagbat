
CROSS_COMPILE ?= arm-none-eabi

AOPS = --warn --fatal-warnings 
COPS = -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding 




hello_world.gba : hello_world.mb copyjump rommap
	./copyjump hello_world.mb
	$(CROSS_COMPILE)-as $(AOPS) hello_world.mb.s -o hello_world.mb.o
	$(CROSS_COMPILE)-ld -T rommap hello_world.mb.o -o hello_world.mb.elf
	$(CROSS_COMPILE)-objdump -D hello_world.mb.elf > hello_world.mb.list
	$(CROSS_COMPILE)-objcopy hello_world.mb.elf -O binary hello_world.gba

copyjump : copyjump.c
	gcc copyjump.c -o copyjump

hello_world.mb : startup.o hello.o video.o memmap
	$(CROSS_COMPILE)-ld startup.o hello.o video.o -T memmap -o hello_world.elf
	$(CROSS_COMPILE)-objdump -D hello_world.elf > hello_world.list
	$(CROSS_COMPILE)-objcopy hello_world.elf -O binary hello_world.mb

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
	rm -f *.mb
	rm -f copyjump

