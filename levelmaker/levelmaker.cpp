#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

enum shape_type{POLYGON=0,BOX,CIRCLE};

using namespace std;

void createNewFileFromScratch();
void createUglyFromNeat();
void createPhysicalObjectFromNeat(ifstream* neat_file, ofstream* ugly_file);

int main()
{
    int mode;
    cout << "Choose the mode to use" << endl;
    cout << "1 - Create new file from scratch" << endl;
    cout << "2 - Create an ugly file using a neat file" << endl;
    cin >> mode;
    switch(mode)
    {
    case 1:
        createNewFileFromScratch();
        break;
    case 2:
        createUglyFromNeat();
        break;
    }
    return 0;
}

void createUglyFromNeat()
{
    string string_register;
    ofstream ugly_file;
    ifstream neat_file;
    int i, n_objects;

    cout << "Insert the neat file's name" << endl;
    cin >> string_register;
    neat_file.open(string_register.c_str());

    cout << "Insert the ugly file's name" << endl;
    cin >> string_register;
    ugly_file.open(string_register.c_str());

    neat_file >> string_register;//Level
    neat_file >> string_register;//name
    neat_file >> string_register;//:
    neat_file >> string_register;//[LEVEL NAME]
    ugly_file << string_register << ' ';

    neat_file >> string_register;//gravity.x
    neat_file >> string_register;//:
    neat_file >> string_register;//[GRAVITY.X]
    ugly_file << string_register << ' ';

    neat_file >> string_register;//gravity.y
    neat_file >> string_register;//:
    neat_file >> string_register;// [GRAVITY.Y]
    ugly_file << string_register << ' ';

    neat_file >> string_register;//background
    neat_file >> string_register;//file
    neat_file >> string_register;//name
    neat_file >> string_register;//:
    neat_file >> string_register;//[BACKGROUND FILE NAME]
    ugly_file << string_register << ' ' ;

    neat_file >> string_register;//objective.upperbound.x
    neat_file >> string_register;//:
    neat_file >> string_register;//[OBJECTIVE.UPPERBOUND.X]
    ugly_file << string_register << ' ' ;

    neat_file >> string_register;//objective.upperbound.y
    neat_file >> string_register;//:
    neat_file >> string_register;//[OBJECTIVE.UPPERBOUND.Y]
    ugly_file << string_register << ' ' ;

    neat_file >> string_register;//objective.lowerbound.x
    neat_file >> string_register;//:
    neat_file >> string_register;//[OBJECTIVE.LOWERBOUND.X]
    ugly_file << string_register << ' ' ;

    neat_file >> string_register;//objective.lowerbound.y
    neat_file >> string_register;//:
    neat_file >> string_register;//[OBJECTIVE.LOWERBOUND.Y]
    ugly_file << string_register << ' ' ;

    neat_file >> string_register;//n_players
    neat_file >> string_register;//:
    neat_file >> string_register;//[N_PLAYERS]
    ugly_file << string_register << ' ' ;
    n_objects = atoi(string_register.c_str());

    for(i=0; i<n_objects; i++) //for n_players
    {
        createPhysicalObjectFromNeat(&neat_file, &ugly_file);
    }

    neat_file >> string_register;//n_physical_objects
    neat_file >> string_register;//:
    neat_file >> string_register;//
    ugly_file << string_register << ' ' ;
    n_objects = atoi(string_register.c_str());

    for(i=0; i<n_objects; i++)
    {
        neat_file >> string_register;//living_object[i]
        neat_file >> string_register;//max
        neat_file >> string_register;//hp
        neat_file >> string_register;//:
        neat_file >> string_register;//
        ugly_file << string_register << ' ' ;

        neat_file >> string_register;//living_object[i]
        neat_file >> string_register;//alive
        neat_file >> string_register;//flag
        neat_file >> string_register;//:
        neat_file >> string_register;//
        ugly_file << string_register << ' ' ;

        createPhysicalObjectFromNeat(&neat_file, &ugly_file);
    }

    neat_file >> string_register;//n_physical_objects
    neat_file >> string_register;//:
    neat_file >> string_register;//[N_PHYSICAL_OBJECTS]
    ugly_file << string_register << ' ' ;
    n_objects = atoi(string_register.c_str());

    for(i=0; i<n_objects; i++) //for n_physical_objects
    {
        createPhysicalObjectFromNeat(&neat_file, &ugly_file);
    }

    neat_file >> string_register;//n_cameras
    neat_file >> string_register;//:
    neat_file >> string_register;//
    ugly_file << string_register << ' ' ;

    neat_file >> string_register;//n_commands
    neat_file >> string_register;//:
    neat_file >> string_register;//
    ugly_file << string_register << ' ' ;
    n_objects = atoi(string_register.c_str());

    for(i=0; i<n_objects; i--)
    {
        neat_file >> string_register;//command
        neat_file >> string_register;//i
        neat_file >> string_register;//:
        neat_file >> string_register;//
        ugly_file << string_register << ' ' ;

    }
}

