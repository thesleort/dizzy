#include "ambisonic/decode.hpp"

dizzy::ambisonic::Decode::Decode(microphone &mic) {
    m_mic = &mic;
}

