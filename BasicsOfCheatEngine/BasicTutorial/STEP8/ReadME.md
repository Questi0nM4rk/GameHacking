# The eight step

Multi level pointer. This is going to be fun. In this step we are gonna find a pointer that poins to another pointer.

## What is multilevel pointer

("=>" reads as points to)

We already know the standart pointer.

`
Address => Value
`

`
Pointer = Address => Value
`

Now, imagine a scenario where you have a pointer pointing to another pointer, which in turn points to the actual data. This is a multi-level pointer. Each level of indirection adds an extra layer of indirection to reach the final value.

This is what it would look like in code.
```
int value = 42;
int* pointer1 = &value;
int** pointer2 = &pointer1;
```

But, we have 4-level pointer. That means that there are 4 pointers before we get to our value. The only problem is that we know the value and not the first pointer. So we need to go agains the stream of the pointers. This may be a little defficult at first so here is a table that you can copy.


>Address5 = Value = (your value)<br>
>base ptr => address4 + offset4 = address5<br>
>base ptr => address3 + offset3 = address3<br>
>base ptr => address2 + offset2 = address2<br>
>static base => address1 + offset1 = address1<br>

In this table you can replace the stuff from top to bottom and see how the pointers follow up.

## Do it

Now that you understand what the multilevel pointer is. Lets do this step. Scan for your value in 4-byte. Once you find it add it to the table. The first address - **address5**, will be the address of your value. Copy and paste it in your table. Go and find what acceses that address as there youll find the first offset.

Mine looks like this:

`
mov [esi+18], eax
`

If you have more than one instruction. Just look in the [ ] as there is the offset and thats all we need. In my case the offset is **18**. So lets put **offset4** in to the table. And now because we are going agains the stream we need to sub the offset instead of adding it. So pull out your calc and go into programmer. Select Hex, paste in your address and sub the offset. Be aware that the calc gives your the Hex with spaces and cheat engine does not like spaces in Hex. So just remove them.

Now that we have the address that the pointer points to. Lets scan for that value. So select Hex and paste the new address in it to scan for. If you scan for the value and more than one results pop up. Just change the value more times and press next scan. If this won help, you just need to go one by one (but its gonna be the last one most of the times) and add them to your table where you can find what acceses this address. If nothing happent in the debuger after you pressed the change value, its not it. Once you found your pointer add it to your table and remove the rest. I advise renaming them inside the cheat engine by double clicking on the name of it. 

My table looks like this now:

>01A54C30 = Value = (your value)<br>
01A54BD8 => 1A54C18 + 0x18 = 01A54C30<br>
base ptr => address3 + offset3 = 01A54BD8<br>
base ptr => address2 + offset2 = address2<br>
static base => address1 + offset1 = address1<br>

Now just repeat this untill you find your green static address. If you encounter that there is nothing inside the [ ] like no +, it means that there is no offset and you can just use the current address.

My final table looks like this:

>01A54C30 = Value = (your value)<br>
01A54BD8 => 1A54C18 + 18 = 01A54C30<br>
01A4C734 => 01A54BD8 + 0 = 01A54BD8<br>
01A6AE8C => 1A4C720 + 14 = 01A4C734<br>
"Tutorial-i386.exe"+2566E0 => 1A6AE80 + 0x0C = 01A6AE8C<br>