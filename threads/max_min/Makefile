source = *.c

include = *.h

all: $(source)
	gcc $(source) $(include) -lpthread -o a.out

run:
	./a.out

clean:
	rm -rf *.out *.o
