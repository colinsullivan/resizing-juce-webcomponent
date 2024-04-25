#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : juce::Component(), juce::Timer()
{
    DBG("MainComponent::MainComponent");
    setWantsKeyboardFocus(true);
    setSize (600, 400);

	addAndMakeVisible(webBrowser);
	webBrowser.goToURL("http://localhost:3000");
    webBrowser.setWantsKeyboardFocus(true);
    
    startTimer(200);
}

MainComponent::~MainComponent()
{
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

	DBG("resized");
    
	int height = getHeight();
	int width = getWidth();

	webBrowser.setSize(width, height);
    repaint();
}

void MainComponent::focusGained (juce::Component::FocusChangeType cause) {
    DBG("focusgained");
    webBrowser.grabKeyboardFocus();
}

void MainComponent::visibilityChanged() {
    DBG("visibilityChanged");
    
}

void MainComponent::timerCallback() {
    DBG("maincmp delayed setup");
    DBG((hasKeyboardFocus(true) ? "maincmp has keyboard focus" : "maincmp does not have keyboard focus"));
//    DBG((getParentComponent()->isShowing() ? "parent is showing" : "parent is not showing"));
    DBG((isShowing() ? "maincmp is visible" : "maincmp is not visible"));
    if (!hasKeyboardFocus(true) && isShowing())
    {
        DBG("maincmp grabbing keyboard focus");
        grabKeyboardFocus();
    }
    stopTimer();
}
