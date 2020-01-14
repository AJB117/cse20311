// Patrick Soga
// Lab 13, Section 2
// 15 Dec 2019
// README.txt

This is a Pokemon battle simulator. The user has choice of 6 Pokemon from the first generation. All Pokemon
enter battle at level 100 and have pre-determined stats and moves. Some things to note:

1. Loading the sprites is very slow if the program isn't run on a wired connection or locally. Please be patient
    as the sprites load.
2. This program requires both the simulator and terminal windows to be open. The terminal gives updates on the 
    current battle and prints out the stats and movesets of the involved Pokemon for the user to analyze.
3. If you want to extend this program by adding new Pokemon, you will have to:
    1. Retrieve the RGB values and dimensions of the sprite of the new Pokemon (both front and back sprites)
    2. Put those RGB values into corresponding folders in the sprites folder
    3. Add the new Pokemon in the initializePokemon() function in project.cpp with the dimensions of the
        sprites
4. There are no status moves beyond Recover and Screech. Status conditions like burns and sleep are not implemented.
    There are also no critical hits.