1-Echauffement

The listing 1 code displays : "x vaut 5"

line 6 : It defines r as a reference on x.
line 7 : the y value is assigned to r. Then, r = x = 3.0
line 8 : r value becomes 5.0, and so x value


2.2.1.a:
The compiler return error, because it's an ambiguous call for the function "read".
the overloading concept concept require that functions have different type of arguments, which it is not the case because of the fact that reference could be interpreted as an int.

3.
Parameters of the function "exchangeNumberOfPages()" are reference to book, so
when we give it two arguments "Book", it generates an error. Not only
that, but also because Book's can't be modified because it's not a pointer, so
the numberOfPages isn't a pointer, then assign for example 54 to 50 isn't
logical.
