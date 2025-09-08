#pragma once

#include "timer.h"

class Animation
{
    Timer timer;
    int frame_count;

public:
    Animation(): timer(0), frame_count(0) {}

    Animation(int frame_count, float length): timer(length), frame_count(frame_count) {}

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
