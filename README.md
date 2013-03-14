MIU Genie 
==========
Solve problems from the MIU system described in Douglas Hofstadter's [Gödel, Escher, Bach](http://www.amazon.com/Godel-Escher-Bach-Eternal-Golden/dp/0465026567) using the "genie method" 

Building
--------
To build the project, run
```bash
make
```

Running
-------
This project takes two arguments: (1) The MIU string to start with and (2) the desired MIU string.
For example:
```bash
./miu MI MIUUI
```

Rules
-----
In his book, Hofstadter describes a MIU system with four axioms:

1. A 'U' can be added to the end of any string ending with an 'I'

2. A string of the form Mx where x is an arbitrary string can be transformed into Mxx

3. Any sequence of three consecutive 'I' characters in a string (III) can be replaced with a single 'U' character

4. Any sequence of two consecutive 'U' characters in a string (UU) can be replaced with the empty string ''

The object of Hofstadter's original challenge is to use the MIU system to transform the string MI into MU.

Caveats
-------
1. This application defines a maximum string length of 20 by default. Any sequence that is (1) longer than 20 character or (2) requires an intermediate result that is longer than 20 characters will fail to complete. The ```MAX_STRING_LENGTH``` parameter can be adjusted in ```miu.cpp``` if necessary.
2. This application will not reject inputs that are not part of the MIU system


