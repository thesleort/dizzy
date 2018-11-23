#include "core/mixer.hpp"

dizzy::Mixer::Mixer(field f) {
    m_field = f;
    channels = f.microphones.size();
} 