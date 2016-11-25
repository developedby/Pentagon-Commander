#ifndef PROMPT
#define PROMPT


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
    int pressed_character;
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
    int log_pos;
    bool show_log;
    int n_log_lines;
    Prompt(){};
public:
    virtual ~Prompt();
    void printLine();
    void feedLine();
    void setShowLog();
    bool getShowLog();
    static Prompt* getPrompt();
    void setPressedCharacter(ALLEGRO_EVENT *event);
    void processPressedCharacter();
};

Prompt* Prompt::object = nullptr;

Prompt::~Prompt()
{
    delete object;
}

Prompt* Prompt::getPrompt()
{
    if(object == nullptr)
    {
        object = new Prompt();
        object->n_log_lines = 0;
        object->show_log = false;
    }
    return object;
}

void Prompt::setPressedCharacter(ALLEGRO_EVENT *event)
{
    if(event->type == ALLEGRO_KEY_UP)
        pressed_character = event->keyboard.keycode;
    else
        pressed_character = -1;
}

void Prompt::processPressedCharacter()
{
    if(pressed_character!=-1)
    {
        switch(pressed_character)
        {
            case ALLEGRO_KEY_A:
                current_line.append("a");
                break;
            case ALLEGRO_KEY_B:
                current_line.append("b");
                break;
            case ALLEGRO_KEY_C:
                current_line.append("c");
                break;
            case ALLEGRO_KEY_D:
                current_line.append("d");
                break;
            case ALLEGRO_KEY_E:
                current_line.append("e");
                break;
            case ALLEGRO_KEY_F:
                current_line.append("f");
                break;
            case ALLEGRO_KEY_G:
                current_line.append("g");
                break;
            case ALLEGRO_KEY_H:
                current_line.append("h");
                break;
            case ALLEGRO_KEY_I:
                current_line.append("i");
                break;
            case ALLEGRO_KEY_J:
                current_line.append("j");
                break;
            case ALLEGRO_KEY_K:
                current_line.append("k");
                break;
            case ALLEGRO_KEY_L:
                current_line.append("l");
                break;
            case ALLEGRO_KEY_M:
                current_line.append("m");
                break;
            case ALLEGRO_KEY_N:
                current_line.append("n");
                break;
            case ALLEGRO_KEY_O:
                current_line.append("o");
                break;
            case ALLEGRO_KEY_P:
                current_line.append("p");
                break;
            case ALLEGRO_KEY_Q:
                current_line.append("q");
                break;
            case ALLEGRO_KEY_R:
                current_line.append("r");
                break;
            case ALLEGRO_KEY_S:
                current_line.append("s");
                break;
            case ALLEGRO_KEY_T:
                current_line.append("t");
                break;
            case ALLEGRO_KEY_U:
                current_line.append("u");
                break;
            case ALLEGRO_KEY_V:
                current_line.append("v");
                break;
            case ALLEGRO_KEY_W:
                current_line.append("w");
                break;
            case ALLEGRO_KEY_X:
                current_line.append("x");
                break;
            case ALLEGRO_KEY_Y:
                current_line.append("y");
                break;
            case ALLEGRO_KEY_Z:
                current_line.append("z");
                break;
            case ALLEGRO_KEY_0:
                current_line.append("0");
                break;
            case ALLEGRO_KEY_1:
                current_line.append("1");
                break;
            case ALLEGRO_KEY_2:
                current_line.append("2");
                break;
            case ALLEGRO_KEY_3:
                current_line.append("3");
                break;
            case ALLEGRO_KEY_4:
                current_line.append("4");
                break;
            case ALLEGRO_KEY_5:
                current_line.append("5");
                break;
            case ALLEGRO_KEY_6:
                current_line.append("6");
                break;
            case ALLEGRO_KEY_7:
                current_line.append("7");
                break;
            case ALLEGRO_KEY_8:
                current_line.append("8");
                break;
            case ALLEGRO_KEY_9:
                current_line.append("9");
                break;
            case ALLEGRO_KEY_SPACE:
                current_line.append(" ");
                break;
            case ALLEGRO_KEY_BACKSPACE:
                current_line.pop_back();
                break;
            case ALLEGRO_KEY_ENTER:
                //write logs
                //send command
                current_line.clear();
                //write feedback
                break;
            case ALLEGRO_KEY_TAB:
                show_log = !show_log;
                break;
            case ALLEGRO_KEY_UP:
                log_pos++;
                break;
            case ALLEGRO_KEY_DOWN:
                log_pos--;
                break;
            default:
                break;
        }
    }
}

#endif //PROMPT
