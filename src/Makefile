tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c
gui.o: gui.c tokenizer.h
	gcc -c gui.c
main: tokenizer.o gui.o
	gcc -o test tokenizer.o gui.o
clean:
	rm -f test *o *~ *# *.#
