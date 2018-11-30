#include <cmath>

#include "core/core.hpp"
#include "ambisonic/ambisonic.hpp"

dizzy::Core::Core(Field &fld, Camera &cam) {
    m_field = &fld;
    m_cam = &cam;

    for (unsigned i = 0; i < m_field->microphones.size(); ++i) {
        Sound s;
        m_sound_levels.mic_levels.push_back(s);
        switch (m_field->microphones[i]->source) {
        case MONO:
            m_field->microphones[i]->sources.push_back(s);
            break;
        case STEREO:
            m_field->microphones[i]->sources.push_back(s);
            m_field->microphones[i]->sources.push_back(s);
            break;
        default:
            m_field->microphones[i]->sources.push_back(s);
            m_field->microphones[i]->sources.push_back(s);
            break;
        }
    }
}

/**
 * @brief Is supposed to create a 50/50 balance between 
 * the microphones l
 * 
 * @param direction 
 * @return sound_levels* 
 */
Sound_levels *dizzy::Core::get_stereo(float direction) {

    // for (unsigned i = 0; i < m_sound_levels.mic_levels[i].mic->position_x; ++i) {
    //     // if()
    // }
}

/**
 * @brief 
 * 
 * @param x position
 * @param y position
 * @return sound_levels* 
 */
Sound_levels *dizzy::Core::get_stereo(float x, float y) {
    // TODO:
}

Sound_levels *dizzy::Core::get_surround(float direction) {
}

Sound_levels *dizzy::Core::get_surround(float x, float y) {
}

void dizzy::Core::set_temperature(float celcius) {
    m_temperature = celcius;
}

float dizzy::Core::current_speed_of_sound(void) {
    float speed;

    speed = 331.3 * std::sqrt(1 + (m_temperature / 273.15));

    // speed = SPEED_OF_SOUND + (0.6 * m_temperature); // Only works between -35 and 35 degree celsius

    return speed;
}

float dizzy::Core::calculate_delay(Microphone &mic) {
    float delay = 0;
    float distance = calculate_distance(mic);

    delay = distance / current_speed_of_sound();

    if (delay > m_max_delay) {
        m_max_delay = delay;
    }
    return delay;
}

float dizzy::Core::calculate_distance(Microphone &mic) {
    float distance = calculate_distance(mic.position_x, mic.position_y, mic.position_z);

    for (unsigned i = 0; i < mic.sources.size(); ++i) {
        mic.sources[i].distance = distance;
    }
    return distance;
}

float dizzy::Core::calculate_distance(float x, float y, float z) {
    float distance = 0;

    distance = std::sqrt(
        std::pow((x - (m_cam->position_x)), 2) +
        std::pow((y - (m_cam->position_y)), 2) +
        std::pow((z - (m_cam->position_z)), 2));

    return distance;
}