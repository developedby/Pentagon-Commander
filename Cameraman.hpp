#ifndef CAMERAMAN
#define CAMERAMAN
#endif // CAMERAMAN

#ifndef PENTAGONCOMMANDER_HPP
#define PENTAGONCOMMANDER_HPP
#include <pentagon_commander.hpp>
#endif // PENTAGONCOMMANDER_HPP

#ifndef CAMERA
#define CAMERA
#include <Camera.hpp>
#endif // CAMERA

#ifndef LEVEL
#define <Level.hpp>
#endif // LEVEL

class Cameraman
{
private:
    Camera *camera;
    Level *level;
    void setCameras();
    int n_cameras;
public:
    void recordLevel();
    void playLevel(ALLEGRO_DISPLAY *display);
    void setCameraPositionToPlayer();
    int getNCameras();
    Cameraman(Level *_level);

    void setNIndependentElements(int n)
    { //TESTE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        int i;
        for(i=0;i<n_cameras;i++)
            camera[i].setNIndependentElements(n);
    }
};
Cameraman::Cameraman(Level *_level)
{
    level = _level;
    n_cameras = level->getNCameras();
    setCameras();
}

int Cameraman::getNCameras()
{
    return n_cameras;
}

void Cameraman::setCameras()
{
    int i;
    camera = new Camera[n_cameras];
    for(i=0; i<n_cameras; i++)
    {
        camera[i].setLevel(level);
        camera[i].setWidthAndHeight(400, 400); //Teste!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        camera[i].createScreen(0, 0); //Teste!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
}

void Cameraman::setCameraPositionToPlayer()
{
    int i;
    if(level->getNPlayers() == n_cameras)
    {
        for(i=0; i<n_cameras; i++)
        {
            camera[i].setLvPos(level->player[i].body_def.position);
        }
    }
}

void Cameraman::recordLevel()
{
    int i;
    for (i=0 ; i<n_cameras; i++)
    {
        camera[i].record();
    }
}

void Cameraman::playLevel(ALLEGRO_DISPLAY *display)
{
    int i;
    for(i=0; i<n_cameras; i++)
        camera[i].play(display);
}
