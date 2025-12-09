*This project has been created as part of the 42 curriculum by cclarke.*

**Description**\
This project involved programming a number of functions for common and incidental usage in
other projects. A great deal of these functions originate *qua* design from or are inspired
by those present in the libc; others are more original. This library also includes functions
pertaining to linked lists: that is, the creation, addition and destruction of lists and/or
their nodes.

**Instructions**\
Courtesy of the Makefile, we have four possible options:
- `make` compiles everything into a static library (a `.a` file), and spawns a bunch of
object (`.o`) files;
- `make clean` gets rid of the `.o` files, but not the `.a` file;
- `make fclean` gets rid of the `.o` files *and* the `.a` file;
- and `make re` is essentially the same as employing `make fclean` and then `make`.

Once the static library has been compiled, all that's left to be done in order to use it is to
`#include "libft.h"` in any given C programme and using the flags `-Llibft -lft`[^1] when
compiling it. That's how I do it, anyway.

**Resources**\
I can't provide very many of these, since the README wasn't mandatory when I finished the Libft
project, so I didn't make a record of it. For the linked lists, I used a document called 'Linked
Lists Basics'. Besides that, I had a look at a few GitHub pages for others' Libft projects and
StackOverflow questions that were asked by people in the past; and AI wasn't really used for
anything else than debugging. 

**Detailed Description of the Library**
- `ft_isalpha() ft_isdigit() ft_isalnum() ft_isascii() ft_isprint() ft_strlen() ft_memset()
ft_bzero() ft_memcpy() ft_memmove() ft_strlcpy() ft_strlcat() ft_toupper() ft_tolower()
ft_strchr() ft_strrchr() ft_strncmp() ft_memchr() ft_memcmp() ft_strnstr() ft_atoi() ft_calloc()
ft_strdup()`

The man pages for the near-homonyms of these provide enough by way of perfectly legible,
plain-English descriptions. I'm sure I don't need to bother with these ones.
- `ft_substr()` finds a term in a string, makes it into its own string, spits it out.
- `ft_strjoin()` returns a concatenation of two different strings.
- `ft_strtrim()` returns a string without certain characters per the given arguments.
- `ft_split()` turns a string into a `char **` on the basis of its 'delimiter', given as an
argument.
- `ft_itoa` turns an int to a string and returns it.
- `ft_strmapi()` applies a function given as an argument to each character of a string also given
as an argument, producing another string in the meantime, which it then returns.
- `ft_striteri()` does the same thing, except it doesn't return anything new; it just modified the
string given as an argument.
- `ft_putchar_fd()` takes a `char` and a file descriptor, and plops the char into the given file.
- `ft_putstr_fd`: same story, but takes a string instead.
- `ft_putendl_fd`: same as above but also provides a newline character.
- `ft_putnbr_fd()` takes an `int` and writes it as a string in the file.\
- `ft_lstnew()` generates a node[^2] and returns it.
- `ft_lstadd_front()` takes a linked list and a node as its argumets, 'links' the given node to
the list, rendering it its new head, and moves the original head of the list by one, making it the
second node.
- `ft_lstsize()` returns an `int` indicating how many nodes the given list has.
- `ft_lstlast()` takes a list and returns its very last node.
- `ft_lstadd_back()` is the inverse of `ft_lstadd_front()`: it takes a list and a node, and
attaches the node to the end of the list.
- `ft_lstdelone()` takes a node and a function as arguments, and destroys (frees) the node using
the function.
- `ft_lstcleari()` applies `ft_lstdelone()` on the given node and all those posterior to it.
- `ft_lstiter()` iterates through a list of nodes and applies the function given as an argument
to each of their contents.
- `ft_lstmap()` does the same thing, except it produces and returns a new list, or, if allocation
fails, it applies the second given function to the failed node, deleting it.

[^1]: `-Llibft` assumes the directory containing the static library is called `libft`; if the
library is present elsewhere, instead of writing `libft` after `-L`, write its path.

[^2]: The typedef for the linked list of which is present in `libft.h`.
