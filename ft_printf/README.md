*This project has been created as part of the 42 corriculum by cclarke.*

**Description**\
This project involved making a good enough copy of printf() from the libc, called ft\_printf().
It only employs printf()'s most essential variable conversions, viz. `%c` `%s` `%p` `%d` `%i`
`%u` `%x` `%X` `%%`; or, respectively, a single `char`, a string, a value of the `void *` type
or an address, a decimal number, an decimal integer, an unsigned integer, a number in hexadecimal,
lower- or upper-case, and finally a per cent sign. `%d` and `%i` are mechanically identical.

**Instructions**\
Using `make`, we may simply `make`, which spawns the necessary `o.` files of both `ft_printf`
and `Libft`. Appending `clean` to the `make` command removes all the `.o` files, but not the `.a`
(static library) file, whereas `fclean` does. `make re` is the same thing as doing `make fclean`
and then `make`. \
All of these commands tie in with Libft, so there is no need to `make` both libraries separately. \
To compile a main programme with these, use these flags: `-L. -lftprintf -Llibft -lft`.

**Resources**\
I didn't record them because it wasn't required at the time. My resources were mainly GitHub
and StackOverflow. AI was used when debugging uncaffinated.

**DSAs**\
The ft\_printf() function indexes through a `constant char *` string taken as a primary argument,
displaying each of its characters. Upon meeting a per cent sign, a conditional clause checks the
next character, and based on that, it triggers another function, appropriately displaying the data
passed, itself produced as a contingent argument by use of the `va\_list` type. My justification
is that it's the algorithm expected for someone at my level. I don't use any data structures other
than simple memory blocks (e.g. for strings), since the data being acted upon by the programme
isn't convoluted enough to require it.
