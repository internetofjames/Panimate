/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class PanimateAudioProcessorEditor  : public AudioProcessorEditor, public Slider::Listener, public Button::Listener, public ComboBox::Listener
{
public:
    PanimateAudioProcessorEditor (PanimateAudioProcessor&);
    ~PanimateAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider* slider) override;
    void buttonClicked(Button* button) override;
    void comboBoxChanged(ComboBox* comboBox) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PanimateAudioProcessor& processor;
    
    // Panimate interface controls
    Slider depth;
    Slider phaseOffset;
    Slider rate;
    Slider positionOffset;
    // Labels for Sliders
    Label depthLabel;
    Label phaseOffsetLabel;
    Label rateLabel;
    Label positionOffsetLabel;
    

    TextButton phaseInvert;
    TextButton tempoSync;
    Label speedLabel;
    
    ComboBox LFOtype;
    Label LFOtypeLabel;
    
//    enum TempoSyncValues {", };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PanimateAudioProcessorEditor)
};
