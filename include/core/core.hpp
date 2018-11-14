#ifndef __CORE_HPP
#define __CORE_HPP

#include <vector>
#include "core/types.hpp"

class dizzy {
public:
    dizzy(float length, float width);
    void add_microphone(float position_x, float position_y);
    void add_camera(float position_x, float position_y, float direction);

    // Setter functions
    void set_length_x(float length);
    void set_length_y(float length);

    // Getter functions
    float get_length_x();
    float get_length_y();

    field *get_config();

private:
    float m_xlength;
    float m_ylength;
    std::vector<microphone*> m_microphones;
    std::vector<camera*> m_cameras;
    void update_norms();
    float normalize_coord(float total_size, float input);
    float normalize_direction(float direction);

    field m_field;
};

#endif