** Simple 'cat' implementation **
* gcc -g cat.c -o cat
  * -g generates source level debug information for gdb
  * -o to specify the output executable name
* ./cat <input>
* gdb cat
* run
* run stdinput
* run < input.txt
  * feed stdin into gdb
* b cat.c:line_number
  * set breakpoint
* d index
  * delete breakpoint with index
* info b
  * display all breakpoints
* bt
  * backtrace upon error
* p
  * print something
* continue
  * continue until the next breakpoint
* next/step
  * both execute the next line of code and stop
  * if next line to be executed is a function call, n executes the entire function, but s steps into the function and
    stops after first line.
