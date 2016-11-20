class GraphicElement
{
private:
    bool to_be_printed;
    float px_x;
    float px_y;
    float px_width;
    float px_height;
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
    void setToBePrinted(bool _to_be_printed);
    void loadSprite(const char *sprites_filename, int _n_sprites, float px_width, float px_height);
    float getHeight();
    float getWidth();
    GraphicElement();
    ~GraphicElement();
    void setCenter(float _px_center_x, float _px_center_y);
};

GraphicElement::GraphicElement()
{
    sprite = nullptr;
    current_sprite = 0;
    flip_flag = 0;
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
    if(to_be_printed)
    {
        getCornerFromCenter();
        al_set_target_bitmap(drawing_target);
        al_draw_bitmap(sprite[current_sprite], px_x, px_y, flip_flag);
    }
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

void GraphicElement::loadSprite(const char *sprites_filename, int _n_sprites, float _px_width, float _px_height)
{
    int i;
    px_width = _px_width;
    px_height = _px_height;
    ALLEGRO_BITMAP *sprite_sheet;
    if(sprite)
    {
        for(i=0;i<n_sprites;i++)
            al_destroy_bitmap(sprite[i]);
        delete[] sprite;
    }
    sprite = new ALLEGRO_BITMAP*[_n_sprites];
    sprite_sheet = al_load_bitmap(sprites_filename);
    n_sprites = _n_sprites;
    for(i=0;i<n_sprites;i++)
    {
        sprite[i] = al_create_bitmap(px_width, px_height);
        al_set_target_bitmap(sprite[i]);
        al_draw_bitmap_region(sprite_sheet,i*px_width,0,px_width,px_height,0,0,flip_flag);
    }
}
float GraphicElement::getHeight()
{
    return px_height;
}
float GraphicElement::getWidth()
{
    return px_width;
}

void GraphicElement::setCenter(float _px_center_x, float _px_center_y)
{
    px_center_x = _px_center_x;
    px_center_y = _px_center_y;
}

void GraphicElement::setToBePrinted(bool _to_be_printed)
{
    to_be_printed = _to_be_printed;
}
