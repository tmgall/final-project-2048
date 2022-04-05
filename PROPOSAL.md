# Final Project Proposal

## Project and Motivation

The project I would like to do is to create a working version of the game 2048 in Cinder. This is a simple mobile game that consists of a 4x4 grid with tiles of different values, all of which are powers of 2. The goal is to combine tiles of the same value and create a higher power of 2 (e.g. two 8 tiles combine to create a 16 tile) and ultimately create a 2048 tile. I have background knowledge including how the game progresses as well as some strategies that are effective in the game. I would like to do this project because I've played 2048 for a long time and always thought that it would be a fun game to implement myself, especially if I want to add extra features to make the game more interesting. For that reason, I already have ideas on possible expansions to the game. 

## Timeline

By Week 1, I complete the Cinder engine that will run the game. This may take a bit more time than on previous MPs because I will need to build it from scratch and figure out how to make my window the appropriate size, compensate for lag by changing the frame rate, etc. I also need to learn how to handle keyboard input because the main inputs of 2048 are the arrow keys. By the end of this week, I should be able to run the Cinder program and have an output in the window, even if it doesn't do anything. 

By Week 2, I finish the internal game logic and its testing. This will involve simplifying the state of the game down to several vectors in an efficient way and developing algorithms that calculate updated game state based on certain moves. This stage will involve a significant amount of testing so that I can most successfully scale my code. Ideally, I could play a very simplified version of the game in the terminal or with a rudimentary UI to ensure that the game logic functions properly. 

By Week 3, I finalize the UI in Cinder and integrate it with the Cinder engine developed in Week 1. This part will require more creativity, as I will need to find an effective way to display the game, the current score, and any other information as a UI. This will also require more testing at a smaller scale to ensure that the structure of the code behind the scenes is functionally correct. 

By Week 4, I complete all documentation, instructions, commenting, testing, and add any additional features given extra time. I will also have friends play the game from my computer as a sort of beta test to ensure that a generic user would easily run and play the game. As this is a final project worth a higher percentage of my grade, I will spend more time validating my work, adding comments, and checking for redundancies or unclear code. 


## Additional Ideas

Here are a few ideas for expansions to the game that I could implement if I finish the above too quickly:

-Create functionality that modifies the board size, so I could create boards of size 5x5, 16x16, etc. instead of 4x4.

-Add a menu screen so that the users feels more like they're playing a game rather than running a program.

-Create a bot that can play the game on its own.

-Develop a way to save a game to a file so that it can be replayed.
