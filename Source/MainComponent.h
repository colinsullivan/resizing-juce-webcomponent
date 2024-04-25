#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void resized() override;
    
    void focusGained (juce::Component::FocusChangeType cause) override;
    void visibilityChanged() override;

private:
    void delayedSetup();
    //==============================================================================
    // Juce 8
    juce::WebBrowserComponent webBrowser { juce::WebBrowserComponent::Options{}
                                         .withBackend (juce::WebBrowserComponent::Options::Backend::webview2)
                                         .withWinWebView2Options (juce::WebBrowserComponent::Options::WinWebView2{}
                                                                      .withUserDataFolder (juce::File::getSpecialLocation (juce::File::SpecialLocationType::tempDirectory)))
                                         .withNativeIntegrationEnabled() };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
