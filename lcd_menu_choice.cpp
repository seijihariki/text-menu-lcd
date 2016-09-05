#include "lcd_menu_choice.h"



lcdmenu::choice::choice (int mitem, LCD* _lcd, screen* par) : maxit(mitem), vtop(0), 
    select(0), state(false), 
    inside(-1), itemcnt(0),
    screen(par, _lcd)
{
    screens = new screen*[mitem];
    labels  = new String [mitem];
}

void lcdmenu::choice::handle_input (char input)
{
    if(inside >= 0) {screens[select]->handle_input(input); return;}
    switch (input)
    {
    case 0:
        {
            if(select)
            {
                if(select == vtop)
                {
                    select--;
                    vtop--;
                } else select--;
            }
        }
        break;
    case 2:
        {
            if(select != maxit - 1)
            {
                if(select == vtop + lcd->h - 1)
                {
                    select++;
                    vtop++;
                } else select++;
            }
        }
        break;
    case 1:
        {
            inside = select; 
        }
        break;
    case 3:
        {
            if(parent) parent->goback();
        }
        break;
    }
}

void lcdmenu::choice::draw ()
{
    if(inside >= 0) {screens[select]->draw(); return;}

    for(int i = vtop, j = 0; i < vtop + lcd->h; j++, i++)
    {
        lcd->write(labels[i], j);
        for(int k = labels[i].length(); k < lcd->w; k++) lcd->write(" ");
        
        lcd->move(lcd->w - 1, select - vtop);
        lcd->write("X");
    }
}

void lcdmenu::choice::add_item (screen *sc, String label)
{
    if(itemcnt == maxit) return;
    screens[itemcnt] = sc;
    labels[itemcnt++] = label;
}

void lcdmenu::choice::rem_item (int pos)
{
    if(!itemcnt) return;
    screens[pos] = screens[--itemcnt];
    labels[pos] = labels[itemcnt];
}

void lcdmenu::choice::goback ()
{
    inside = -1;
}

