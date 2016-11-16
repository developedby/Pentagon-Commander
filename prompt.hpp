/*#ifndef STRING
#include <string>
#define STRING
#endif // STRING*/

bool key[ALLEGRO_KEY_MAX];

using namespace std;

class Prompt
{
private:
    static Prompt *object;
    string *log[500];
    string current_line;
    string feedback_line;
    char pressed_character;
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
    Prompt(){};
public:
    void printLine();
    void feedLine();
    void setShowLog();
    bool getShowLog();
    static Prompt* getPrompt();
    int setPressedCharacter(ALLEGRO_EVENT *event);
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

int Prompt::setPressedCharacter(ALLEGRO_EVENT *event)
{
    if(event->type == ALLEGRO_KEY_UP)
        pressed_character = event->keyboard.keycode;
    else
        pressed_character = 0;
}
