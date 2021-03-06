Project 1: Tokenizer
====================
# Instructions:

You should document your tokenizer in this file.

This file is written in the refreshingly simple `markdown` text
formatting language.

To learn about text formatting using markdown, we encourage you to examine 
 - [../README.md](../README.md)
 - the online [Markdown Guide](https://www.markdownguide.org/).

# tokenizer.c

The tokenizer.c file contains 5 methods that manipulate both char and char*.
The two called space_char and non_space_char, check if a character is a space
or not and returns true.

The next two called *word_end and *word_start, return either 0 pointers if the
input is empty, or a pointer to the start of the word and a pointer to the
first space after the end of the first word.

The last method counts the number of words in a char* called str and returns
it to the user.

The five methods can be tested using a Make file and gui.c

The next section of the tokenizer has 4 methods that complete the tokenizing
function. These four are: copy_str, which copiesone string to another taking
into consideration memory and space, tokenize, which seperates all the words
in an input string into individual tokens, print_tokens which prints all the
designated tokens for a tokenized string, and free_tokens which frees the
allocated memory.

The tokenizing method can be tested using a Make file and gui.c

#history.c

The history.c file contains 5 methods that aid the user in keeping track of
what has been written in the tokenizer. The methods consist of init_history(),
which instanciates a new instance of a linked list where the history will be
stored, add_history, which iterates through the history and adds a new entry
every time the user tokenizes a string, *get_history which gets the specific
string at a certain key that the user specifies through the command !key,
print_history, which prints the entire history that is stored in the linked
list, and finally free_history, which frees all the allocated memory for the
linked list so that the next iteration has a clean linked list.

The tokenizing method can be tested using a Make file and gui.c

## gui.c

The gui.c file takes in user input, displays it back to the user and is used
to test the methods inside tokenizer with the use of a Makefile.

Inside gui.c there are two methods a main and one called userInputGUI, which
holds the logic responisble for getting the user input and displaying it to
the user, as well as the temporary test cases. The main holds a single call to
userInputGUI.


## MakeFile

The make file holds 4 major functions, tokenizer.o, gui.o, main, and clean.

-Tokenizer.o: Is resonsible for compiling tokenizer.c
-gui.o: is responsible for compiling gui.c
-main: is responsible for compiling gui.o and tokenizer.o and running it using
-a file called test
> test can be called after the command "make main" is called followed by
>./test to see the output
-clean: is responsible for cleaning the directory of unwanted files.

All methods can be called with command "make <function_name>".
