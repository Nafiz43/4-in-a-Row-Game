# 4-in-a-Row-Game


## Game board Design:
For designing the game board, we have taken a two dimensional vector of integer. Human agent will put ‘1’ on the board and AI agent will put ‘2’ on the board. Later on, while representing, ‘1’ is converted to ‘O’ and ‘2’ is converted to ‘X’. We have considered standard board size in this game which is 6x7.

<table class="tg">
<thead>
  <tr>
    <th class="tg-ev0v">   <br>Serial   </th>
    <th class="tg-ev0v">   <br>Agent   </th>
    <th class="tg-ev0v">   <br>Assigned on board   </th>
    <th class="tg-ev0v">   <br>Represented on board   </th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-0pky">&nbsp;&nbsp;&nbsp;<br>1.&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-0pky">&nbsp;&nbsp;&nbsp;<br>Human&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-0pky">&nbsp;&nbsp;&nbsp;<br>1&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-0pky">&nbsp;&nbsp;&nbsp;<br>‘O’&nbsp;&nbsp;&nbsp;</td>
  </tr>
  <tr>
    <td class="tg-0pky">&nbsp;&nbsp;&nbsp;<br>2.&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-0pky">&nbsp;&nbsp;&nbsp;<br>AI&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-0pky">&nbsp;&nbsp;&nbsp;<br>2&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-0pky">&nbsp;&nbsp;&nbsp;<br>‘X’&nbsp;&nbsp;&nbsp;</td>
  </tr>
</tbody>
</table>

![image](https://user-images.githubusercontent.com/43680716/85220002-0f51b480-b3ca-11ea-8fa5-d94ae237cc98.png)

fig: Representation of the Game Board

## Evaluation Function:
For cutting the adversarial search after a certain level of the search tree, we have designed an evaluation function. For each move, AI agent will look for depth of five. Then after reaching that level, evaluation function will be called. We assigned value for each possible set of four elements of the board taken from horizontally, vertically and diagonally. By summing up values of all possible sets, we obtained an evaluation value for each state and by this way AI agent don’t need to go the terminal state to determine the utility value of a state.
The criterion on which value is assigned to each of the set is attached below:

<table class="tg">
<thead>
  <tr>
    <th class="tg-amwm">&nbsp;&nbsp;&nbsp;<br>Serial&nbsp;&nbsp;&nbsp;</th>
    <th class="tg-amwm">&nbsp;&nbsp;&nbsp;<br>AI piece&nbsp;&nbsp;&nbsp;</th>
    <th class="tg-amwm">&nbsp;&nbsp;&nbsp;<br>Human piece&nbsp;&nbsp;&nbsp;</th>
    <th class="tg-amwm">&nbsp;&nbsp;&nbsp;<br>Empty piece&nbsp;&nbsp;&nbsp;</th>
    <th class="tg-amwm">&nbsp;&nbsp;&nbsp;<br>Score&nbsp;&nbsp;&nbsp;</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>1.&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>4&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>0&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>0&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>100000&nbsp;&nbsp;&nbsp;</td>
  </tr>
  <tr>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>2.&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>3&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>0&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>1&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>1000&nbsp;&nbsp;&nbsp;</td>
  </tr>
  <tr>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>3.&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>2&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>0&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>2&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>100&nbsp;&nbsp;&nbsp;</td>
  </tr>
  <tr>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>4.&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>1&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>0&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>3&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>10&nbsp;&nbsp;&nbsp;</td>
  </tr>
  <tr>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>5.&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>0&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>0&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>4&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>5&nbsp;&nbsp;&nbsp;</td>
  </tr>
  <tr>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>6.&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>0&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>4&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>0&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>-100000&nbsp;&nbsp;&nbsp;</td>
  </tr>
  <tr>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>7.&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>0&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>3&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>1&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>-1000&nbsp;&nbsp;&nbsp;</td>
  </tr>
  <tr>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>8.&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>0&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>2&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>2&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>-100&nbsp;&nbsp;&nbsp;</td>
  </tr>
  <tr>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>9.&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>0&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>1&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>3&nbsp;&nbsp;&nbsp;</td>
    <td class="tg-baqh">&nbsp;&nbsp;&nbsp;<br>-10&nbsp;&nbsp;&nbsp;</td>
  </tr>
</tbody>
</table>

First row depicts, if AI have four pieces in the set, then score 100000 will be assigned. In second row, AI have three pieces and one piece is empty, for this 1000 score will be assigned to this set.
