# The seventh step

Our first code injection. In this step we will lear a little bit of assembly. As the cheat engine has a disassembler that lets you inject your own code the process.

## Basic assembly

Assembly language is considered the most low-level programming language out there. It's like the raw form of instructions that computers understand, easily convertible into binary code. The fascinating thing about assembly is that it allows you to have direct access to the hardware itself. You get to tinker with the inner workings of a computer, manipulating system resources with precision. I highly advise to learn some basics.

Here are some basic assembly commands that may be usefull.

| Command | Meaning                                       | Usage                                         |
|---------|-----------------------------------------------|-----------------------------------------------|
| MOV     | Move (copies value from source to destination)| MOV destination, source                       |
| ADD     | Addition (adds source to destination)          | ADD destination, source                       |
| SUB     | Subtraction (subtracts source from destination)| SUB destination, source                       |
| CMP     | Compare (compares values of operands)          | CMP operand1, operand2                        |
| JMP     | Jump (unconditionally jumps to a specified destination)| JMP destination                        |
| JE      | Jump if Equal (jumps if the previous comparison was equal) | JE destination                     |
| JNE     | Jump if Not Equal (jumps if the previous comparison was not equal)| JNE destination               |
| LOOP    | Loop (repeats instructions a specified number of times)| LOOP label                                |
| AND     | Logical AND (performs a bitwise AND operation on the operands)| AND destination, source           |
| OR      | Logical OR (performs a bitwise OR operation on the operands)| OR destination, source             |
| XOR     | Logical XOR (performs a bitwise XOR operation on the operands)| XOR destination, source           |
| INC     | Increment (increments the value of the destination operand)| INC destination                      |
| DEC     | Decrement (decrements the value of the destination operand)| DEC destination                      |
| CALL    | Call Subroutine (calls a subroutine or function) | CALL subroutine                           |
| RET     | Return (returns from a subroutine)              | RET                                          |


## Do it

All we need to do in this step is to change the hit me functionality from removeing 1 hp to adding 2 hp. As always find the value. Add it to the table. Find out what writes to this address. Now something new. Stop the debugger and click on the command that writes to it. Press "Ctrl+d" to open in it disassembler. Than click "Ctrl+a" to open assembler to write code. Than press "Ctrl+shift+a" to make a AOB injection that can be used again after closing the process. Look at the code and try to figure out what it does.

```
newmem:

code:
  sub dword ptr [ebx+000004A4],01 // removes 1 from HP offset
  jmp return // jumps to return

INJECT:
  jmp newmem
  nop 2
return:
registersymbol(INJECT)

[DISABLE]

INJECT:
  db 83 AB A4 04 00 00 01

unregistersymbol(INJECT)
dealloc(newmem)
```

Now all we need to do is to replace the *sub* with *add* and the *01* with *02*. Be aware that you need to have the 0 before the numbres as it tells the assembly that it is a byte.

```
newmem:

code:
  add dword ptr [ebx+000004A4],02 // removes 1 from HP offset
  jmp return // jumps to return

...
```

After you changed it. Click the *File* at the top left and click *Assign to current cheat table* - this will add this script to your cheat table to activate when you want. Now close all the windos. No need to save it, because its saved in out cheat table. After you closed it all. Activate the script by clicking on the box on the left. When you done that, you can proceed to clicking *Hit me*. **Deactivate the script and Go next**.