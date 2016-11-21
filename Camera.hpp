#ifndef CAMERA
#define CAMERA

#ifndef PENTAGONCOMMANDER_HPP
#define PENTAGONCOMMANDER_HPP
#include <PentagonCommander.hpp>
#endif //PENTAGONCOMMANDER_HPP

#ifndef LEVEL
#include <Level.hpp>
#define LEVEL
#endif // LEVEL

class Camera
{
private:
    b2Vec2 lv_pos;
    float px_x;
    float px_y;
    float px_width;
    float px_height;
    LivingObject *focused_player;
    Level *level;
    ALLEGRO_BITMAP *screen;
    GraphicElement background;
    GraphicElement *independent_elements;
    int n_independent_elements;
public:
    void setNIndependentElements(int _n_independent_elements);
    void setIndependentElements(GraphicElement *_independent_elements);
    void createScreen(float _px_x, float _px_y);
    void record();
    void play(ALLEGRO_DISPLAY *display);
    void setLvPos(b2Vec2 player_pos);
    void setWidthAndHeight(float _px_width, float _px_height);
    void setLevel(Level *_level);
};

void Camera::setLevel(Level *_level)
{
    level = _level;
}

void Camera::setNIndependentElements(int _n_independent_elements)
{
    n_indenpent_elements = _n_independent_elements;
}

void Camera::setIndependentElements(GraphicElement *_independent_elements)
{
    independent_elements = _independent_elements;
}

void Camera::setLvPos(b2Vec2 player_pos)
{
    lv_pos = player_pos;
}

void Camera::setWidthAndHeight(float _px_width, float _px_height)
{
    px_width = _px_width;
    px_height = _px_height;
}

void Camera::createScreen(float _px_x, float _px_y)
{
    px_x = _px_x;
    px_y = _px_y;
    screen = al_create_bitmap(px_width, px_height);
}

void Camera::play(ALLEGRO_DISPLAY *display)
{
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(screen, px_x, px_y, 0);
    al_flip_display();
}

void Camera::record()
{
    int i;
    b2Vec2 body_pos, rect_dist;
    background.setCorner(0, 0);
    background.setDrawingTarget(screen);
    background.printOnScreen();
    for(i=0; i<level->getNPhysicalObjects(); i++)
    {
        body_pos = level->physical_object[i].body->GetPosition();
        if((body_pos.x + level->physical_object[i].getWidth()/2 > lv_pos.x) || (body_pos.x - level->physical_object[i].getWidth()/2 < (lv_pos.x + pixelsToMeters(px_width))))
        {
            if((body_pos.y + pixelsToMeters(level->physical_object[i].getHeight()/2) < lv_pos.y - pixelsToMeters(px_height))
               || (body_pos.y - pixelsToMeters(level->physical_object[i].getHeight()/2) > lv_pos.y))
            {
                rect_dist.x = metersToPixels(body_pos.x - lv_pos.x);
                rect_dist.y = metersToPixels(lv_pos.y - body_pos.y);
                level->physical_object[i].setCenter(rect_dist.x, rect_dist.y);
                level->physical_object[i].getCornerFromCenter();
                level->physical_object[i].setDrawingTarget(screen);
                level->physical_object[i].printOnScreen();
            }
        }
    }
    for(i=0; i<level->getNLivingObjects(); i++)
    {
        body_pos = level->living_object[i].body->GetPosition();
        if(((body_pos.x + level->living_object[i].getWidth()/2) > lv_pos.x) || (body_pos.x - level->living_object[i].getWidth()/2 < (lv_pos.x + pixelsToMeters(px_width))))
        {
            if((body_pos.y + pixelsToMeters(level->living_object[i].getHeight()/2) < (lv_pos.y - pixelsToMeters(px_height)))
               || (body_pos.y - pixelsToMeters(level->living_object[i].getHeight()/2) > lv_pos.y))
            {
                rect_dist.x = metersToPixels(body_pos.x - lv_pos.x);
                rect_dist.y = metersToPixels(lv_pos.y - body_pos.y);
                level->living_object[i].setCenter(rect_dist.x, rect_dist.y);
                level->living_object[i].getCornerFromCenter();
                level->living_object[i].setDrawingTarget(screen);
                level->living_object[i].printOnScreen();
            }
        }
    }
    for(i=0; i<level->getNPlayers(); i++)
    {
        body_pos = level->player[i].body->GetPosition();
        if((body_pos.x + level->player[i].getWidth()/2 > lv_pos.x) || (body_pos.x - level->player[i].getWidth()/2 < (lv_pos.x + pixelsToMeters(px_width))))
        {
            if((body_pos.y + pixelsToMeters(level->player[i].getHeight()/2) < lv_pos.y - pixelsToMeters(px_height))
               || (body_pos.y - pixelsToMeters(level->player[i].getHeight()/2) > lv_pos.y))
            {
                rect_dist.x = metersToPixels(body_pos.x - lv_pos.x);
                rect_dist.y = metersToPixels(lv_pos.y - body_pos.y);
                level->player[i].setCenter(rect_dist.x, rect_dist.y);
                level->player[i].getCornerFromCenter();
                level->player[i].setDrawingTarget(screen);
                level->player[i].printOnScreen();
            }
        }
    }
    for(i=0; i<n_independent_elements; i++)
    {
        independent_elements[i].setDrawingTarget(screen);
        independent_elements[i].printOnScreen();
    }
}

#endif //CAMERA
