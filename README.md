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
<figure>
  <figcaption><i>Loading animation at the beginning</i></figcaption>
  <img src="https://user-images.githubusercontent.com/114214103/195540071-65dc23a8-e3c6-4e6c-b549-8e1178119245.png" alt="Loading animation">
  <figcaption><i>Main menu</i></figcaption>
  <img src="https://user-images.githubusercontent.com/114214103/195545299-af88cfff-0258-497b-a1b2-f0a156b54cfd.png" alt="Main menu">
  <figcaption><i>Enter player's name</i></figcaption>
  <img src="https://user-images.githubusercontent.com/114214103/195546943-6f58438b-0ce8-4ca6-b4ea-8b08bd22f31c.png" alt="Player's name">
  <figcaption><i>Gameplay</i></figcaption>
  <img src="https://user-images.githubusercontent.com/114214103/195549011-9b10b2f9-d6ad-4cce-b7b1-17b1a9fd1f74.png" alt="Gameplay">
  <figcaption><i>How to play</i></figcaption>
  <img src="https://user-images.githubusercontent.com/114214103/195549803-1cc6234e-b346-42fc-a9f8-a66bcf10aa54.png" alt="How to play">
  <figcaption><i>Settings</i></figcaption>
  <img src="https://user-images.githubusercontent.com/114214103/195550715-f0f9ca9c-1571-4f82-8774-9bc54d61af39.png" alt="Settings">
</figure>

<h3>III. References:</h3>
<a href="https://codelearn.io/sharing/windowsh-va-ham-dinh-dang-console-p1" target="_blank">Windows.h and console formatting function - part 1(Codelearn.io).</a><br/>
<a href="https://codelearn.io/sharing/windowsh-ham-dinh-dang-noi-dung-console" target="_blank">Windows.h and content formatting functions - part 2(Codelearn.io).</a>
