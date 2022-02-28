This is Henry Jiang's 2021-2022 Science Fair project. This README details input information. For information on the algorithm/project, read the PDF. 

The first line should be Type: [Standard|XV|Ineq]. Not case sensitive. This details the sudoku type. For what these mean, see the paper.

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

Insert '-' between cells and between rows for no symbol, 'X' for X, and 'V' for V (not case sensitive). Example:

```
Type: XV
0-0-0X0-0-0-0-0X0
V---X-V--
0-0-0-0-0-0V0X0-0
---------
0-0-2-0X0-0-4-0-5
---V-X---
0-0-0-0-0X0-0-0X0
-V-------
0X0-0-0-0-0-0X0-0
----XX--V
0-0-0-0-0-0-0-0-0
----V----
5-0-4-0X0-0-1-0X0
---------
0X0-0-0X0-0-0-0X0
---------
0-0-0-0-0-0-0-0X0
```

# Ineq/Inequality

Between cells, insert > for left greater than right, < for right greater than left. Between rows, insert > for top greater than bottom and < for bottom greater than top. If no symbol was given, use '-'. Example:

```
Type: Ineq
0-0-0-0-0>0-0-0-0
<---><-<>
0-0-0-0>0-0-0-0<0
<<---<---
0<0<0-0<0-0<0>0<0
->-><----
0-0-0-0-0<0-0-0-0
-------><
0>0-0>0-0-0-0>0>0
<---<->-<
0-0-0>0-0-0-0<0-0
><<>-->>>
0-0>0-0>0<0>0-0-0
><-----<-
0<0-0-0-0-0-0-0-0
--<->----
0-0<0-0>0>0-0-0-0
```
