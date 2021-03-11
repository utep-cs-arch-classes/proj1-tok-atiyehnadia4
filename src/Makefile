tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c
gui.o: gui.c tokenizer.h
	gcc -c gui.c
history.o: history.c history.h
	gcc -c history.c
main: tokenizer.o gui.o history.o
	gcc -o test tokenizer.o gui.o history.o
clean:
	rm -f test *o *~ *# *.#
