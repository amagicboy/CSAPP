CFLAGS = -Og
CC = gcc
OBJS1=show-bytes32 show-bytes64
OBJS2=ha

all: $(OBJS2) 

show-bytes32: show-bytes.c
	$(CC) $(CFLAGS) -m32 show-bytes.c -o show-bytes32

show-bytes64: show-bytes.c
	$(CC) $(CFLAGS) -m64 show-bytes.c -o show-bytes64

ha: homework.c
	$(CC) $(CFLAGS) homework.c -o ha 

clean:
	rm -f *~ *.o show-bytes32 show-bytes64 combine_nums is_little_endian replace_byte homework ha
