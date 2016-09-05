#include "lcd_menu.h"

lcdmenu::LCD::LCD (int sx, int sy) : w(sx), h(sy)
{
}

lcdmenu::screen::screen (screen* par, LCD* _lcd) : parent(par), lcd(_lcd)
{
}

void lcdmenu::screen::setParent (screen *par)
{
    parent = par;
}

