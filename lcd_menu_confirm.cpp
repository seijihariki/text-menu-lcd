#include "lcd_menu_confirm.h"

lcdmenu::confirm::confirm (String _label, screen* sc, LCD* _lcd, screen* par) : onconf(sc), label(_label), select(false), inside(false), screen(par, _lcd)
{
}

void lcdmenu::confirm::handle_input (char input)
{
    if(inside) {onconf->handle_input(input); return;}
    switch (input)
    {
    case 0:
    case 2:
        select = !select;
        break;
    case 1:
        {
            if(select) inside = true;
            else parent->goback();
        }
        break;
    case 3:
        {
            parent->goback();
        }
        break;
    }
}

void lcdmenu::confirm::draw ()
{
    if(inside) {onconf->draw(); return;}
    
    lcd->write(label, 0, 0);
    
    for(int k = label.length(); k < lcd->w; k++) lcd->write(" ");
    lcd->move(0,1);
    lcd->move(3,1);
    for(int k = 3; k < lcd->w/2; k++) lcd->write(" ");
    lcd->move(lcd->w/2 + 2,1);
    for(int k = lcd->w/2 + 2; k < lcd->w; k++) lcd->write(" ");
    
    lcd->write("Yes", 0, 1);
    lcd->write("No", lcd->w/2, 1);
    
    lcd->write("X", select?4:(lcd->w/2 + 3), 1);
}

void lcdmenu::confirm::goback ()
{
    inside = false;
}

