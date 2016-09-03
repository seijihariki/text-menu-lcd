#include "lcd-menu.h"

LCD::LCD (int sx, int sy) : w(sx), h(sy)
{
}

screen::screen (screen* par) : parent(par)
{
}

choice::choice (int mitem, int lines, screen* par) : maxit(mitem), vtop(0), 
    select(0), state(false), 
    inside(-1), itemcnt(0), 
    sy(lines), screen(par)
{
    screens = new screen*[mitem];
    labels  = new String [mitem];
}

void choice::handle_input (char input)
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
            if(select != maxit)
            {
                if(select == vtop + sy - 1)
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
            parent->goback();
        }
        break;
    }
}

void choice::draw (LCD *lcd)
{
    if(inside >= 0) {screens[select]->draw(); return;}

    for(int i = vtop, j = 0; i < vtop + sy; j++, i++)
        lcd->write(labels[i], j);

    lcd->move(lcd->w - 1, select - vtop);
    lcd->write("X");
}

void choice::add_item (screen *sc, String label)
{
    if(itemcnt == maxit) return;
    screens[itemcnt] = sc;
    labels[itemcnt++] = label;
}

void choice::rem_item (int pos)
{
    if(!itemcnt) return;
    screens[pos] = screens[--itemcnt];
    labels[pos] = labels[itemcnt];
}


