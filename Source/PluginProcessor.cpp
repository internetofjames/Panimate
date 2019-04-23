/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PanimateAudioProcessor::PanimateAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

PanimateAudioProcessor::~PanimateAudioProcessor()
{
}

//==============================================================================
const String PanimateAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PanimateAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PanimateAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PanimateAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double PanimateAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PanimateAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int PanimateAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PanimateAudioProcessor::setCurrentProgram (int index)
{
}

const String PanimateAudioProcessor::getProgramName (int index)
{
    return {};
}

void PanimateAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void PanimateAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    // we need sampleRate, current play position (for consistent autopanning performance)
    // etc as playback is initiated
    panner.setFs(sampleRate);
    
}

void PanimateAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PanimateAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void PanimateAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    playHead = this->getPlayHead();
    playHead->getCurrentPosition(currentPositionInfo);

    this->panner.setCurrentAngle(currentPositionInfo.timeInSeconds);
    
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    
    // Copy the AudioBuffer data into a new object
    AudioBuffer<float> mono_buffer = AudioBuffer<float>(buffer);
    
    // add in the data from any additional channels to the first one and then clear the no longer needed channels
    for (auto i = 1; i < totalNumInputChannels; ++i) {
        mono_buffer.addFrom(0, 0, mono_buffer, i, 0, mono_buffer.getNumSamples());
        mono_buffer.clear(i, 0, mono_buffer.getNumSamples());
    }
    
    for (int sample = 0; sample < buffer.getNumSamples() ; ++sample){
        
        // get the sample from the mono_buffer
        float x = mono_buffer.getWritePointer(0)[sample];
        
        for (int channel = 0; channel < totalNumInputChannels ; ++channel){
            
            float y = panner.processSample(x,channel);
            
            buffer.getWritePointer(channel)[sample] = y;
        }
    }
}

//==============================================================================
bool PanimateAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* PanimateAudioProcessor::createEditor()
{
    return new PanimateAudioProcessorEditor (*this);
}

//==============================================================================
void PanimateAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void PanimateAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PanimateAudioProcessor();
}
