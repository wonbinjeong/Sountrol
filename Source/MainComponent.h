#pragma once

#include <JuceHeader.h>

//class SettingsWindow : public juce::DocumentWindow, juce::AudioAppComponent
//{ 
//public:
//    SettingsWindow(const juce::String name)
//        : DocumentWindow(name,
//            juce::Desktop::getInstance().getDefaultLookAndFeel()
//            .findColour(juce::ResizableWindow::backgroundColourId),
//            DocumentWindow::allButtons), audioSetupComp(deviceManager, 0, 256, 0, 256, false, false, false, false)
//    {
//        setBounds(20, 20, 300, 400);
//        setResizable(true, false);
//        setUsingNativeTitleBar(true);
//    }
//
//    void closeButtonPressed() {
//        setVisible(false);
//    }
//
//private:
//    juce::AudioDeviceSelectorComponent audioSetupComp;
//    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SettingsWindow);
//};

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void updateOnOffState(juce::Button* button);

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

    void initializeFrequencies();
    void updateParameters();

private:
    //==============================================================================
    // Your private member variables go here...

    //std::unique_ptr<SettingsWindow> window;

    //void showSettingsWindow()
    //{
    //    if (window == nullptr) {
    //        window.reset(new SettingsWindow("Window"));
    //    }
    //    window->setVisible(true);
    //}

    juce::Slider slider1;
    juce::Slider slider2;
    juce::Slider slider3;
    juce::Slider slider4;
    juce::Label lblSlider1;
    juce::Label lblSlider2;
    juce::Label lblSlider3;
    juce::Label lblSlider4;

    juce::TextButton btnResetSlider1{ "Reset" };
    juce::TextButton btnResetSlider2{ "Reset" };
    juce::TextButton btnResetSlider3{ "Reset" };
    juce::TextButton btnResetSlider4{ "Reset" };
    
    juce::ToggleButton btnBypassSlider1{ "Bypass" };
    juce::ToggleButton btnBypassSlider2{ "Bypass" };
    juce::ToggleButton btnBypassSlider3{ "Bypass" };
    juce::ToggleButton btnBypassSlider4{ "Bypass" };

private:
    float freq1Low, freq1High, freq2Low, freq2High, freq3Low, freq3High,
        freq4Low, freq4High, freq5Low, freq5High, freq6Low;

    using GainProcessor = juce::dsp::Gain<float>;
    using HLFilter = juce::dsp::ProcessorDuplicator<juce::dsp::IIR::Filter<float>, juce::dsp::IIR::Coefficients<float>>;
    using CompressorProcessor = juce::dsp::Compressor<float>;

    juce::dsp::ProcessorChain<HLFilter, HLFilter, GainProcessor> filterBand1L;
    juce::dsp::ProcessorChain<HLFilter, HLFilter, GainProcessor> filterBand1R;

    juce::dsp::ProcessorChain<HLFilter, HLFilter, GainProcessor> filterBand2L;
    juce::dsp::ProcessorChain<HLFilter, HLFilter, GainProcessor> filterBand2R;

    juce::dsp::ProcessorChain<HLFilter, HLFilter, GainProcessor> filterBand3L;
    juce::dsp::ProcessorChain<HLFilter, HLFilter, GainProcessor> filterBand3R;

    //juce::dsp::ProcessorChain<HLFilter, HLFilter> filterBand4L;
    //juce::dsp::ProcessorChain<HLFilter, HLFilter> filterBand4R;

    juce::dsp::ProcessorChain<HLFilter, HLFilter, CompressorProcessor> filterBand5L;
    juce::dsp::ProcessorChain<HLFilter, HLFilter, CompressorProcessor> filterBand5R;

    juce::dsp::ProcessorChain<HLFilter> filterBand6L;
    juce::dsp::ProcessorChain<HLFilter> filterBand6R;


    //juce::dsp::ProcessorChain<GainProcessor> filterBand1L;
    //juce::dsp::ProcessorChain<GainProcessor> filterBand1R;
    juce::TextButton btnOnOff{ "Sountrol On" };
    juce::TextButton btnSettings{ "Sound Settings" };
    juce::TextButton btnResetAll{ "Reset All" };

    bool btnOn = true;

private:
    juce::AudioDeviceSelectorComponent audioSetupComp;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

