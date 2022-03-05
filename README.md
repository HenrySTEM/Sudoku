This is Henry Jiang's 2021-2022 Science Fair project. This README details input information. For information on the algorithm/project, read the PDF. 

The first line should be ```[Standard|XV|Ineq]```. Not case sensitive. This details the sudoku type. For what these mean, see the paper.
The second line should be ```[simple|recurse|backtrack|links]```. Not case sensitive. This details the algorithm.

Test cases I used:
Standard Sudoku test cases came from [here](http://lipas.uwasa.fi/~timan/sudoku/) (1,Medium,4,Escargot,Hard).

XV test cases came from [here](https://www.funwithpuzzles.com/2016/02/xv-sudoku.html) and the 2017 Sudoku Grand Prix [in this video](https://www.youtube.com/watch?v=9ATC_uBF8ow).

Inequality test case from [here](https://www.funwithpuzzles.com/2015/03/inequality-sudoku-fun-with-sudoku-40.html).

XV and Inequality sudoku test cases came from the first few Google Image results.

# Standard

For standard sudokus, just type a 9 by 9 matrix with no spaces (line breaks optional). If a cell is not given, insert a 0. Example:

```
Type: Sudoku
530070000
600195000
098000060
800060003
400803001
700020006
060000280
000419005
000080079
```

# XV

Insert '-' for no symbol 'X' for X, and 'V' for V (not case sensitive). Put the ones between two horizontally adjacent cells on a 9 by 8 grid after the numbers, then the ones between two vertically adjacent in a 8 by 9 grid after that. Line breaks optional. Example (the one in the paper):

```
Type: XV
000000000
000000000
002000405
000000000
000000000
000000000
504000100
000000000
000000000
--x----x
-----vx-
----x--x
x-----x-
--------
---x---x
x--x---x
-------x
v---x-v--
---------
---v-x---
-v-------
----xx--v
----v----
---------
---------
```

# Ineq/Inequality

Insert > for left greater than right, < for right greater than left, insert > for top greater than bottom and < for bottom greater than top. If no symbol was given, use '-'. Put a 9 by 8 after the numbers for horizontally adjacent cells, then 8 by 9 for the vertically adjacent.

```
Type: Ineq
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
---->---
--->---<
<<-<-<><
----<---
>->--->>
-->---<-
->-><>--
<-------
-<->>---
<---><-<>
<<---<---
->-><----
-------><
<---<->-<
><<>-->>>
><-----<-
--<->----
```
