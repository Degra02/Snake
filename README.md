# Snake Game
Snake game written in C++ using SFML.

## How to build

Execute the following command on your terminal
```bash
cmake CmakeLists.txt
```
to create the _Makefile_, then just use 
```bash
make
```
to build the program.

## Font selection
The file ```04B_30_.TTF``` is the font file for the score.  
To change it, include the respective font file on the project directory
and change the file name in this line
```C++
font.loadFromFile("04B_30__.TTF");
```

in ```src/main.cpp```.

