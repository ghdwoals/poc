Given a group of variables, their addresses, and their contents, determine their rvalues and lvalues, and the addresses of their locations, if any (otherwise note their illegalities). Assume all variables are:

(1) integers (```int```); then
(2) pointers to integers (```int *```),

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

As a simple example, if variable ```a``` were an integer, its rvalue would be 1028 and its lvalue address at 1040.

For every given expression, determine its rvalue and lvalue address. If illegal, specify so. The incomplete table, save for the first answer, and the expressions is shown first. Each expression's rvalues and lvalue addresses are explained. Finally, a completed table will be shown.

EXPRESSION  | INT RVALUE | INT LVALUE ADDR | INT* RVALUE | INT* LVALUE ADDR
------------|------------|-----------------|-------------|-----------------
(a) ```m```       |   1008     |   1016          |   1008      |   1016
(b) ```v + 1```   |    |  |   |
(c) ```j - 4```   |
(d) ```a - d```   |
(e) ```v - w```   |
(f) ```&c```      |
(g) ```&e + 1```  |
(h) ```&o - 4```  |
(i) ```&(f + 2)```|
(j) ```*g```      |
(k) ```*k + 1```  |
(l) ```*(n + 1)```|
(m) ```*h - 4```  |
(n) ```*(u + 4)```|
(o) ```*f - g```  |
(p) ```*f - *g``` |
(q) ```*s - *q``` |
(r) ```*(r - t)```|
(s) ```y > i ```  |
(t) ```y > *i ``` |
(u) ```*y > *i``` |
(v) ```**h   ```  |
(w) ```c++```     |
(x) ```++c  ```   |
(y)``` *q++```    |
(z) ```(*q)++``` |
(aa)  ```*++q```|
(bb)```++*q```|
(cc) ```*++*q```|
(dd)```++*(*q)++```|

First, let's use simple definitions of lvalue and rvalue from [Eli Bendersky] (http://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c). An lvalue: "represents an object that occupies some identifiable location in memory (i.e. has an address)". An rvalue "is an expression that does not represent an object occupying some identifiable location in memory".

(a) ```m```

This one is fairly straightforward. If ```m``` is type int, its rvalue would be 1008, and its lvalue address would be at 1016. It is pretty easy to see that attempting to assign another (valid) value to ```m``` would be doable because its location is known. If ```m``` is ```int*```, its contents would be 1008 (the address it is pointing to), and its lvalue addr would be 1016. Again, because its address is clearly known, it can be changed.


(b) ```v + 1```

The contents of ```v``` is 1036; adding 1 to ```v``` would give an rvalue of 1037. This is straightforward. However, the expression ```v + 1``` does not represent a legal lvalue address. While ```v``` is a perfectly legal lvalue, because it represents a valid address, ```v + 1``` does not represent a valid address in memory, hence it is illegal.

If ```v``` were an ```int*```, its rvalue would be 1040. Remember, we are working with a 4-byte ```int``` and ```int*```. However, the expression ```v + 1``` would not represent a valid lvalue address.

(c) ```j - 4```

Again, ```int j``` - 4 would be 996. And, again, ```j - 4``` would not represent a legal lvalue address. 







