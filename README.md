This project demonstrates resizing a JUCE web component, intended to investigate Windows issues with scrolling and resizing the WebView.

This was put together quickly, there is a project within a project here.

`NewProject.jucer`: A JUCE GUI app that opens a WebView.
`VSTProject/NewProject.jucer`: A JUCE VST & Stanalone app that opens a WebView.

## Modifying the Webpage
`webapp/`: A webapp is included which uses Create React App and includes Polyfills needed for IE.  This is useful for testing more advanced webapp features or for opening the devtools.
`webapp/public/simple.html`: A basic HTML page that can be modified directly, eliminating the variable of the complex JS-side tooling.

## Running
Ensure the URL being loaded is correct:

`goToURL` should point to `http://localhost:3000` if you are using the CRA devtools or directly to the `webapp/public/simple.html` file.

https://github.com/colinsullivan/resizing-juce-webcomponent/blob/master/VSTProject/Source/PluginEditor.cpp#L22
