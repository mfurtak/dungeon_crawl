State state;

void initState() {
  state.bumped = false;
  state.cameraX = 0;
  state.cameraY = 0;
    
  byte itemId = random(2, NUM_SPRITES);
  
  byte itemX = random(0, WORLD_W);
  byte itemY = random(0, WORLD_H);
  
  state.playerX = itemX;
  state.playerY = itemY;

  while (state.playerX == itemX) {
    state.playerX = random(0, WORLD_W);
  }
  while (state.playerY == itemY) {
    state.playerY = random(0, WORLD_H);
  }
  
  for (byte y = 0; y < WORLD_H; y++){
    for (byte x = 0; x < WORLD_W; x++){
      if (x == state.playerX && y == state.playerY) {
        state.world[x][y] = 1;
      } else if (x == itemX && y == itemY) {
        state.world[x][y] = itemId;
      } else {
        state.world[x][y] = 0;
      }
    }
  }
}

State updateState(Inputs inputs) {
  state.bumped = false;
  
  updatePlayer(inputs);
  updateCamera();

  return state;
}

void updatePlayer(Inputs inputs) {
  state.world[state.playerX][state.playerY] = 0;
  
  if (inputs.up) {
    if (state.playerY > 0) {
      state.playerY -= 1;  
    } else {
      state.bumped = true;
    }
  }
  if (inputs.down) {
    if (state.playerY < WORLD_H - 1) {
      state.playerY += 1;
    } else {
      state.bumped = true;
    }
  }
  if (inputs.left) {
    if (state.playerX > 0) {
      state.playerX -= 1;
    } else {
      state.bumped = true;
    }
  }
  if (inputs.right) {
    if (state.playerX < WORLD_W - 1) {
      state.playerX += 1;
    } else {
      state.bumped = true;
    }
  }

  state.world[state.playerX][state.playerY] = 1;
}

void updateCamera() {
  //target position of the camera for the cursor to be centered
  int cameraXTarget = (state.playerX * 8) - (LCDWIDTH / 2) + 8;
  int cameraYTarget = (state.playerY * 8) - (LCDHEIGHT / 2) + 8;
  //apply the target coordinate to the current coordinates with some smoothing
  state.cameraX = (state.cameraX*3 + cameraXTarget)/4;
  state.cameraY = (state.cameraY*3 + cameraYTarget)/4;
}

byte clamp(byte value, byte minimum, byte maximum) {
  return max(min(value, maximum), minimum);
}

