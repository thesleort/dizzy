#ifndef __AMBISONIC_DECODE_HPP
#define __AMBISONIC_DECODE_HPP

#include "ambisonic.hpp"
#include "types.hpp"

namespace dizzy {
namespace ambisonic {
class Decode {
public:
    Decode(microphone &mic);

private:
    microphone *m_mic;
};
} // namespace ambisonic
} // namespace dizzy

#endif