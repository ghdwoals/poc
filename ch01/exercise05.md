There have been troubles compiling and running Reek's modified code for his
original rearrange program in Chapter 1. Running the program with different
types of input led to varying outputs and a lot of segfaults.

```
1 3 5 10 -1
This is a test line
Original input: This is a test line
Rearranged line: hisis a t
```

```
3 1 5 10 -1
This is a test line
Original input: This is a test line
Segmentation fault (core dumped)
```


```
1 3 10 5 -1
This is a test line
Original input: This is a test line
Segmentation fault (core dumped)
```


```
1 10 3 5 -1
This is a test line
Original input: This is a test line
Rearranged line: his is a ts i
```


```
10 5 3 1 -1
This is a test line
Original input: This is a test line
Segmentation fault (core dumped)
```

You might have noticed that I didn't specifically enter *ranges* out of order.
Note that I did test this, and entering ranges in different orders (for example:
1 5 3 10 -1 and 5 10 1 3 -1) led to different outputs.

Since I was somewhat confused on the original goal of the exercise, I decided
to modify the whole thing. The objective is to "Modify the rearrange function
so that it will work correctly even if the ranges are not entered in order."

I decided to modify the program so that it would work no matter what order the
user entered the numbers. It's a little different, but it works. I guess.
