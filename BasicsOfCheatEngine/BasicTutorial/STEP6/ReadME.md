# The sixth step

This step is also super important, as it explains poiters. If you did anything in C based languages you did see some pointers. Its just a variable that stores the address of another variable in memory. And we are gonna look for them now.

## How does a pointer work

Lets say we have a variable X. The X needs to be stored somewhere in the computer memory at some address. And this address is stored in the pointer that we are looking for. It very handy when you want to use the same variable for more things. All it does it call a pointer to the main variable memory and use that pointer to access and change the value in it.


## Do it

You have 2 buttons now. One that says *change value* and one that says *change pointer*. Scan for the value with 4-byte as normal. Click change value untill you find what youve been looking for. Add it to your table. Double click the address of the variable you added. Copy the address from it. And now cheat engine want us to do some looking around. But because we know that the value of the pointer we are looking for is the address we copied. Just scan for the address as value in HEX. Look for green text, it means that the address is static - it does not change. Add the green one to your table. Now we gonna tell cheat engine that it is a pointer. Double click on the address of the green pointer. Uncheck Hexadecimal as the value in it is not hexadecimal. Also click pointer in the bottom. Now when you close it. The value from the original variable and this pointer should be the same. Change the value in the pointer to 5000 and freeze is by click in the box on the left of your pointer. Now click change pointer. Because the value is frozen, cheat engine will set it to 5000 when its allocated again. Go next. 