void createPhysicalObjectFromNeat(ifstream* neat_file, ofstream* ugly_file)
{
    string string_register;
    int j;
    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//id
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT.id]
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//body
    (*neat_file) >> string_register;//type
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT BODY TYPE]
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//position
    (*neat_file) >> string_register;//x
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT X POSITION]
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//position
    (*neat_file) >> string_register;//y
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT Y POSITION]
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//angle
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT ANGLE]
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//linear
    (*neat_file) >> string_register;//damping
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT LINEAR DAMPING]
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//angular
    (*neat_file) >> string_register;//damping
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT ANGULAR DAMPING]
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//gravity
    (*neat_file) >> string_register;//scale
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT GRAVITY SCALE]
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//allow
    (*neat_file) >> string_register;//sleep
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT ALLOW SLEEP FLAG]
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//awake
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT AWAKE FLAG]
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//fixed
    (*neat_file) >> string_register;//rotation
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT FIXED ROTATIONG FLAG]
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//bullet
    (*neat_file) >> string_register;//flag
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT BULLET FLAG]
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//active
    (*neat_file) >> string_register;//flag
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT ACTIVE FLAG]
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//shapetype
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//[OBJECT SHAPE TYPE]
    (*ugly_file) << string_register << ' ' ;

    int shapetype = atoi(string_register.c_str());
    switch (shapetype)
    {
    case POLYGON:
        (*neat_file) >> string_register;//OBJECT
        (*neat_file) >> string_register;//n_vertices
        (*neat_file) >> string_register;//:
        (*neat_file) >> string_register;//[N_VERTICES]
        (*ugly_file) << string_register << ' ' ;

        for(j=0; j<atoi(string_register.c_str()); j++)
        {
            (*neat_file) >> string_register;//OBJECT
            (*neat_file) >> string_register;//vertice[j]
            (*neat_file) >> string_register;//x
            (*neat_file) >> string_register;//:
            (*neat_file) >> string_register;//VERTICE X COORDINATE
            (*ugly_file) << string_register << ' ' ;

            (*neat_file) >> string_register;//OBJECT
            (*neat_file) >> string_register;//vertice[j]
            (*neat_file) >> string_register;//y
            (*neat_file) >> string_register;//:
            (*neat_file) >> string_register;//VERTICE Y COORDINATE
            (*ugly_file) << string_register << ' ' ;
        }
        break;

    case BOX:
        (*neat_file) >> string_register;//OBJECT
        (*neat_file) >> string_register;//half
        (*neat_file) >> string_register;//width
        (*neat_file) >> string_register;//:
        (*neat_file) >> string_register;//
        (*ugly_file) << string_register << ' ' ;

        (*neat_file) >> string_register;//OBJECT
        (*neat_file) >> string_register;//half
        (*neat_file) >> string_register;//height
        (*neat_file) >> string_register;//:
        (*neat_file) >> string_register;//
        (*ugly_file) << string_register << ' ' ;
        break;

    case CIRCLE:
        (*neat_file) >> string_register;//OBJECT
        (*neat_file) >> string_register;//radius
        (*neat_file) >> string_register;//:
        (*neat_file) >> string_register;//
        (*ugly_file) << string_register << ' ' ;

    }//end switch

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//density
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//friction
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//restitution
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//category
    (*neat_file) >> string_register;//bits
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//mask
    (*neat_file) >> string_register;//bits
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//sprite
    (*neat_file) >> string_register;//filename
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//n_sprites
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//sprite
    (*neat_file) >> string_register;//width
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//sprite
    (*neat_file) >> string_register;//height
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//
    (*ugly_file) << string_register << ' ' ;

    (*neat_file) >> string_register;//OBJECT
    (*neat_file) >> string_register;//to
    (*neat_file) >> string_register;//be
    (*neat_file) >> string_register;//printed
    (*neat_file) >> string_register;//:
    (*neat_file) >> string_register;//
    (*ugly_file) << string_register << ' ' ;
}

