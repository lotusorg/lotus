# lotus code style

## file extensions

* c source file extesion is .c
* c headers files extensions is .h
* c++ source file extesion is .cpp
* c++ headers files extensions is .hpp
* assembly source files extension is .s

## lagnuage standard

* assembly will use the gnu assembler syntax

## headers

* headers must have include guards

  ````c
  #ifndef __HEADER_H__
  #define __HEADER_H__

  /* some code */

  #endif /* __HEADER_H__ */
  ````

* c headers must have this

  ````c
  #ifdef __cplusplus
  extern "C" {
  #endif

  /*  some code */

  #ifdef __cplusplus
  }
  #endif
  ````

## macros

* in general macros should not be used. However, if they are absolutely needed, then they should be named with all capitals and underscores
* between `#include` directive and the name of the header there must be 1 space `#include "header.h"`

## comments

* one line comments looks like this: `/* one line commnet should look like this */`
* its highly recommended adding comments in the code and documenting functions

## code

* before every curly brace there is must to be a new line
* the asterisks in a pointer eclration is in the side of the type `type_name* var_name`
* return types of a function must be at the same line of the declartion of the function
* on function declration in header files, you should specify arguments name

## spaces tabs and indentation

* dont use tabs
* use 4 spaces to indenet
