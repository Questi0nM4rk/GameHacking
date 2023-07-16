# The first game

The challange of the first game is that when ever you are about to kill the enemy. He will gain imunity and regain his HP back. This happens right before you shoot your last shot.

## First part

Lets scan for this value. Do not scan for the number that you see on screen. Scan for shots fired and save yourself some time. Now that we have the shots fired. We need to find out what writes to this and how it works. If you look at it, youll see that there is this code:

```
add dword ptr [rbx+6C],01
```

This means that each time you shoot, 1 is added to a variable *shots fired*.

## Second part

Now that we have the somethig to overwrite, lets go inject some code. Go and open the disassembler into the auto assembler and the AOB injection. Once you done that, the only thing you need to do is change the 1 to a 0. And you done the first level.

```
newmem:

code:
  add dword ptr [rbx+6C],00     // you can just comment it out too
  mov [rbx+70],rsi
  jmp return

INJECT:
  jmp newmem
  nop 3
return:
registersymbol(INJECT)
```

## Bonus

If you want to do ONESHOT with this infinite ammo too. We can scan for unknown initial value. And than each time you hit the enemy, scan for decreased value. Once you found it. Go and look what writes to it. You will find something like this:

```
mov [rax+70],edx
```

This just means its moving the new HP amount into the HP variable. Go to the disassembler and with it open your script from earlier. Make sure that you have selected the right command in the memory viewer and that you are clicked inside your script. Now just select AOB injection and it will add new INJECT part to your current script. 

All you need to do for the ONESHOT is to change the edx to 00. As this means whenever you shoot it. Its new HP will go to 0.

```
[ENABLE]

aobscanmodule(INJECT,gtutorial-x86_64.exe,83 43 6C 01 48 89 73 70) // should be unique
alloc(newmem,$1000,INJECT)

label(code)
label(return)

newmem:

code:
  add dword ptr [rbx+6C],00
  mov [rbx+70],rsi
  jmp return

INJECT:
  jmp newmem
  nop 3
return:
registersymbol(INJECT)

//---------------------------------------------

aobscanmodule(INJECT2,gtutorial-x86_64.exe,89 50 70 48 83 78 68 00) // should be unique
alloc(newmem2,$1000,INJECT2)

label(code2)
label(return2)

newmem2:

code2:
  mov [rax+70],00
  cmp qword ptr [rax+68],00
  jmp return2

INJECT2:
  jmp newmem2
  nop 3
return2:
registersymbol(INJECT2)

[DISABLE]

INJECT:
  db 83 43 6C 01 48 89 73 70

unregistersymbol(INJECT)
dealloc(newmem)

```

## Go next

Just add this script to your cheat table and activate it. And window should pop up. Well done go next.