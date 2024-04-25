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
    // Your private member variables go here...
//    WebBrowserWatcher mWebBrowserWatcher;
    juce::WebBrowserComponent webBrowser;
	


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
