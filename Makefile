CC=gcc

CLAGS=-DDEBUG

all: unisim test_sim

unisim:	main.c sim.o loader.o shifter.o mmu.o extender.o syscall.o
	$(CC) $(CFLAGS) -o unisim main.c sim.o loader.o helper.o shifter.o mmu.o extender.o syscall.o

sim.o: sim.c sim.h helper.h helper.o
	$(CC) $(CFLAGS) -c sim.c

loader.o: loader.c loader.h helper.h helper.o
	$(CC) $(CFLAGS) -c loader.c

helper.o: helper.c helper.h
	$(CC) $(CFLAGS) -c helper.c

shifter.o: shifter.c shifter.h
	$(CC) $(CFLAGS) -c shifter.c

mmu.o: mmu.c mmu.h
	$(CC) $(CFLAGS) -c mmu.c

extender.o: extender.c extender.h
	$(CC) $(CFLAGS) -c extender.c

test: unisim hello
	./unisim hello

test_sim: sim.o test_sim.c
	$(CC) $(CFLAGS) -o test_sim test_sim.c sim.h

syscall.o: syscall.c syscall.h
	$(CC) $(CFLAGS) -c syscall.c

clean:
	rm *.o
