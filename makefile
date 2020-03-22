eqsubsets: eqsubsets.c eqsubsets.h
	gcc -Wall -o eqsubsets eqsubsets.c

clean:
	rm -rf eqsubsets *.o
