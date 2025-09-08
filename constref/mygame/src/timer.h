#pragma once

class Timer
{
    float length, time;
    bool timeout;

 public:
    Timer(float length): length(length), time(0), timeout(false) {}

    void step(float delta_time)
    {
        time += delta_time;
        if (time >= length) {
            time -= length;
            timeout = true;
        }
    }

    bool is_timeout() const
    {
        return this->timeout;
    }

    float get_time() const
    {
        return this->time;
    }

    float get_length() const
    {
        return this->length;
    }

    void reset()
    {
        this->time = 0;
    }
};
