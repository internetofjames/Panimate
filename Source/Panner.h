/*
  ==============================================================================

    Panner.h
    Created: 28 Feb 2019 1:43:53pm
    Author:  James Bertrand

  ==============================================================================
*/

#ifndef PANNER_H
#define PANNER_H

#include <stdio.h>

class Panner {

public:
    // properties
    enum TypeLFO {sine=1,square=2,triangle=3,sawtooth=4};
    TypeLFO LFO = sine;
    
    // methods
    float processSample(float x, int channel);
    
    void setFs(int sampleRate);
    int getFs();
    
    void setRate(float rateInMilliseconds);
    float getRate();
    
    void setDepth(float depth);
    float getDepth();
    
    void setPhaseOffset(float phaseOffsetInDegrees);
    float getPhaseOffset();
    
    void setPosiitonOffset(float panPositionOffset);
    float getPositionOffset();
    
    void setTempoSynced(bool isSynced);
    bool isTempoSynced();
    
    void setPhaseInverted(bool isInverted);
    bool isPhaseInverted();
    
    void setCurrentAngle(float currentPlaybackPosition);
    
    void setLFOType(TypeLFO type);
    TypeLFO getLFOType();
    
    
private:
    // properties
    int Fs = 48000;
    int channel = 0;
    
    float rate = 1.0f; // interpreted as the period of the LFO, in seconds
    float depth = 0.0f;
    float phaseOffset = 0.0f;
    float positionOffset = 0.0f;
    
    float currentAngle = 0.0f;
    
    bool tempoSynced = false;
    bool phaseInverted = false;
    
    // methods
    float sineFunction();
    float squareFunction();
    float sawtoothFunction();
    float triangleFunction();
    
    void updateAngle();
    float getNextSample();
    
};

#endif /* Panner.h */
