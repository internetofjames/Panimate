/*
  ==============================================================================

    Panner.cpp
    Created: 28 Feb 2019 1:43:53pm
    Author:  James Bertrand

  ==============================================================================
*/

#include "Panner.h"
#include <math.h>

float Panner::processSample(float x,int channel){
    
    this->channel = channel;
    
    // Output variable
    float y;
    float lfo;
    
    lfo = getNextSample();
    
    y = x * lfo;
    
    return y;
    
};

// Set the sample rate that the panner should operate at
// This should be set by your DAW
void Panner::setFs(int sampleRate){
    // check for valid sample rate
    if (sampleRate == 44100 || sampleRate == 48000 || sampleRate == 96000 || sampleRate == 192000){
        Fs = sampleRate;
    }
};

int Panner::getFs(){
    return Fs;
};

// Set the period of the LFO in milliseconds
void Panner::setRate(float rateInMilliseconds){
    rate = rateInMilliseconds;
    
    angleChange = ((1.0f/rateInMilliseconds) * 2.0f * M_PI / (float)Fs) + phaseOffset;
}

float Panner::getRate(){
    return rate;
};

// Set the max amplitude of the LFO
void Panner::setDepth(float depth){
    this->depth = depth;
};

float Panner::getDepth(){
    return depth;
};

// Set the phase offset that the LFO will begin at
void Panner::setPhaseOffset(float phaseOffsetInDegrees){
    phaseOffset = phaseOffsetInDegrees;
};

float Panner::getPhaseOffset(){
    return phaseOffset;
};

// Set the position offset that the panner will begin within the stereo field
void Panner::setPosiitonOffset(float panPositionOffset){
    positionOffset = panPositionOffset;
};

float Panner::getPositionOffset(){
    return positionOffset;
};

// Set whether or not the LFO is tempo synced
void Panner::setTempoSynced(bool isSynced){
    tempoSynced = isSynced;
}

bool Panner::isTempoSynced(){
    return tempoSynced;
};

void Panner::setPhaseInverted(bool isInverted){
    phaseInverted = isInverted;
};

bool Panner::isPhaseInverted(){
    return phaseInverted;
};

void Panner::setLFOType(TypeLFO type){
    LFO = type;
};

Panner::TypeLFO Panner::getLFOType(){
    return LFO;
};

// LFO functions
float Panner::sineFunction(){
    float out = sinf(currentAngle[channel]);
    
    updateAngle();
    
    return out;
}

float Panner::squareFunction(){
    float out;
    if(currentAngle[channel] < M_PI){
        out = 1.0f;
    }
    else {
        out = -1.0f;
    }
    
    updateAngle();
    
    return out;
}


float Panner::sawtoothFunction(){
    float out = 2.0f * (currentAngle[channel]/(2.0f*M_PI)) - 1.0f;
    
    updateAngle();
    
    return out;
}


float Panner::triangleFunction(){
    float out;
    if(currentAngle[channel] < M_PI){
        out = 2.0f * (currentAngle[channel]/(M_PI)) - 1.0f;
    }
    else {
        float temp = 1.0f - ((currentAngle[channel]-M_PI)/(M_PI));
        out = 2.0f * temp - 1.0f;
    }
    
    updateAngle();
    
    return out;
}



void Panner::updateAngle(){
    currentAngle[channel] += angleChange;
    if (currentAngle[channel] > 2*M_PI){
        currentAngle[channel] -= (2*M_PI);
    }
}


float Panner::getNextSample(){
    
    float lfo=0.0f;
    
    switch (LFO) {
        case sine:
            lfo = depth * sineFunction() + positionOffset;
            break;
            
        case square:
            lfo = depth * squareFunction() + positionOffset;
            break;
            
        case sawtooth:
            lfo = depth * sawtoothFunction() + positionOffset;
            break;
            
        case triangle:
            lfo = depth * triangleFunction() + positionOffset;
            break;
            
        default: // sine as a back-up
            lfo = depth * sineFunction() + positionOffset;
            break;
    }
    
    // if the combination of user defined parameters causes the LFO to exceed the maximum
    // possible pan values of -100 (full left) or 100 (full right) set them to the max
    if (lfo > 100){
        lfo = 100.0f;
    }
    if (lfo < -100){
        lfo = -100.0f;
    }
    
    int phaseInvert = 1;
    if (phaseInverted) {
        phaseInvert = -1;
    }
    
    lfo *= phaseInvert;
    
    return lfo;
}
