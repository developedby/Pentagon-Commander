#ifndef PENTAGONCOMMANDER_HPP
#define PENTAGONCOMMANDER_HPP

/* Variables */
const float FPS = 60;
const int SCREEN_W = 1080;
const int SCREEN_H = 720;
bool comAudio = true;
const float px_to_m_fac = 1.0/69.0;
const float m_to_px_fac = 69.0;
const int font_size = 10;

/* Functions */
int initAllegro(ALLEGRO_DISPLAY **display, ALLEGRO_EVENT_QUEUE **event_queue,
    ALLEGRO_TIMER **timer, ALLEGRO_FONT **font, ALLEGRO_SAMPLE **som);
void destroyAllegro(ALLEGRO_DISPLAY **display, ALLEGRO_EVENT_QUEUE **event_queue,
    ALLEGRO_TIMER **timer, ALLEGRO_FONT **font, ALLEGRO_SAMPLE **som);
float pixelsToMeters(float px);
float metersToPixels(float m);

#include <GraphicElement.hpp>
#include <prompt.hpp>
#include <PhysicalObject.hpp>
#include <LivingObject.hpp>
#include <Camera.hpp>
#include <Level.hpp>
#include <Cameraman.hpp>

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
#endif //PENTAGONCOMMANDER_HPP
