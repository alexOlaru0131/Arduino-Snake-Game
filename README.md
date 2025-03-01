# Snake-Game

Hello! In this project I made the a game in which a snake needs to eat fruits in order to gather points.

For the hardware part I used:
- 4 `buttons`
- an `SSD1306 0.96 inch I2C OLED Display`
- am `Arduino Uno Rev3` Board

They were placed in the following montage:
![alt text](https://github.com/alexOlaru0131/Snake-Game/blob/main/SnakeGame.png)

The program uses the same rules as the Snake Game on Nokia. To control the snake you need to press the buttons which direction (function) you can set by adjusting the code or by rearranging the wires.

The rules are simple. The snake is starting by the length of 1 (unit). The snake needs to eat the fruits. Each time the snake eats a fruit (1 unit), he gets bigger by 1 unit. The snake and fruits are placed randomly on the display. If the snake gets big enough that you will hit it's body with it's head, you will lose the game and restart imeediately a new one.

The code I designed works by these rules, it's not that complicated. You can upgrade it by modifying the looks of the snake and fruit (I wanted to show an apple, but it got too complicated).

https://youtu.be/nMhmNtP8bHk
