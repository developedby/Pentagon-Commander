class GraphicElement
{
private:
    float px_x;
    float px_y;
    float px_center_x;
    float px_center_y;
    int flip_flag;
    int n_sprites;
    int current_sprite;
    ALLEGRO_BITMAP **sprite;
    ALLEGRO_BITMAP *drawing_target;
    void getCornerFromCenter();
public:
    void printOnScreen();
    void setDrawingTarget(ALLEGRO_BITMAP *_drawing_target);
    void setFlipFlag(int flag);
    void setCurrentSprite(int n);
    void loadSprite(char *sprites_filename, int _n_sprites, float px_width, float px_height);
    GraphicElement();
    ~GraphicElement();
};

GraphicElement::GraphicElement()
{
    sprite = NULL;
}

GraphicElement::~GraphicElement()
{
    int i;
    if(sprite)
    {
        for(i=0;i<n_sprites;i++)
            al_destroy_bitmap(sprite[i]);
        delete[] sprite;
    }
}

void GraphicElement::getCornerFromCenter()
{
    int height = al_get_bitmap_height(sprite[current_sprite]);
    int width = al_get_bitmap_width(sprite[current_sprite]);
    /* All bitmap dimensions are to be odd sized */
    px_x = px_center_x - width/2;
    px_y = px_center_y - height/2;
}

void GraphicElement::printOnScreen()
{
    getCornerFromCenter();
    al_set_target_bitmap(drawing_target);
    al_draw_bitmap(sprite[current_sprite], px_x, px_y, flip_flag);
}

void GraphicElement::setDrawingTarget(ALLEGRO_BITMAP *_drawing_target)
{
    drawing_target = _drawing_target;
}

void GraphicElement::setFlipFlag(int flag)
{
    flip_flag = flag;
}

void GraphicElement::setCurrentSprite(int n)
{
    current_sprite = n;
}

void GraphicElement::loadSprite(char *sprites_filename, int _n_sprites, float px_width, float px_height)
{
    int i;
    ALLEGRO_BITMAP *sprite_sheet;
    if(sprite)
    {
        for(i=0;i<n_sprites;i++)
            al_destroy_bitmap(sprite[i]);
        delete[] sprite;
    }
    sprite = new ALLEGRO_BITMAP*[_n_sprites];
    sprite_sheet = al_load_bitmap(sprites_filename);
    n_sprites=_n_sprites;
    for(i=0;i<n_sprites;i++)
    {
        al_set_target_bitmap(sprite[i]);
        al_draw_bitmap_region(sprite_sheet,i*px_width,0,0,0,px_width,px_height,flip_flag);
    }
}
