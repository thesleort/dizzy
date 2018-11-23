#ifndef __AMBISONIC_ENCODE_HPP
#define __AMBISONIC_ENCODE_HPP

#include <iostream>

#include "ambisonic/ambisonic.hpp"
#include "types.hpp"

namespace dizzy {
namespace ambisonic {

class Encode {
public:
    Encode(microphone &mic, unsigned order);

    void set_coordinates(const float radius, const float azimuth, const float elevation);
    void set_radius(const float radius);
    void set_azimuth(const float azimuth);
    void set_elevation(const float elevation);
    
    void enqueue_signals(std::vector<signal> signals);
private:
    microphone *m_mic;
    unsigned m_order;

    float m_radius;
    float m_azimuth;
    float m_elevation;
};

}
} // namespace dizzy

#endif