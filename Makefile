Smith-Waterman.o: Smith-Waterman.c Smith-Waterman.h scoring_matrix.h traceback.h
	clang -Wall -Werror -c Smith-Waterman.c -o Smith-Waterman.o

scoring_matrix.o: scoring_matrix.c scoring_matrix.h
	clang -Wall -Werror -c scoring_matrix.c -o scoring_matrix.o

traceback.o: traceback.c traceback.h scoring_matrix.h
	clang -Wall -Werror -c traceback.c -o traceback.o

from-csv: Smith-Waterman.o scoring_matrix.o traceback.o from-csv.c
	clang -Wall -Werror Smith-Waterman.o scoring_matrix.o traceback.o from-csv.c -o from-csv

test: Smith-Waterman.o scoring_matrix.o traceback.o test.c
	clang -Wall -Werror Smith-Waterman.o scoring_matrix.o traceback.o test.c -o test

clean:
	rm Smith-Waterman.o scoring_matrix.o traceback.o from-csv test
