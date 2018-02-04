Inputs handleInput() {
  Inputs inputs;
  
  inputs.up = gb.buttons.pressed(BTN_UP) || gb.buttons.repeat(BTN_UP, REPEAT_DELAY);
  inputs.down = gb.buttons.pressed(BTN_DOWN) || gb.buttons.repeat(BTN_DOWN, REPEAT_DELAY);
  inputs.left = gb.buttons.pressed(BTN_LEFT) || gb.buttons.repeat(BTN_LEFT, REPEAT_DELAY);
  inputs.right = gb.buttons.pressed(BTN_RIGHT) || gb.buttons.repeat(BTN_RIGHT, REPEAT_DELAY);
  inputs.anyMove = inputs.up || inputs.down || inputs.left || inputs.right;
  inputs.a = gb.buttons.pressed(BTN_A);
  inputs.b = gb.buttons.pressed(BTN_B);
  inputs.c = gb.buttons.pressed(BTN_C);

  return inputs;
}
