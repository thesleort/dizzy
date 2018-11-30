#ifndef __AMBISONIC_SETUP_HPP
#define __AMBISONIC_SETUP_HPP

#include "ambisonic.hpp"

namespace dizzy {
namespace ambisonic {

    class Setup {
public:
    Setup(dimension dim);
    void add_microphone(Microphone &mic);
    void add_signal(Signal_type sig);


private:
    dimension m_dimension;
    Microphone *m_mic;
};
}
} // namespace dizzy

#endif