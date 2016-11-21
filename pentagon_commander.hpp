#ifndef LIVINGOBJECT
#define LIVINGOBJECT
#endif // LIVINGOBJECT

#include <prompt.hpp>

#ifndef LEVEL
#include <Level.hpp>
#define LEVEL
#endif // LEVEL



#include <Camera.hpp>



float pixelsToMeters(float px);
float metersToPixels(float m);
#include <GraphicElement.hpp>
#include <PhysicalObject.hpp>
#include <LivingObject.hpp>


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
