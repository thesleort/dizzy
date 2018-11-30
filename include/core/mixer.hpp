#ifndef __MIXER_HPP
#define __MIXER_HPP

#include "types.hpp"
#include <vector>

namespace dizzy {
    class Mixer {
        public:
        Mixer(Field f);
        void set_microphone_volume(Microphone &mic);

        float get_microphone_volume(Microphone &mic);
        private:
            Field m_field;
            unsigned channels;
    };
}

#endif