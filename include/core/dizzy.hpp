#ifndef __DIZZY_HPP
#define __DIZZY_HPP

#include <vector>
#include "core/types.hpp"

class dizzy {
    class setup;
    class core;
public:
    dizzy();

protected:

    float m_xlength;
    float m_ylength;
    std::vector<microphone*> m_microphones;
    std::vector<camera*> m_cameras;
    field m_field;
};

#endif