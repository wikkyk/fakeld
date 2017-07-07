CC ?= cc

all:
	$(CC) -o ld-2.24.so -static fakeld.c

install:
	mkdir /lib64
	cp ld-2.24.so /lib64
	ln -s ld-2.24.so /lib64/ld-linux-x86-64.so.2

.PHONY: all install
