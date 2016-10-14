NOTE: This page is not yet complete.

Question:
Given a group of variables, their addresses, and their contents, determine their rvalues, then find its lvalue (giving the address of the location it specifies, if any). Otherwise, note their illegalities. Assume all variables are:

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

First, let's use simple definitions of lvalue and rvalue from [Eli Bendersky] (http://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c). It would be advised to discuss what lvalues and rvalues are before answering the question. An lvalue: "represents an object that occupies some identifiable location in memory (i.e. has an address)". An rvalue "is an expression that does not represent an object occupying some **identifiable** location in memory" [emphasis mine]. To continue his example:

```c
4 = var;        // ERROR!
(var + 1) = 4;  // ERROR!
```

The above expressions are not legal lvalues because "both are temporary results of expressions, which don't have an identifiable memory location (i.e. they can just reside in some temporary register for the duration of the computation). Therefore, assigning to them makes no semantic sense - there's nowhere to assign to."

(a) ```m```

This one is fairly straightforward. If ```m``` is type ```int```, its rvalue would be 1008, and its lvalue address would be at 1016. It is pretty easy to see that attempting to assign another (valid) value to ```m``` would be doable because its location is known. If ```m``` is ```int*```, its contents would be 1008 (the address it is pointing to), and its lvalue addr would be 1016. Again, because its address is clearly known, it can be changed.


(b) ```v + 1```

The contents of ```v``` is 1036; adding 1 to ```v``` would give an rvalue of 1037. This is straightforward. However, the expression ```v + 1``` does not represent a legal lvalue address. While ```v``` is a perfectly legal lvalue, because it represents a valid address, ```v + 1``` does not represent a valid address in memory, hence it is illegal.

If ```v``` were an ```int*```, its rvalue would be 1040. Remember, we are working with a 4-byte ```int``` and ```int*```. However, the expression ```v + 1``` would not represent a valid lvalue address because the expression does not represent some object that has an identifiable address.

(c) ```j - 4```

Again, ```int j``` - 4 would be 996. And, again, ```j - 4``` would not represent a legal lvalue address. If ```j``` is an ```int*```, ```j - 4``` would evaluate to an rvalue of 984. However, this would not be a legal lvalue, because the expression does not represent a valid identifiable address in memory.

(d) ```a - d```

As an ```int```, ```a - d``` evaluates to 12, but the expression cannot serve as a legal lvalue address. As an ```int*```, the expression evaluates to 3 [(1028 - 1016) / 4], but it is illegal to use as an lvalue address. 

(e) ```v - w```

```int```: ```v - w``` == 1036 - 1060 == -24. No legal representation as an lvalue address. As ```int*```s, -24/6 = -4 == rvalue. Again, the expression ```v - w``` does not represent an identifiable location in memory.

(f) ```&c```

```&``` is an address operator.

```int```: rvalue = 1056. Illegal lvalue address. It would perhaps be unwise to allow one to manipulate the address of some variable.

```int*```: rvalue = 1056. Again, there is no legal use as an lvalue.

(g) ```&e + 1```

```int```: rvalue = 1036. Since we are dealing with addresses and 4-byte integers, 4 is added to the original address. No legal lvalue.

```int*```: rvalue = 1036. lvalue address = illegal.

(h) ```&o - 4```

```int```: rvalue = 1080. lvalue address = illegal.
```int*```: rvalue = 1080. lvalue address = illegal.

(i) ```&(f + 2)```

In this case, all of the rvalues and lvalues are illegal. Think of it this way with ```f``` as an ```int```. What we are essentially asking the program to do is add 2 to ```f``` (for a sum of 1054) and then go to the address of this transient value.

(j) ```*g```

Since ```int``` cannot be dereferenced, ```*g``` is illegal both as an rvalue and lvalue. However, as an ```int*```, it is legal in both cases. As an rvalue, the value of ```*g``` is fairly obvious. We dereference the address pointed to by ```g```, which is 1064. Therefore, the rvalue is 1000. Since ```g``` is pointing at a legitimate address in memory, the contents of what ```g``` is pointing to can be manipulated. ```g``` points to address 1064.

(k) ```*k + 1```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = 1045. lvalue address = illegal; operation cannot be to a fixed address.

(l) ```*(n + 1)```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = 1012. As for ```*(n + 1)```'s lvalue address, because it happens to represent an actual address, in this case it may be used legally. Its lvalue is 1060.

(m) ```*h - 4```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = 1076. lvalue address = illegal.

(n) ```*(u - 4)```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = 1056. lvalue address = 1076.

(o) ```*f - g```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = illegal. lvalue address = illegal. You cannot subtract a pointer's contents (address) from a dereferenced pointer.

(p) ```*f - *g```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = 52. lvalue address = illegal.

(q) ```*s - *q```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = -80. lvalue address = illegal.

(r) ```*(r - t)```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = illegla. lvalue address = illegal.

(s) ```y > i```

```int```: rvalue: 0 (remember "falsity" and "truthhood" in C). lvalue address = illegal.
```int*```: rvalue = 0. lvalue address = illegal.

(t) ```y > *i```

```int```: rvalue = illegal (illegal comparison). lvalue address = illegal.
```int*```: rvalue = illegal (illegal comparison). lvalue address = illegal.

(u) ```*y > *i```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = 1. lvalue address = illegal.

(v) ```**h```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = 1080. lvalue address = 1020.

(w) ```c++```

```int```: rvalue = 1076 (remember, this is postfix increment operator). lvalue address = illegal.
```int*```: rvalue = 1076. lvalue address = illegal.

(x) ```++c```

```int```: rvalue = 1077. lvalue address = illegal.
```int*```: rvalue = 1080. lvalue address = illegal.

(y) ```*q++```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = 1080. lvalue address = 1072.

(z) ```(*q)++```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = 1080. lvalue address = illegal. This expression differs from (y) in that the parentheses force dereferencing first. The indirection operator provides an integer value. This expression cannot serve as a legal lvalue, because its evaluation does not persist. In (y), the postfix incrementation actually has higher precedence and, thus, occurs first. In (y), ```q``` points to a known address, which is incremented after.

(aa) ```*++q```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = 1056. lvalue address = 1076.

(bb) ```++*q```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = 1081. lvalue address = illegal. Again, the indirection operator forces dereferencing to occur first. However, the value of this expression cannot be used as a valid lvalue address. Applying indirection on ```q``` gives us an integer value (incremented or not), not a valid address. This is in contrast to (aa), where ```q``` continues to point to an address and indirection applied after incrementation.

(cc) ```*++*q```

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = 1072. lvalue address = 1084.

(dd) ```++*(*q)++``` 

```int```: rvalue = illegal. lvalue address = illegal.
```int*```: rvalue = 1021. lvalue address = illegal.
