/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PanimateAudioProcessorEditor::PanimateAudioProcessorEditor (PanimateAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    PanimateAudioProcessorEditor::setResizable(true, true);
    
    // add Panimate interface controls
    
    // ComboBox for LFO type selection
    LFOtype.addListener(this);
    LFOtype.setBounds(25, 50, 200, 25);
    LFOtype.addItem("Sine", 1);
    LFOtype.addItem("Square", 2);
    LFOtype.addItem("Triangle", 3);
    LFOtype.addItem("Sawtooth", 4);
    LFOtype.setSelectedId(1);
    LFOtype.setJustificationType(Justification::centred);
    addAndMakeVisible(LFOtype);
    
    LFOtypeLabel.setText("Pan Type", dontSendNotification);
    LFOtypeLabel.attachToComponent(&LFOtype, false);
    LFOtypeLabel.setJustificationType(Justification::left);
    addAndMakeVisible(LFOtypeLabel);
    
    // Slider for depth
    depth.addListener(this);
    depth.setBounds(25, 125, 110, 110);
    depth.setSliderStyle(Slider::RotaryVerticalDrag);
    depth.setRange(0, 100, 1);
    depth.setValue(100);
    depth.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 15);
    depth.setNumDecimalPlacesToDisplay(0);
    depth.setTextValueSuffix("%");
    addAndMakeVisible(depth);
    
    depthLabel.setText("Depth", dontSendNotification);
    depthLabel.attachToComponent(&depth, false);
    depthLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(depthLabel);
    
    
    // Slider for LFO phase offset
    phaseOffset.addListener(this);
    phaseOffset.setBounds(25, 275, 110, 110);
    phaseOffset.setSliderStyle(Slider::RotaryVerticalDrag);
    phaseOffset.setRange(0, 360, 1);
    phaseOffset.setValue(0);
    phaseOffset.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 15);
    phaseOffset.setNumDecimalPlacesToDisplay(0);
    addAndMakeVisible(phaseOffset);
    
    phaseOffsetLabel.setText("Phase Offset", dontSendNotification);
    phaseOffsetLabel.attachToComponent(&phaseOffset, false);
    phaseOffsetLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(phaseOffsetLabel);
    
    // Slider for rate
    rate.addListener(this);
    rate.setBounds(550, 125, 110, 110);
    rate.setSliderStyle(Slider::RotaryVerticalDrag);
    rate.setRange(0, 10000);
    rate.setValue(0);
    rate.setSkewFactor(0.35);
    rate.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 15);
    rate.setNumDecimalPlacesToDisplay(3);
    addAndMakeVisible(rate);
    
    rateLabel.setText("Rate (ms)", dontSendNotification);
    rateLabel.attachToComponent(&rate, false);
    rateLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(rateLabel);
    
    // ComboBox for rateBars
    // not visible by default
    rateBars.addListener(this);
    rateBars.setBounds(560, 110, 90, 40);
    rateBars.addItem("0", 1);
    rateBars.addItem("1", 2);
    rateBars.addItem("2", 3);
    rateBars.addItem("3", 4);
    rateBars.addItem("4", 5);
    rateBars.addItem("5", 6);
    rateBars.addItem("6", 7);
    rateBars.addItem("7", 8);
    rateBars.addItem("8", 9);
    rateBars.setSelectedId(2);
    rateBars.setJustificationType(Justification::centred);
    addChildComponent(&rateBars);
    
    barsLabel.setText("Bars:", dontSendNotification);
    barsLabel.attachToComponent(&rateBars, false);
    barsLabel.setJustificationType(Justification::centred);
    addChildComponent(&barsLabel);
    
    // ComboBox for rateBeats
    // not visible by default
    rateBeats.addListener(this);
    rateBeats.setBounds(560, 190, 90, 40);
    rateBeats.addItem("1/2", 1);
    rateBeats.addItem("1/4", 2);
    rateBeats.addItem("1/8", 3);
    rateBeats.addItem("1/16", 4);
    rateBeats.addItem("1/32", 5);
    rateBeats.addItem("1/64", 6);
    rateBeats.addItem("0", 7);
    rateBeats.setSelectedId(7);
    rateBeats.setJustificationType(Justification::centred);
    addChildComponent(&rateBeats);
    
    beatsLabel.setText("Beats:", dontSendNotification);
    beatsLabel.attachToComponent(&rateBeats, false);
    beatsLabel.setJustificationType(Justification::centred);
    addChildComponent(&beatsLabel);
    
    // Slider for pan position starting point
    positionOffset.addListener(this);
    positionOffset.setBounds(550, 275, 110, 110);
    positionOffset.setSliderStyle(Slider::RotaryVerticalDrag);
    positionOffset.setRange(-100, 100, 1);
    positionOffset.setValue(0);
    positionOffset.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 15);
    positionOffset.setNumDecimalPlacesToDisplay(0);
    addAndMakeVisible(positionOffset);
    
    positionOffsetLabel.setText("Start Position", dontSendNotification);
    positionOffsetLabel.attachToComponent(&positionOffset, false);
    positionOffsetLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(positionOffsetLabel);
    
    // Toggle button for phase inversion
    phaseInvert.addListener(this);
    phaseInvert.setBounds(200, 25, 25, 25);
    phaseInvert.setClickingTogglesState(true);
    phaseInvert.setButtonText(String (CharPointer_UTF8 ("Ø")));
    addAndMakeVisible(phaseInvert);
    
    // Text button for tempo synchronization
    tempoSync.addListener(this);
    tempoSync.setBounds(475, 50, 200, 25);
    tempoSync.setClickingTogglesState(true);
    tempoSync.setButtonText("Tempo Sync : OFF");
    addAndMakeVisible(tempoSync);
    
    speedLabel.setText("Speed", dontSendNotification);
    speedLabel.attachToComponent(&tempoSync, false);
    speedLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(speedLabel);
    
    PanimateAudioProcessorEditor::setResizeLimits(300, 200, 3500, 2000);
    setSize (700, 400);
    
}

