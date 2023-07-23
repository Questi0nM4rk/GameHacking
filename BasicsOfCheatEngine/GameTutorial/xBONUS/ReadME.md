# BONUS

You thought that there are only 3 games to beat... Hah. The is one secret that we need to beat. If you pull up your CE table with all your scripts. You can activate any of them and than look to the top right corner of the game, where its name is displayed.

You will see - integrity check error. This is in some way this games anty-cheat. So lets beat it!

## How to disable

Start by looking for some byte. As this will be most likely a bool. Now what is its initial value 0? 1?... What signals that the game was breached. The initial value is 1. 1 signals that everything is ok. If it switches to 0, than the game is being cheated.

So scan for 1 in Byte. Press next scan a couple of times. Than activate your cheat and scan for 0. Deactivate and scan for 1. Do this until you have like 10 left. Than try to shoot or do something in the game. This will narrow your list down to 1-3 things. You want the one thats being write in by:

`
sete byte ptr [address]
`

This is the one that the game is using. Go and open AOB at this command. And just comment this line out. Like this:

```
code:
  //sete byte ptr [rbx+70]
  cmp byte ptr [rbx+70],00
  jmp return
```

BOOM! You done it. If you activate this and than activate any of your cheats. The game wont know.

The secret is that if you finish all 3 games without the integrity check, you will get a special message at the end.

**Go and cheat it! -QSM**