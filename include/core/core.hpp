#ifndef __CORE_HPP
#define __CORE_HPP

#include "core/types.hpp"

#define SPEED_OF_SOUND 331.3 // Speed at 0 degree celcius

class core {
public:
    core(field &fld, camera &cam);
    void set_temperature(float celcius);
    sound_levels* get_stereo(float direction);
    sound_levels* get_stereo(float x, float y);
    sound_levels* get_surround(float direction);
    sound_levels* get_surround(float x, float y);
protected:
    camera *m_cam;
    field *m_field;
    float m_max_delay;
    float m_temperature = 10;
    sound_levels m_sound_levels;
    float current_speed_of_sound(void);
    float calculate_delay(microphone &mic);
    float calculate_distance(microphone &mic);
    float calculate_distance(float x, float y);
    sound* get_closest_right();
    sound* get_closest_left();
    sound* get_third_closest();
    // std::vector <sound_levels> m_cam_sound_levels;
};

#endif