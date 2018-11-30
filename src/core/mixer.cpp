#include "core/mixer.hpp"

dizzy::Mixer::Mixer(Field f) {
    m_field = f;
    channels = f.microphones.size();
} 