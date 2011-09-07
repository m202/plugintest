all:	test plug1.so plug2.so

plug1.so: plug1.c
	gcc -fPIC -shared -o plug1.so plug1.c

plug2.so: plug2.c
	gcc -fPIC -shared -o plug2.so plug2.c

test: test.c
	gcc -o test test.c -ldl

clean:
	rm -f *.o *.so test
