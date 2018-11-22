#ifndef __AMBISONIC_SETUP_HPP
#define __AMBISONIC_SETUP_HPP

#include "ambisonic.hpp"

namespace dizzy {
namespace ambisonic {

    class Setup {
public:
    Setup(dimension dim);
    void add_microphone(microphone &mic);
    void add_signal(signal_type sig);


private:
    dimension m_dimension;
    microphone *m_mic;
};
}
} // namespace dizzy

#endif