#ifndef __AMBISONIC_DECODE_HPP
#define __AMBISONIC_DECODE_HPP

#include "ambisonic.hpp"
#include "types.hpp"

#include <vector>

namespace dizzy {
namespace ambisonic {
class Decode {
public:
    Decode(Microphone &mic);

    void process(std::vector<float> *output);

protected:
    Microphone *m_microphone;
};
} // namespace ambisonic
} // namespace dizzy

#endif