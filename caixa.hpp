#include <GraphicElement.hpp>
#include <PhysicalObject.hpp>
#include <LivingObject.hpp>
#include <Camera.hpp>
#include <Level.hpp>

/* Variables */
const float FPS = 60;
const int SCREEN_W = 1080;
const int SCREEN_H = 720;
bool comAudio = true;
bool key[ALLEGRO_KEY_MAX];
bool redraw = false;

/* Functions */
int initAllegro(ALLEGRO_DISPLAY **display, ALLEGRO_EVENT_QUEUE **event_queue,
    ALLEGRO_TIMER **timer, ALLEGRO_FONT **font, ALLEGRO_SAMPLE **som);
void destroyAllegro(ALLEGRO_DISPLAY **display, ALLEGRO_EVENT_QUEUE **event_queue,
    ALLEGRO_TIMER **timer, ALLEGRO_FONT **font, ALLEGRO_SAMPLE **som);
