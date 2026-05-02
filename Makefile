obj := $(patsubst %.c,%.o,$(wildcard *.c))
invert: $(obj)
	gcc -o $@ $^
clean:
	rm -f *.o invert