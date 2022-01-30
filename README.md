# tmin
a simple language to simulate turing machines
(this thing is as of now not even close to a prototype, sorry)

this is meant to act as an interpreter for a simple syntax reminiscent of how turing machines were specified in the original paper by Alan Turing
(see https://www.cs.virginia.edu/~robins/Turing_Paper_1936.pdf) (subroutines and debugging planned for later)

the program uses the following syntax for m-configurations (sorry for the horrendous misuse of angle brackets)
```
<name of m-config>{
  <row>
  <row>
  <however many newline separated rows you want>
}
```

and the following syntax for rows
 ```
 <character> <operations> <final-m-config>
```

where ```<character>``` is either an ascii charachter or a keyword ```any, empty, ...```,
```<operations>``` is a comma separated list of ```L(or l)```(move left), ```R(or r)```(move right), ```N(or n)```(don't move), or ```P(or p)+<ascii char>```(print char)
and ```<final m-config>``` is the name of an m-confguration among the declared ones
