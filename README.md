# Machine Learning tic-tac-toe
![image](https://user-images.githubusercontent.com/24864674/109415060-b6a1d500-79b6-11eb-9d22-c24bda89fdb6.png)

This repository is the perfect example to understand a basic implementation of machine learning in video games.


## GENERATING A DATASET
To generate a dataset for the AI, you need to build the program, and use the UI in terminal to launch a training session.
Each training session can use the last dataset, or create a new one from nothing.

Each training session is done on 1000000 games, so it may take 10-15 minutes to finish.
*(I was too lazy to multithread the whole system, and it would make the code harder to read)*

Once a dataset is generated, you can see the results in the file called *InstanceOne.txt* and it should look a bit like this:
```
X_OOOXX_O : 0 0 0 0 0 0 0 -1 0
XXO_O_XOO : 0 0 0 0 0 -1 0 0 0
XOXXO_O_O : 0 0 0 0 0 -1 0 0 0
X__XO_O_O : 0 0 -1 0 0 0 0 -1 0
___XO___O : -2 -2 -2 0 0 -2 -2 -3 0
__X__OOXO : -1 0 0 -1 0 0 0 0 0
```
##### Quick explanation on how the data is organised:
- The left part of each line represent the state at which was the map when the AI had to play.
- The right part of each line represents the score of each cell.
- You may see a lot of zero, and this is normal. There is an issue with data redundancy because you can't play on an already occupied cell

## HOW DOES IT WORK ?
For the non-tech savy navigating here on github *(shame on you)* this AI trains itself by storing its actions for each turn, and applies a score once it lost or won.
When possible, it uses the highest scored cell to play on, in hopes it will win.

## BUILDING
The code was build on Lubuntu 20.04 with QTCreator 5.12.X.

Building on windows isn't possible at the moment, since the InputUtils (and part of the DisplayUtils) are tailored for linux only.

## CONTRIBUTING
If you wish to contribute, great !
You can do a small or big contributions through pull requests
