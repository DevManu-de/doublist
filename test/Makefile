run:
	make -C ../
	gcc test.c ../libdoublist.a -o test -I../include
	valgrind --leak-check=full --track-origins=yes ./test

.PHONY: clean
clean:
	rm -f test

