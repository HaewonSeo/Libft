# Libft(115/115)
+ Create My 42 C Library
+ It continues to be used in future projects.

### Introduction
C programming can be very tedious when one doesn’t have access to those highly useful
standard functions. This project gives you the opportunity to re-write those functions,
understand them, and learn to use them. This library will help you for all your future C
projects.
Through this project, we also give you the opportunity to expand the list of functions
with your own. Take the time to expand your libft throughout the year.

### Part 1 - Libc functions
+ In this first part, you must re-code a set of the libc functions, as defined in their
man. Your functions will need to present the same prototype and behaviors as the originals.


### Part 2 - Additional functions
+ In this second part, you must code a set of functions that are either not included in the
libc, or included in a different form. Some of these functions can be useful to write Part
1’s functions.

### Bonus Part
+ Having functions to manipulate memory and strings is very useful, but you’ll soon
discover that having functions to manipulate lists is even more useful. You’ll use the following structure to represent the elements of your list.
+ make bonus will add the bonus functions to the libft.a library
+ Here is a description of the fields of the t_list struct:
	+ content : The data contained in the element. The void * allows to store any kind of data.
	+ next : The next element’s address or NULL if it’s the last element.
