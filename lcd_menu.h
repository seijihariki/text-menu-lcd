struct LCD
{
public:
    LCD(int sx, int sy);
    virtual void write(String str) = 0;
    virtual void write(String str, int row) = 0;
    virtual void write(String str, int column, int row) = 0;
    
    virtual void move(int x, int y) = 0;
    virtual void clear() = 0;
};

struct screen
{
public:
    screen(screen* par);

    virtual void handle_input(char input) = 0;
    virtual void draw() = 0;
    virtual void goback() = 0;

protected:
    screen* parent;
};

struct choice : public screen
{
public:
    choice(int mitem, int lines, screen* par);

    void handle_input(char input);
    void draw();

    void add_item(screen *sc, String label);
    void rem_item(int pos);
private:
    bool state;
    int inside, sy;
    int select, vtop;
    int itemcnt, maxit;
    screen **screens;
    String *labels;
};
