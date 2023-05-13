AFTER COMPILING LISTING1.CPP, WE OBTAIN : 

++Complex(0,0)
0x7ffe28bb32f0

+++Complex(1,1)
0x7ffe28bb3300

+++Complex(2,2)
0x7ffe28bb3310

Calling foo()
rrrComplex(1+i.1)
0x7ffe28bb3300

rrrComplex(0+i.0)
0x7ffe28bb32f0

+++Complex(10,10)
0x7ffe28bb32c0

op=Complex(0+i.0)
0x7ffe28bb32c0

op=Complex(1+i.1)
0x7ffe28bb32c0

rrrComplex(1+i.1)
0x7ffe28bb32c0

op=Complex(1+i.1)
0x7ffe28bb3310

End of main()


LET'S ANALYZE IT LINE BY LINE:

lines 1,2: Constructor which takes two doubles is called (even if we the arguments were both int), the complex number that 
has (re, im) = (0, 0) is stored in the address 0x7ffe28bb32f0.

lines 3,4: Constructor which takes two doubles is called (even if we the arguments were both int), the complex number that 
has (re, im) = (1, 1) is stored in the address 0x7ffe28bb3300.

lines 5,6: Constructor which takes two doubles is called (even if we the arguments were both int), the complex number that 
has (re, im) = (2, 2) is stored in the address 0x7ffe28bb3310.

lines 8,9: the compiler makes a copy of arguments that foo() requires, so it begins by making a copy of z1 (first argument) and 
storing it in 0x7ffe28bb3300

lines 10,11: the compiler makes a copy of arguments that foo() requires, so it begins by making a copy of z0 (second argument) and 
storing it in 0x7ffe28bb32f0

lines 12,13: The execution of the function begins. A new complex(10, 10) is created and stored in 0x7ffe28bb32c0.

lines 14,15: in the same address, the operator = is used to give to z(10, 10) the value of the first argument of the function.

lines 16,17: in the same address again, the operator = is used to put in the value of the second argument of the function.

lines 18,19: the returned value of the function foo() is copies in the address of z3 (0x7ffe28bb3310) by using the copy constructor.

