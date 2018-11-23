#include "ambisonic/decode.hpp"

dizzy::ambisonic::Decode::Decode(microphone &mic) {
    m_mic = &mic;
}

void dizzy::ambisonic::Decode::process(std::vector<float> *output) {

    for (unsigned i = 0; i < m_mic->sources.size(); ++i) {
        float result = 0;
        for (unsigned j = 0; j < output->size(); ++j) {
            
        }
        output[i].push_back(result);
    }
}