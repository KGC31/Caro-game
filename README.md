<h1>CARO GAME - HCMUS PROGRAMMING TECHNIQUE PROJECT</h1>

<h3>I. Introduction:</h3>
<p>
<i>Caro game</i> (<i>Tic Tac Toe</i> in American English) is a two-player game that can be traced back to ancient Egypt dating from around 1300 BC, where similar board found on roofing tiles. An early variant of the game called <i>terni lapilli</i> was played during the Roman Empire, around the first century BC. Other related game are <i>three men's morris</i> and <b>Puebloans</b> game, <i>Picaria</i>.
</p>

<p>
<i>Caro game</i> is played on ten-by-ten grid (three-by-three for <i>Tic Tac Toe</i>) with two symbols are <i>X</i> and <i>O</i>, representing player 1 and player 2 moves on the board. Players take turns to make their moves on the board, who ever has <b>five-in-a-row</b> horizontal, vertical or diagonal first is the winner. If the board is full and there is no winner, that game will be a <i>tie-game</i>.
</p>

<p>
This is a HCMUS programming project of Programming Technique, written in C++ by 21127333-Nguyen Viet Kim, student of class 21CLC08.
</p>
<h3>II. Desciption:</h3>

<h4>II.1. Files organization:</h4>
<p>
<i>Caro game</i> project includes 7 .cpp files for different sections of functions:
</p>
<ul>
  <li><b>Caro.cpp</b>: Includes <i>Loading...</i> animation and main function in which console-formatting functions are deployed in order to format console window, play music and display main menu.</li>
  <li><b>Main menu.cpp</b>: Display game's text logo and menu for users to choose. This includes: <i>Play Game, How to play, Settings</i> and <i> Exit.</i></li>
  <li><b>Gameplay.cpp</b>: This file contains login function, game board generating function, sideboard generating function, cursor move function, after-game menu function, and is connected with <i>Win_check.cpp</i> for checking winning condition.</li>
  <li><b>Win_check.cpp</b>: This is where line checking functions are placed to check if there is a winner. It includes functions for checking horizontal, vertical and diagonal line of five. The main checking function return true if there is a winner, false on the other hand, and send the result to Gameplay function.</li>
  <li><b>How to play.cpp</b>: Display HOW TO PLAY text and instructions for playing.</li>
  <li><b>Settings.cpp</b>: Display SETTINGS text and give players option of theme(dark/ light mode) and music(on/ off).</li>
  <li><b>Windows functions.cpp</b>: Contains function that used for resizing console window, actions with cursor and changing text's color.</li>
</ul>
<p>
Further desciptions of function uses are commented in each files, at the top of each function.
</p>

<h4>II.2. Game preview:</h4>
![Screenshot (165)](https://user-images.githubusercontent.com/114214103/195540071-65dc23a8-e3c6-4e6c-b549-8e1178119245.png)
