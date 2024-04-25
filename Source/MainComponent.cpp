#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : juce::Component()
{
    DBG("MainComponent::MainComponent");
    setWantsKeyboardFocus(true);
    setSize (600, 400);

	addAndMakeVisible(webBrowser);
	webBrowser.goToURL("http://localhost:3000");
    webBrowser.setWantsKeyboardFocus(true);
   
    // Out of the box, this seems the best way to have the main
    // component actually grab keyboard focus when the standalone app
    // starts
    juce::Timer::callAfterDelay(500, [&](){
        delayedSetup();
    });
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
    DBG("MainComponent::focusGained");
    webBrowser.grabKeyboardFocus();
}

void MainComponent::visibilityChanged() {
    DBG("visibilityChanged");    
}

void MainComponent::delayedSetup() {
    if (!hasKeyboardFocus(true) && isShowing())
    {
        grabKeyboardFocus();
    }
}
