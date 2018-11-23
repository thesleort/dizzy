#ifndef __CORE_HPP
#define __CORE_HPP

#include "types.hpp"

#define SPEED_OF_SOUND 331.3 // Speed at 0 degree celcius

namespace dizzy {
class Core {
public:
    Core(Field &fld, Camera &cam);
    void set_temperature(float celcius);
    Sound_levels* get_stereo(float direction);
    Sound_levels* get_stereo(float x, float y);
    Sound_levels* get_surround(float direction);
    Sound_levels* get_surround(float x, float y);
protected:
    Camera *m_cam;
    Field *m_field;
    float m_max_delay;
    float m_temperature = 10;
    Sound_levels m_sound_levels;
    float current_speed_of_sound(void);
    float calculate_delay(Microphone &mic);
    float calculate_distance(Microphone &mic);
    float calculate_distance(float x, float y, float z);
    Sound* get_closest_right();
    Sound* get_closest_left();
    Sound* get_third_closest();
    // std::vector <sound_levels> m_cam_sound_levels;
};
}
#endif