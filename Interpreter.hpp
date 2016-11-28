#ifndef INTERPRETER
#define INTERPRETER

#include <pentagon_commander.hpp>
#include <Level.hpp>

enum command_execution{e_executed = 1, e_syntax_error, e_unknown_error};

class Interpreter
{
private:
    static Interpreter* instance;
    Level* level;
    string word;
    string answer;
    Interpreter();
public:
    ~Interpreter();
    static Interpreter* getInterpreter();
    void setLevel(Level* _level);
    string interpret(string command);
    command_execution walk(istringstream &iss);
    command_execution jump(istringstream &iss);
    command_execution stop(istringstream &iss);
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
    level = nullptr;
}

Interpreter::~Interpreter()
{
    Interpreter::instance = nullptr;
}

void Interpreter::setLevel(Level* _level)
{
    level = _level;
}

string Interpreter::interpret(string command)
{
    istringstream iss(command);
    word.clear();
    iss >> word;
    cout << word << endl;
    if(word.compare("walk") == 0 && level->available_command[e_walk])
    {
        walk(iss);
        return answer;
    }
    else if(word.compare("jump") == 0)
    {
        jump(iss);
        return answer;
    }
    else if(word.compare("stop") == 0)
    {
        stop(iss);
        return answer;
    }
    else
    {
        answer = "Syntax Error - Command unknown";
        return answer;
    }
    return "unknown error uWu";
}

///Commands

command_execution Interpreter::walk(istringstream &iss)
{
    iss >> word;
    if(word.compare("right") == 0)
    {
        level->player[0].body->SetLinearVelocity(b2Vec2(player_max_speed, level->player[0].body->GetLinearVelocity().y));
        answer = "moving right";
        return e_executed;
    }
    else if(word.compare("left") == 0)
    {
        level->player[0].body->SetLinearVelocity(b2Vec2(-player_max_speed, level->player[0].body->GetLinearVelocity().y));
        answer = "moving left";
        return e_executed;
    }
    else
        return e_syntax_error;
    answer = "unknown error 0x0";
    return e_unknown_error;
}
command_execution Interpreter::jump(istringstream &iss)
{
    level->player[0].body->SetLinearVelocity(b2Vec2(level->player[0].body->GetLinearVelocity().x, player_max_speed));
    answer = "jumped";
    return e_executed;
}
command_execution Interpreter::stop(istringstream &iss)
{
    level->player[0].body->SetLinearVelocity(b2Vec2(0, level->player[0].body->GetLinearVelocity().y));
    answer = "stopped";
    return e_executed;
}

#endif // INTERPRETER
