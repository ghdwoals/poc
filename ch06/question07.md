Given a group of variables, their addresses, and their contents, determine their rvalues and lvalues, and the addresses of their locations, if any (otherwise note their illegalities). Assume all variables are:

(1) integers; then
(2) pointers to integers,

and that address arithmetic is based on 4-byte integers and pointers.

The table is recreated below:

VAR     |   ADDR    |   CONTENTS    |   VAR     |   ADDR    |   CONTENTS
--------|-----------|---------------|-----------|-----------|-----------
a       |   1040    |   1028        |   o       |   1096    |   1024
c       |   1056    |   1076        |   q       |   1084    |   1072
d       |   1008    |   1016        |   r       |   1068    |   1048
e       |   1032    |   1088        |   s       |   1004    |   2000
f       |   1052    |   1044        |   t       |   1060    |   1012
g       |   1000    |   1064        |   u       |   1036    |   1092
h       |   1080    |   1020        |   v       |   1092    |   1036
i       |   1020    |   1080        |   w       |   1012    |   1060
j       |   1064    |   1000        |   x       |   1072    |   1080
k       |   1044    |   1052        |   y       |   1048    |   1068
m       |   1016    |   1008        |   z       |   2000    |   1000
n       |   1076    |   1056        |           |           |

As a simple example, if variable <code>a</code> were an integer, its rvalue would be 1028 and its lvalue address at 1040.

For every given expression, determine its rvalue and lvalue address. If illegal, specify so. The incomplete table, save for the first answer, and the expressions is shown first. Each expression's rvalues and lvalue addresses are explained. Finally, a completed table will be shown.
```
EXPRESSION  | INT RVALUE | INT LVALUE ADDR | INT* RVALUE | INT* LVALUE ADDR
------------|------------|-----------------|-------------|-----------------
(a) m       |   1008     |   1016          |   1008      |   1016
(b) v + 1   |    |  |   |
(c) j - 4   |
(d) a - d   |
(e) v - w   |
(f) &c      |
(g) &e + 1  |
(h) &o - 4  |
(i) &(f + 2)|
(j) *g      |
(k) *k + 1  |
(l) *(n + 1)|
(m) *h - 4  |
(n) *(u + 4)|
(o) *f - g  |
(p) *f - *g |
(q) *s - *q |
(r) *(r - t)|
(s) y > i   |
(t) y > *i  |
(u) *y > *i |
(v) **h     |
(w) c++     |
(x) ++c     |
(y) *q++    |
(z) (*q)++  |
(aa)    *++q|
(bb)    ++*q|
(cc) ```*++*q```|
(dd)```++*(*q)++```|
```
The
