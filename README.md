# Snake-Game

Hello! In this project I made the a game in which a snake needs to eat fruits in order to gather points.

For the hardware part I used:
- 4 `buttons`
- an `SSD1306 0.96 inch I2C OLED Display`
- am `Arduino Uno Rev3` Board

They were placed in the following montage:
![alt text](https://github.com/alexOlaru0131/Snake-Game/blob/main/SnakeGame.png)

In the software part, the display uses the `SPI communication protocol` and it displays the snake on each unit of length as a filled sqaure and tge fruits as filled circles. The snake can't hit the walls as it will just appear in the opposite part of the screen when going in the margin. As the snake eats each fruit, he will increase in size by one unit. If the snake collides with himself, the game will reset. The fruits are placed randomly on the map.

https://youtu.be/nMhmNtP8bHk
