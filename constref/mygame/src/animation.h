#pragma once

#include "timer.h"

class Animation
{
    int frame_count;
    Timer timer;

public:
    Animation() : frame_count(0), timer(0) {}

    Animation(int frame_count, float length) : frame_count(frame_count), timer(length) {}

    float get_length() const
    {
        return timer.get_length();
    }

    int current_frame() const
    {
        return static_cast<int>(timer.get_time() / (timer.get_length() * frame_count));
    }

    void step(float delta_time)
    {
        timer.step(delta_time);
    }
};
