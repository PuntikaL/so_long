# So_long is a project from 42 Cursus
> which is to create a small 2D Game using the MiniLibX Graphics Library
## How To Install?
This project need MiniLibx to run.
After you downloaded the library, use a command
```
 make
```
to compile files
Then run with ./so_long followed by the map:
```
./so_long sample_map.ber
```
Because I kinda forgot, tbh. So, if this's not working, the program will return a guide of input pattern for you. Don't worry!<br>
P.S. No bonus version here

## How to play
I would like to name the game as **Bunny adventure**<br>
you could see the rabbit character, (Sorry I didn't capture the screen. If you run this, please feel free to send picture via my email. I would appreciate that a lot luv)<br>
apple trees, barrels, stones, and a chest.<br>
- The barrels and stones are obstracle here, the rabbit couldn't pass through. They're represented as "1" in .ber files
- The apple trees are source of rabbit's energy. He need to keep all of them to feed his family. Represented as "C" in .ber files
- Once all the apples are collected, the chest will open for Mr. Rabbit to jump in and escape from this yard. Represented as "E" in .ber files
- The grass tiles are the same wheter it has flower or not (I use a basic random technique). Represented as "0" in .ber files
- The rabbit is the player's character represented as "P"

## My Logic
As a warning for you, my fellow cadet. My logic is quite different and could make you stuck while trying to make a bonus part. But at the same time, this could be considered as easy and time-saving method.
The logic behind this is simple. Once I make my move, I repaint on block that I move to and move from. Basicly switch or redraw them. Therefore, at a time, I redraw only 2 tile instead of all the map.
You could imagin about the pros and cons of it now. <br>
Good luck, mate

## Almost forgot
If the input map is invalid, the program will output so. If the player can't collect all the keys (apples) in order to open the exit gate (chest), the map also will be considered as invalid map.
Flood fill technique is used to check this.


