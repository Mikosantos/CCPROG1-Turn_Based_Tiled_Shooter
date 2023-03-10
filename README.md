<h1 align="center">
CCPROG1_Turn Based Tiled Shooter

(Logic Formulation and Introductory Programming)

   <img width="122" alt="ccprog1_mp" src="https://user-images.githubusercontent.com/92857538/215101132-bee34d42-e1dc-4ac0-a72c-6d91c888e93d.png">
</h1>

**About**:   
   - Tile-based shooters are shooting games where the player's movement is restricted to specific spaces. 
   - For this project, the user is the player and the player can either move left, or right, or shoot every turn. 
   - After the player makes a move, the enemy’s turn begins and they can move based on a simple pattern. 
   - To simplify the movement, both enemies and the player will move in a simple tile-based manner. There are 4 columns that the player and enemies can move from. The enemy has 5 rows they can move down from. 
   - The player can only move horizontally and will move one tile per movement. 
   - Firing the laser will destroy only one enemy in the same column. The player cannot move and fire the laser on the same turn. 
   - Whenever an enemy is defeated, the player scores 10 points. Enemies spawn from the top of the map and will move right, down, left, and down in a cycle. When the player reaches a score of 100 points, the player has won. Otherwise, If the enemies reach the bottom of the map, the player has lost.


**To run**:

   - Download any IDE; VsCode or DevC++ suffices.
   - Download, install, and run gcc compiler. There are many tutorials on how-tos on YouTube. 
   - Use "gcc -Wall MP.c -o run.exe" for Windows.

