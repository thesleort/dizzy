#ifndef __CORE_HPP
#define __CORE_HPP

#include "core/types.hpp"

class core {
public:
    core(field &fld, camera &cam);
    sound_levels* get_stereo(float direction);
    sound_levels* get_surround(float direction);
protected:
    camera &m_cam;
    field &m_field;
    std::vector <sound_levels> m_cam_sound_levels;
};

#endif