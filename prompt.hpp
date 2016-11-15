bool key[ALLEGRO_KEY_MAX];

class Prompt
{
private:
    static Prompt *object;
    //string *log[500];
    //string current_line;
    //string feedback_line;
    ALLEGRO_BITMAP *bitmap;
    float width;
    float height;
    float x;
    float y;
    ALLEGRO_BITMAP *log_bitmap;
    float log_width;
    float log_height;
    float log_x;
    float log_y;
    bool show_log;
    Prompt();
public:
    void printLine();
    void feedLine();
    void setShowLog();
    bool getShowLog();
    static Prompt* getPrompt();
    int getPressedCharacter(ALLEGRO_EVENT *event);
};

Prompt* Prompt::object = nullptr;

Prompt* Prompt::getPrompt()
{
    if(object == nullptr)
    {
        object = new Prompt();
    }
    return object;
}

int Prompt::getPressedCharacter(ALLEGRO_EVENT *event)
{
    if(event->type == ALLEGRO_KEY_UP)
        return event->keyboard.keycode;
    else
        return 0;
}
