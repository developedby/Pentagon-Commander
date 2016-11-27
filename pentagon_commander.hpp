#ifndef PENTAGONCOMMANDER_HPP
#define PENTAGONCOMMANDER_HPP

enum commands
{
    e_stop = 0, e_walk, e_jump
};

/* Variables */
const float FPS = 60;
const int SCREEN_W = 1080;
const int SCREEN_H = 720;
bool comAudio = true;
const float px_to_m_fac = 1.0/69.0;
const float m_to_px_fac = 69.0;
const int font_size = 20;
float time_step = 1.0/60.0;
int velocity_iterations = 8;
int position_iterations = 3;
const float prompt_width = (float)SCREEN_W;
const float prompt_height = 100.0;
const float log_width = (float)SCREEN_W;
const float log_height = (float)SCREEN_H - prompt_height;
const float player_max_speed = 1.0/15.0;

/* Functions */
int initAllegro(ALLEGRO_DISPLAY **display, ALLEGRO_EVENT_QUEUE **event_queue,
    ALLEGRO_TIMER **timer, ALLEGRO_FONT **font, ALLEGRO_SAMPLE **som);
void destroyAllegro(ALLEGRO_DISPLAY **display, ALLEGRO_EVENT_QUEUE **event_queue,
    ALLEGRO_TIMER **timer, ALLEGRO_FONT **font, ALLEGRO_SAMPLE **som);
float pixelsToMeters(float px);
float metersToPixels(float m);

#include <Box2D.h>
#include <GraphicElement.hpp>
#include <PhysicalObject.hpp>
#include <LivingObject.hpp>
#include <Camera.hpp>
#include <Level.hpp>
#include <Cameraman.hpp>
#include <prompt.hpp>
#include <Interpreter.hpp>

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
