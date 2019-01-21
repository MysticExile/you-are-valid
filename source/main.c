#include <stdio.h>
#include <string.h>

#include <switch.h>

int main(int argc, char **argv) {
  // Initialize console. Using NULL as the second argument tells the console
  // library to use the internal console structure as current one.
  consoleInit(NULL);

  // Move the cursor to row 16 and column 20 and then prints "Hello World!"
  // To move the cursor you have to print "\x1b[r;cH", where r and c are
  // respectively the row and column where you want your cursor to move
  printf("\x1b[5;1HPress A for love"
         "\x1b[6;1HPress B for love"
         "\x1b[7;1HPress X for love"
         "\x1b[8;1HPress Y for love"
         "\x1b[9;1HPress L to clear the console");

  while (appletMainLoop()) {
    // Scan all the inputs. This should be done once for each frame
    hidScanInput();

    // hidKeysDown returns information about which buttons have been just
    // pressed (and they weren't in the previous frame)
    u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
    if (kDown & KEY_A) {
      printf("\nYou are valid <3 ");
    }

    if (kDown & KEY_B) {
      printf("\nYou are loved <3 ");
    }

    if (kDown & KEY_X) {
      printf("\nOnly you define who you are, let no one else mold you into "
             "something or someone you're not <3 ");
    }

    if (kDown & KEY_Y) {
      printf("\nIf you're in a hard spot right now just know that there are "
             "\nbetter times ahead <3 ");
    }

    if (kDown & KEY_L) {
      consoleClear();
      printf("\x1b[5;1HPress A for love"
             "\x1b[6;1HPress B for love"
             "\x1b[7;1HPress X for love"
             "\x1b[8;1HPress Y for love"
             "\x1b[9;1HPress L to clear the console");
    }

    if (kDown & KEY_PLUS)
      break; // break in order to return to hbmenu

    consoleUpdate(NULL);
  }

  consoleExit(NULL);
  return 0;
}
