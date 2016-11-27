#ifndef INTERPRETER
#define INTERPRETER

#include <pentagon_commander.hpp>
#include <prompt.hpp>
#include <Level.hpp>

class Interpreter
{
private:
    static Interpreter* instance;
    Prompt* prompt;
    Level* level;
    Interpreter();
public:
    ~Interpreter();
    static Interpreter* getInterpreter();
    void setLevel(Level* _level);
    string walk(string command);
    string jump(string command);
    string stop(string command);
};

Interpreter* Interpreter::instance = nullptr;

Interpreter* Interpreter::getInterpreter()
{
    if(instance == nullptr)
        instance = new Interpreter();
    return instance;
}

Interpreter::Interpreter()
{
    prompt = Prompt::getPrompt();
    prompt->setInterpreter(this);
}

Interpreter::~Interpreter()
{
    Interpreter::instance = nullptr;
}

void Interpreter::setLevel(Level* _level)
{
    level = _level;
}

///Commands

/*string Interpreter::walk(string command)
{

}
string Interpreter::jump(string command);
string Interpreter::stop(string command);*/

#endif // INTERPRETER
