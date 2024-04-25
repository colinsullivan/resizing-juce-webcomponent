#pragma once

#include <JuceHeader.h>

class WebBrowserWatcher : public juce::ComponentMovementWatcher
{
public:
    WebBrowserWatcher(juce::Component* componentToWatch) : juce::ComponentMovementWatcher(componentToWatch) {};
    /** This callback happens when the component that is being watched is moved
            relative to its top-level peer window, or when it is resized. */
     void componentMovedOrResized (bool wasMoved, bool wasResized) override {};

        /** This callback happens when the component's top-level peer is changed. */
     void componentPeerChanged() override {};

        /** This callback happens when the component's visibility state changes, possibly due to
            one of its parents being made visible or invisible.
        */
     void componentVisibilityChanged() override {
         DBG("WebBrowserWatcher::componentVisibilityChanged");
     };
};

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component, public juce::Timer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void resized() override;
    
    void focusGained (juce::Component::FocusChangeType cause) override;
    void visibilityChanged() override;
    
    void timerCallback() override;

private:
    //==============================================================================
    // Your private member variables go here...
//    WebBrowserWatcher mWebBrowserWatcher;
    juce::WebBrowserComponent webBrowser;
	


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
