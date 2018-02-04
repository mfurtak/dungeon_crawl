#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;

#define WORLD_W 16
#define WORLD_H 8

#define SPRITE_SIZE 8
#define REPEAT_DELAY 5

typedef struct {
  bool up, down, left, right, a, b, c;
} Inputs;

typedef struct {
  boolean bumped;
  byte world[WORLD_W][WORLD_H];
  byte playerX, playerY; // in game world coords
  int cameraX, cameraY; // in screen coords
} State;

void setup() {
  gb.begin();
  reset();
}

void loop() {
  if (gb.update()) {
    Inputs inputs = handleInput();

    if (inputs.c) {
      reset();
    }
    
    State state = updateState(inputs);
    draw(inputs, state);
  }
}

void reset() {
  gb.pickRandomSeed();
  initState();
  showTitleScreen();
}

