#ifndef PENTAGONCOMMANDER_HPP
#define PENTAGONCOMMANDER_HPP
#endif //PENTAGONCOMMANDER_HPP

float pixelsToMeters(float px);
float metersToPixels(float m);


#ifndef PROMPT
#define PROMPT
#include <prompt.hpp>

#ifndef LEVEL
#define LEVEL
#include <Level.hpp>
#endif // LEVEL

#ifndef CAMERA
#define CAMERA
#include <Camera.hpp>
#endif //CAMERA

#ifndef GRAPHICELEMENT
#define GRAPHICELEMENT
#include <GraphicElement.hpp>
#endif //GRAPHICELEMENT

#ifndef PHYSICALOBJECT
#define PHYSICALOBJECT
#include <PhysicalObject.hpp>
#endif //PHYSICALOBJECT

#ifndef LIVINGOBJECT
#define LIVINGOBJECT
#include <LivingObject.hpp>
#endif // LIVINGOBJECT


/* Variables */
const float FPS = 60;
const int SCREEN_W = 1080;
const int SCREEN_H = 720;
bool comAudio = true;
const float px_to_m_fac = 1/69;
const float m_to_px_fac = 69;

/* Functions */
int initAllegro(ALLEGRO_DISPLAY **display, ALLEGRO_EVENT_QUEUE **event_queue,
    ALLEGRO_TIMER **timer, ALLEGRO_FONT **font, ALLEGRO_SAMPLE **som);
void destroyAllegro(ALLEGRO_DISPLAY **display, ALLEGRO_EVENT_QUEUE **event_queue,
    ALLEGRO_TIMER **timer, ALLEGRO_FONT **font, ALLEGRO_SAMPLE **som);


void playLevel(Level *level, ALLEGRO_DISPLAY **display)
{
    int i;
    for(i=0; i<level->getNCameras(); i++)
    {
        level->camera[i]->record();
        level->camera[i]->play(*display);
    }
}

float pixelsToMeters(float px)
{
    float meters;
    meters = px*px_to_m_fac;
    return meters;
}

float metersToPixels(float m)
{
    float pixels;
    pixels = m*m_to_px_fac;
    return pixels;
}
