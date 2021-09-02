#include <iostream>

int x = 0;

void looper()
{
  for(int i=0; i < 4; i++)
  {
    printf("i is %i \n", i);
    if(i > 2) x++;
  }
}

int main()
{
  looper();
  x++;
  return 0;
}
/* command
g++ -g debug.cpp -o debugme
Outputs debugme.exe

Debug
gdb debugme

In gdb
run
break 1
break 9 // Add a breakpoint in the code

print variable
info locals
info stack
info args

next - next line of code
step - follow function calls
continue - resume the program until it hits the next breakpoint or end of the program

Conditional breakpoint

break 9 if i > 2

Watchpoint
*/
