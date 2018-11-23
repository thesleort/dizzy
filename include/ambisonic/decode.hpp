#ifndef __AMBISONIC_DECODE_HPP
#define __AMBISONIC_DECODE_HPP

#include "ambisonic.hpp"
#include "types.hpp"

#include <vector>

namespace dizzy {
namespace ambisonic {
class Decode {
public:
    Decode(microphone &mic);

    void process(std::vector<float> *output);

protected:
    microphone *m_mic;
};
} // namespace ambisonic
} // namespace dizzy

#endif