PanimateAudioProcessorEditor::~PanimateAudioProcessorEditor()
{
}

//==============================================================================
void PanimateAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (30.0f);
    g.drawFittedText ("Panimate", getLocalBounds(), Justification::centredTop, 1);
    g.drawFittedText("Graphic TBA...", getLocalBounds(), Justification::centred, 5);
}

void PanimateAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    // Uses AffineTransform::scale to properly scale plugin components when window is resized
    LFOtype.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    LFOtypeLabel.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    
    phaseInvert.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    
    depth.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    depthLabel.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    
    phaseOffset.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    phaseOffsetLabel.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    
    
    rate.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    rateLabel.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    
    rateBars.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    barsLabel.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    
    rateBeats.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    beatsLabel.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    
    positionOffset.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    positionOffsetLabel.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    
    tempoSync.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));
    
    speedLabel.setTransform(AffineTransform::scale(getWidth() / 700.f, getHeight() / 400.f));

}

void PanimateAudioProcessorEditor::sliderValueChanged(Slider *slider) {
    
    // set depth property of panner
    if (slider == &depth) {
        processor.panner.setDepth(slider->getValue());
    }
    
    // set phase offset property of panner
    if (slider == &phaseOffset) {
        processor.panner.setPhaseOffset(slider->getValue());
    }
    
    // only set rate property of panner from this slider if tempoSync is toggled off
    if (slider == &rate && tempoSynced == false) {
        rateValue = slider->getValue();
        processor.panner.setRate(rateValue);
        
        // dynamically change decimal place of value that is displayed
        if (rateValue < 100.f){
            slider->setNumDecimalPlacesToDisplay(3);
        }
        if (rateValue >= 100.f && rateValue < 1000.f){
            slider->setNumDecimalPlacesToDisplay(2);
        }
        if  (rateValue >= 1000.f && rateValue < 10000.f){
            slider->setNumDecimalPlacesToDisplay(0);
        }
    }
    
    if (slider == &positionOffset) {
        processor.panner.setPositonOffset(slider->getValue());
    }
    
}

void PanimateAudioProcessorEditor::buttonClicked(Button *button) {
    
    if (button == &tempoSync) {
        if (button->getToggleState() == true) {
            // tempoSync is toggled on
            // change tempo sync button color to show functionality
            button->setColour(TextButton::ColourIds::buttonOnColourId, Colour(255, 255, 0));
            button->setColour(TextButton::ColourIds::textColourOnId, Colour(0, 0, 0));
            button->setButtonText("Temp Sync : ON");
            rate.setVisible(false);
            rateBars.setVisible(true);
            rateBeats.setVisible(true);
            tempoSynced = true;
            processor.panner.setTempoSynced(true);
            processor.panner.setRate(tempoSyncBarValueMap.at(barValue), tempoSyncBeatValueMap.at(beatValue));
        }
        else {
            // tempoSync is toggled off
            button->setColour(TextButton::ColourIds::buttonColourId, Colour(0, 0, 0));
            button->setColour(TextButton::ColourIds::textColourOnId, Colour(255, 255, 255));
            button->setButtonText("Temp Sync : OFF");
            rate.setVisible(true);
            rateBars.setVisible(false);
            rateBeats.setVisible(false);
            tempoSynced = false;
            processor.panner.setTempoSynced(false);
            processor.panner.setRate(rateValue);
        }
    }
    if (button == &phaseInvert) {
        if (button->getToggleState() == true) {
            // phaseInvert is toggled on
            button->setColour(TextButton::ColourIds::buttonOnColourId, Colour(255, 255, 0));
            button->setColour(TextButton::ColourIds::textColourOnId, Colour(0, 0, 0));
            phaseInverted = true;
            processor.panner.setPhaseInverted(true);
        }
        else {
            // phaseInvert is toggled off
            button->setColour(TextButton::ColourIds::buttonColourId, Colour(0, 0, 0));
            button->setColour(TextButton::ColourIds::textColourOnId, Colour(255, 255, 255));
            phaseInverted = false;
            processor.panner.setPhaseInverted(false);
        }
        
    }
}

void PanimateAudioProcessorEditor::comboBoxChanged(ComboBox *comboBox) {
    
    if (comboBox == &LFOtype) {
        processor.panner.LFO = (Panner::TypeLFO)comboBox->getSelectedId();
    }
    
    if (comboBox == &rateBars && tempoSynced == true) {
        barValue = rateBars.getSelectedId();
    }
    
    if (comboBox == &rateBeats && tempoSynced == true) {
        beatValue = rateBeats.getSelectedId();
    }
    
    if (tempoSynced) {
        processor.panner.setRate(tempoSyncBarValueMap.at(barValue), tempoSyncBeatValueMap.at(beatValue));
    }
    
}
