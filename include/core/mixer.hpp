#ifndef __MIXER_HPP
#define __MIXER_HPP

#include "types.hpp"
#include <vector>

namespace dizzy {
    class Mixer {
        public:
        Mixer(field f);
        void set_microphone_volume(microphone &mic);

        float get_microphone_volume(microphone &mic);
        private:
            field m_field;
            unsigned channels;
    };
}

#endif