/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.11
 * Author: pzuehlke
 ****************************************************************************/

/* 
Here are some test cases to consider:

* Empty input: This should return a word, line, and character count of 0.

* Input with only whitespace characters (spaces, tabs, newlines): This should
  also return a count of 0.

* Input of a single word with no leading or trailing whitespace: This should
  return a word count of 1.

* Input with multiple words separated by various kinds of whitespace (spaces,
  tabs, newlines), including combinations of these such as a whitespace
  immediately followed by a newline and a tab: The word count should equal the
  number of words.

* Very long input: This checks whether the program can handle large data.

* Very long words, longer than typical buffer sizes: This could potentially
  uncover bugs related to buffer overflows.
*/