void createNewFileFromScratch()
{
    string string_register;
    ofstream ugly_file, neat_file;
    int i, j, int_register, int_register2;

    cout << "Insert the file name: ";
    cin >> string_register;
    ugly_file.open(string_register.c_str());
    string_register = "neat_" + string_register;
    neat_file.open(string_register.c_str());

    cout << "Insert the level name: ";
    cin >> string_register;
    ugly_file << string_register << ' ';
    neat_file << "Level name : " << string_register << '\n';

    cout << "Insert gravity on the x axis: ";
    cin >> string_register;
    ugly_file << string_register << ' ';
    neat_file << "gravity.x : " << string_register << '\n';

    cout << "Insert gravity on the y axis: ";
    cin >> string_register;
    ugly_file << string_register << ' ';

    neat_file << "gravity.y : " << string_register << '\n';

    cout << "Insert the background file name: ";
    cin >> string_register;
    ugly_file << string_register << ' ';

    neat_file << "background file name : " << string_register << '\n';

    cout << "Insert the objective area's upperbound x coordinate: ";
    cin >> string_register;
    ugly_file << string_register << ' ';
    neat_file << "objective.upperbound.x : " << string_register << '\n';

    cout << "Insert the objective area's upperbound y coordinate: ";
    cin >> string_register;
    ugly_file << string_register << ' ';
    neat_file << "objective.upperbound.y : " << string_register << '\n';

    cout << "Insert the objective area's lowerbound x coordinate: ";
    cin >> string_register;
    ugly_file << string_register << ' ';
    neat_file << "objective.lowerbound.x : " << string_register << '\n';

    cout << "Insert the objective area's lowerbound y coordinate: ";
    cin >> string_register;
    ugly_file << string_register << ' ';
    neat_file << "objective.lowerbound.y : " << string_register << '\n';

    cout << "Insert the number of players: ";
    cin >> int_register;
    ugly_file << int_register << ' ';
    neat_file << "n_players : " << int_register << '\n';

    for(i=0; i<int_register; i++)
    {
        cout << "Insert player[" << i <<"]'s ID: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] id : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s body type (0-Dynamic, 1-Static, 2-Kinematic): ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] body type : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s position x coordinate: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] position x : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s position y coordinate: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] position y : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s angle: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] angle : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s linear damping: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] linear damping : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s angular damping: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] angular damping : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s gravity scale: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] gravity scale : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s allow sleep flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] allow sleep : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s awake flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] awake : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s fixed rotation flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] fixed rotation : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s bullet flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] bullet flag : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s active flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] active flag : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s shapetype (0-Polygon, 1-Box, 2-Circle): ";
        cin >> int_register2;
        ugly_file << int_register2 << ' ';
        neat_file << "player[" << i <<  "] shapetype : " << int_register2 << '\n';

        switch(int_register2)
        {
            case 0:

            cout << "Insert player[" << i <<"]'s number of vertices: ";
            cin >> int_register2;
            ugly_file << int_register2 << ' ';
            neat_file << "player[" << i <<  "] n_vertices : " << int_register2 << '\n';
            for(j=0; j<int_register2; j++)
            {
                cout << "Insert player[" << i << "]'s vertice[" << j << "] x coordinate: ";
                cin >> string_register;
                ugly_file << string_register << ' ';
                neat_file << "player[" << i <<  "] vertice[" << j << "] x : " << string_register << '\n';

                cout << "Insert player[" << i << "]'s vertice[" << j << "] y coordinate: ";
                cin >> string_register;
                ugly_file << string_register << ' ';
                neat_file << "player[" << i <<  "] vertice[" << j << "] y : " << string_register << '\n';
            }
            break;

            case 1:

            cout << "Insert player[" << i <<"]'s half width: ";
            cin >> string_register;
            ugly_file << string_register << ' ';
            neat_file << "player[" << i <<  "] half width : " << string_register << '\n';

            cout << "Insert player[" << i <<"]'s half height: ";
            cin >> string_register;
            ugly_file << string_register << ' ';
            neat_file << "player[" << i <<  "] half height : " << string_register << '\n';
            break;

            case 2:

            cout << "Insert player[" << i <<"]'s radius: ";
            cin >> string_register;
            ugly_file << string_register << ' ';
            neat_file << "player[" << i <<  "] radius : " << string_register << '\n';
            break;
        }

        cout << "Insert player[" << i <<"]'s density: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] density : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s friction: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] friction : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s restitution: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] restitution : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s category bits: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] category bits : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s mask bits: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] mask bits : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s sprite filename: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] sprite filename : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s number of sprites: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] n_sprites : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s sprite width: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] sprite witdh : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s sprite height: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] sprite height : " << string_register << '\n';

        cout << "Insert player[" << i <<"]'s to be printed flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "player[" << i <<  "] to be printed : " << string_register << '\n';
    }

    cout << "Insert the number of living objects: ";
    cin >> int_register;
    ugly_file << int_register << ' ';
    neat_file << "n_living_objects : " << int_register << '\n';

    for(i=0; i<int_register; i++)
    {
        cout << "Insert living_object[" << i <<"]'s max hp: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] max hp : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s alive flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] alive flag : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s ID: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] id : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s body type (0-Dynamic, 1-Static, 2-Kinematic): ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] body type : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s position x coordinate: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] position x : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s position y coordinate: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] position y : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s angle: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] angle : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s linear damping: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] linear damping : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s angular damping: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] angular damping : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s gravity scale: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] gravity scale : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s allow sleep flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] allow sleep : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s awake flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] awake : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s fixed rotation flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] fixed rotation : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s bullet flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] bullet flag : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s active flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] active flag : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s shapetype (0-Polygon, 1-Box, 2-Circle): ";
        cin >> int_register2;
        ugly_file << int_register2 << ' ';
        neat_file << "living_object[" << i <<  "] shapetype : " << int_register2 << '\n';

        switch(int_register2)
        {
            case 0:

            cout << "Insert living_object[" << i <<"]'s number of vertices: ";
            cin >> int_register2;
            ugly_file << int_register2 << ' ';
            neat_file << "living_object[" << i <<  "] n_vertices : " << int_register2 << '\n';
            for(j=0; j<int_register2; j++)
            {
                cout << "Insert living_object[" << i << "]'s vertice[" << j << "] x coordinate: ";
                cin >> string_register;
                ugly_file << string_register << ' ';
                neat_file << "living_object[" << i <<  "] vertice[" << j << "] x : " << string_register << '\n';

                cout << "Insert living_object[" << i << "]'s vertice[" << j << "] y coordinate: ";
                cin >> string_register;
                ugly_file << string_register << ' ';
                neat_file << "living_object[" << i <<  "] vertice[" << j << "] y : " << string_register << '\n';
            }
            break;

            case 1:

            cout << "Insert living_object[" << i <<"]'s half width: ";
            cin >> string_register;
            ugly_file << string_register << ' ';
            neat_file << "living_object[" << i <<  "] half width : " << string_register << '\n';

            cout << "Insert living_object[" << i <<"]'s half height: ";
            cin >> string_register;
            ugly_file << string_register << ' ';
            neat_file << "living_object[" << i <<  "] half height : " << string_register << '\n';
            break;

            case 2:

            cout << "Insert living_object[" << i <<"]'s radius: ";
            cin >> string_register;
            ugly_file << string_register << ' ';
            neat_file << "living_object[" << i <<  "] radius : " << string_register << '\n';
            break;
        }

        cout << "Insert living_object[" << i <<"]'s density: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] density : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s friction: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] friction : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s restitution: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] restitution : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s category bits: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] category bits : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s mask bits: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] mask bits : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s sprite filename: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] sprite filename : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s number of sprites: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] n_sprites : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s sprite width: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] sprite witdh : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s sprite height: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] sprite height : " << string_register << '\n';

        cout << "Insert living_object[" << i <<"]'s to be printed flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "living_object[" << i <<  "] to be printed : " << string_register << '\n';
    }

    cout << "Insert the number of physical objects: ";
    cin >> int_register;
    ugly_file << int_register << ' ';
    neat_file << "n_physical_objects : " << int_register << '\n';

    for(i=0; i<int_register; i++)
    {
        cout << "Insert physical_object[" << i <<"]'s ID: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] id : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s body type (0-Dynamic, 1-Static, 2-Kinematic): ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] body type : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s position x coordinate: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] position x : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s position y coordinate: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] position y : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s angle: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] angle : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s linear damping: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] linear damping : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s angular damping: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] angular damping : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s gravity scale: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] gravity scale : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s allow sleep flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] allow sleep : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s awake flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] awake : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s fixed rotation flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] fixed rotation : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s bullet flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] bullet flag : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s active flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] active flag : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s shapetype (0-Polygon, 1-Box, 2-Circle): ";
        cin >> int_register2;
        ugly_file << int_register2 << ' ';
        neat_file << "physical_object[" << i <<  "] shapetype : " << int_register2 << '\n';

        switch(int_register2)
        {
            case 0:

            cout << "Insert physical_object[" << i <<"]'s number of vertices: ";
            cin >> int_register2;
            ugly_file << int_register2 << ' ';
            neat_file << "physical_object[" << i <<  "] n_vertices : " << int_register2 << '\n';
            for(j=0; j<int_register2; j++)
            {
                cout << "Insert physical_object[" << i << "]'s vertice[" << j << "] x coordinate: ";
                cin >> string_register;
                ugly_file << string_register << ' ';
                neat_file << "physical_object[" << i <<  "] vertice[" << j << "] x : " << string_register << '\n';

                cout << "Insert physical_object[" << i << "]'s vertice[" << j << "] y coordinate: ";
                cin >> string_register;
                ugly_file << string_register << ' ';
                neat_file << "physical_object[" << i <<  "] vertice[" << j << "] y : " << string_register << '\n';
            }
            break;

            case 1:

            cout << "Insert physical_object[" << i <<"]'s half width: ";
            cin >> string_register;
            ugly_file << string_register << ' ';
            neat_file << "physical_object[" << i <<  "] half width : " << string_register << '\n';

            cout << "Insert physical_object[" << i <<"]'s half height: ";
            cin >> string_register;
            ugly_file << string_register << ' ';
            neat_file << "physical_object[" << i <<  "] half height : " << string_register << '\n';
            break;

            case 2:

            cout << "Insert physical_object[" << i <<"]'s radius: ";
            cin >> string_register;
            ugly_file << string_register << ' ';
            neat_file << "physical_object[" << i <<  "] radius : " << string_register << '\n';
            break;
        }

        cout << "Insert physical_object[" << i <<"]'s density: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] density : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s friction: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] friction : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s restitution: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] restitution : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s category bits: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] category bits : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s mask bits: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] mask bits : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s sprite filename: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] sprite filename : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s number of sprites: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] n_sprites : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s sprite width: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] sprite witdh : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s sprite height: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] sprite height : " << string_register << '\n';

        cout << "Insert physical_object[" << i <<"]'s to be printed flag: ";
        cin >> string_register;
        ugly_file << string_register << ' ';
        neat_file << "physical_object[" << i <<  "] to be printed : " << string_register << '\n';
    }

    cout << "Insert the number of cameras: ";
    cin >> int_register;
    ugly_file << int_register << ' ';
    neat_file << "n_cameras : " << int_register << '\n';

    cout << "Insert the number of commands: ";
    cin >> int_register;
    ugly_file << int_register << ' ';
    neat_file << "n_commands : " << int_register << '\n';

    for(i=0; i<int_register; i++)
    {
        cout << "Choose if command " << i << "is available (1-yes, 0-no): ";
        cin >> int_register2;
        ugly_file << int_register << ' ';
        neat_file << "command " << i << " : "<< int_register << '\n';
    }

    ugly_file.close();
    neat_file.close();
}
