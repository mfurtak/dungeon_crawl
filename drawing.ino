#define NUM_SPRITES 6

const byte empty[] PROGMEM = {8,8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
const byte player[] PROGMEM = {8,8,0x8,0x1C,0x1C,0x28,0x1C,0xA,0x14,0x14};
const byte playerStep[] PROGMEM = {8,8,0x8,0x1C,0x1C,0xA,0x1C,0x28,0x14,0x14,};
const byte imp[] PROGMEM = {8,8,0x81,0x52,0x3C,0x5A,0x8,0x14,0x0,0x0};
const byte chest[] PROGMEM = {8,8,0x0,0x0,0x7E,0x81,0xFF,0x99,0x81,0xFF};
const byte openChest[] PROGMEM = {8,8,0x0,0x7E,0x81,0xFF,0x7E,0x99,0x81,0xFF};

const byte* sprites[NUM_SPRITES] = {empty, player, playerStep, imp, chest, openChest};

void showTitleScreen() {
  gb.titleScreen(F("Dungeon Crawl"));
}

void draw(Inputs inputs, State state) {
  if (state.bumped) {
    gb.sound.playTick();
  }
  
  gb.display.print(F("X"));
  gb.display.print(state.playerX);
  gb.display.print(F(" Y"));
  gb.display.print(state.playerY);

  gb.display.print(F("  CX"));
  gb.display.print(state.cameraX);
  gb.display.print(F(" CY"));
  gb.display.print(state.cameraY);

  if (inputs.anyMove) {
    gb.display.print(F("  A"));
  }
  
  for(byte y = 0; y < WORLD_H; y++){
    for(byte x = 0; x < WORLD_W; x++){
      byte spriteId = state.world[x][y];
      int xScreen = (x * 8) - state.cameraX;
      int yScreen = (y * 8) - state.cameraY;
      gb.display.drawBitmap(xScreen, yScreen, sprites[spriteId], 0, 0);
    }
  }
}
