#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define screenWidth 128
#define screenHeight 64
Adafruit_SSD1306 display(screenWidth, screenHeight, &Wire, -1);

#define sButtonUp 8
#define sButtonDown 9
#define sButtonLeft 10
#define sButtonRight 11

int buttonUp = 0;
int buttonDown = 0;
int buttonLeft = 0;
int buttonRight = 0;

const int rows = 8;
const int cols = 16;
int snakeX = cols / 2;
int snakeY = rows / 2;
int fruitX = 0;
int fruitY = 0;
int direction = 0;

const int maxLength = 64;
int snakeLength = 1;
int snakeSegmentsX[maxLength];
int snakeSegmentsY[maxLength];

bool gameOver = false;

int score = 0;

void setup() {
  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  pinMode(sButtonUp, INPUT);
  pinMode(sButtonDown, INPUT);
  pinMode(sButtonLeft, INPUT);
  pinMode(sButtonRight, INPUT);

  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(1);      
  display.setTextColor(SSD1306_WHITE); 
  display.setCursor(0,0);     
  display.println("Snake Game!"); 
  display.display();
  delay(2000);

  randomSeed(analogRead(0));
  placeFruit();

  snakeSegmentsX[0] = snakeX;
  snakeSegmentsY[0] = snakeY;
}

void loop() {
  if (!gameOver) {
    buttonUp = digitalRead(sButtonUp);
    buttonDown = digitalRead(sButtonDown);
    buttonLeft = digitalRead(sButtonLeft);
    buttonRight = digitalRead(sButtonRight);

    if (buttonUp == HIGH && direction != 3) {
      direction = 1;
    }
    else if (buttonDown == HIGH && direction != 1) {
      direction = 3;
    }
    else if (buttonLeft == HIGH && direction != 0) {
      direction = 2;
    }
    else if (buttonRight == HIGH && direction != 2) {
      direction = 0;
    }

    moveSnake();
    checkCollision();
    checkEatFruit();
    display.clearDisplay();
    drawSnake();
    drawFruit();
    display.display();
    delay(200);
  } else {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(5, 20);
    display.println("Game Over!");
    display.display();
    delay(2000);

    resetGame();
  }
}

void moveSnake() {
  int prevX = snakeX;
  int prevY = snakeY;

  switch (direction) {
    case 0:
      snakeX++;
      break;
    case 1:
      snakeY--;
      break;
    case 2:
      snakeX--;
      break;
    case 3:
      snakeY++;
      break;
  }

  if (snakeX < 0) {
    snakeX = cols - 1;
  }
  else if (snakeX >= cols) {
    snakeX = 0;
  }
  
  if (snakeY < 0) {
    snakeY = rows - 1;
  }
  else if (snakeY >= rows) {
    snakeY = 0;
  }

  for (int i = snakeLength - 1; i > 0; i--) {
    snakeSegmentsX[i] = snakeSegmentsX[i - 1];
    snakeSegmentsY[i] = snakeSegmentsY[i - 1];
  }

  snakeSegmentsX[0] = snakeX;
  snakeSegmentsY[0] = snakeY;
}

void placeFruit() {
  fruitX = random(0, cols);
  fruitY = random(0, rows);
}

void drawSnake() {
  for (int i = 0; i < snakeLength; i++) {
    display.fillRect(snakeSegmentsX[i] * 8, snakeSegmentsY[i] * 8, 8, 8, SSD1306_WHITE);
  }
}

void drawFruit() {
  display.fillCircle(fruitX * 8 + 4, fruitY * 8 + 4, 4, SSD1306_WHITE);
}

void checkCollision() {
  for (int i = 1; i < snakeLength; i++) {
    if (snakeX == snakeSegmentsX[i] && snakeY == snakeSegmentsY[i]) {
      gameOver = true;
      return;
    }
  }
}

void checkEatFruit() {
  if (snakeX == fruitX && snakeY == fruitY) {
    snakeLength++;
    placeFruit();
  }
}

void resetGame() {
  gameOver = false;
  snakeX = cols / 2;
  snakeY = rows / 2;
  snakeLength = 1;
  direction = 0;
  placeFruit();
}
