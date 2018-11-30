#ifndef __AMBISONIC_DECODE_UHJ_HPP
#define __AMBISONIC_DECODE_UHJ_HPP

#include "ambisonic.hpp"
#include "ambisonic/decode.hpp"

namespace dizzy {
namespace ambisonic {
class UHJDecode : public dizzy::ambisonic::Decode {
    public:
        UHJDecode(Microphone &mic);
        void process();
};
} // namespace ambisonic
} // namespace dizzy

#endif