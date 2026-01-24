*This project has been created as part of the 42 curriculum by cclarke.*

**Description**\
This project involved creating a program that, when called as a function, returns a line from a given
file. Each time it is called, it returns the next line. Simple as.

**Instructions**\
In a main file, no more is needed than to call the function `get_next_line()`. It's return value will be
the very line from the file. The next call will return the next line, and so on. In order to access the
file, one must employ the `open()` function,[^1] whose returned file descriptor value stored in an `int`
variable is to be put as `get_next_line()`'s parametre.

**Resources**\
I used Slack and ChatGPT to resolve any obscurities that I might have faced, nothing else. Besides this I
found good nights' sleep to be a good resource.

**Algorithm**\
The algorithm is a simple one. A static variable buffer (`buf`) is used to store information `read()` from
the file. If there is no `\n` present, it appends the conents to another string variable, which either
consists of `""` or `buf`'s previous contents based on how much of it was erased up to the prior `\n`. The
latter does not occur if `get_next_line()` is being called for the first time. It keeps doing this until
there is a `\n` present in buf, in which case it appends it to that other string variable, including content
past the `\n` not yet meant to be displayed. The prototypical final string gets cut at the point of the `\n`
,leaving it at the end of it) and the string is returned.\
If the file ends with a line that does not end with a `\n` then what is instead done is (i) based on `bytes`,
a `ssize_t` variable containing how many bytes `read()` read, being less than `BUFFER_SIZE`, the size of
the buffer, a.k.a. how many bytes `read()` is meant to read by default, but larger than 1, which would only
happen if the last and single character read was '\n'; or, (ii) based on `bytes` equalling exactly one, viz.
'\n'.\
Before the string to be returned.. gets returned, `buf` is updated so that everything past the `\n` gets
pushed to the front of the string for next time. This means that if `buf` ends with a `\n`, buf will only
consist of NULL-terminators. This dictates whether the pre-finalised string should start as `""` or with
the contents of `buf` as mentioned above.\

[^1]: Present when the `<fcntl.h>` header is pound-included.
