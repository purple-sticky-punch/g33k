// Arduino 3D Maze v0.0 by Hari Wiguna, 2016

#include "U8glib.h"
U8GLIB_PCD8544 u8g(13,11, 9,8,10);    // SPI Com: SCK = 13, MOSI = 11, CS = 9, A0/DataCommand = 8, Reset = 10

u8g_uint_t screenWidth, screenHeight;
u8g_uint_t hInset;
u8g_uint_t vInset;
u8g_uint_t wallHeight;

void DrawMaze()
{
  u8g.drawFrame(0,0, screenWidth,screenHeight);

  wallHeight = screenHeight - vInset - vInset;

  //-- Left Wall --
  u8g.drawLine(0,0, hInset,vInset);
  u8g.drawVLine(hInset,vInset, wallHeight);
  u8g.drawLine(hInset, screenHeight-vInset, 0, screenHeight);

  //-- Right Flat --
  u8g.drawHLine(screenWidth-hInset,vInset, hInset);
  u8g.drawVLine(screenWidth-hInset,vInset, wallHeight);
  u8g.drawHLine(screenWidth-hInset,screenHeight-vInset, hInset);

  //-- Second Right Wall --
  u8g_uint_t hInset2 = hInset + 10;
  u8g_uint_t vInset2 = vInset + 8;
  u8g_uint_t wallHeight2 = screenHeight - vInset2 - vInset2;
  u8g.drawLine(screenWidth-hInset2,vInset2, screenWidth-hInset,vInset);
  u8g.drawVLine(screenWidth-hInset2,vInset2, wallHeight2);
  u8g.drawLine(screenWidth-hInset2,screenHeight-vInset2, screenWidth-hInset,screenHeight-vInset);

  //-- Back wall --
  u8g.drawHLine(hInset,vInset2, screenWidth-hInset-hInset2);
  u8g.drawHLine(hInset,screenHeight-vInset2, screenWidth-hInset-hInset2);
}

void setup(void) {
  u8g.setRot180();  // flip screen
  screenWidth = u8g.getWidth();
  screenHeight = u8g.getHeight();
  vInset = screenHeight/4;
  hInset = screenWidth/4;
}

void loop(void) {
  u8g.firstPage();
  do {
    DrawMaze();
  } while ( u8g.nextPage() );
}
