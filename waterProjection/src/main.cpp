#include "ofMain.h"
#include "ofApp.h"
#include "SecondApp.h"
#include "ofAppGLFWWindow.h"

#define DEF_WIDTH 600
#define DEF_HEIGHT 600

int numScreens;
GLFWmonitor** monitors;

int getNumScreens() {
    // Check screens size and location
    monitors = glfwGetMonitors(&numScreens);
    cout << "Number of screens found: " << numScreens << endl;
    return numScreens;
}

bool setWindowDimensions(ofGLFWWindowSettings& settings, int windowNum) {
    if (numScreens>1) {
        int xM; int yM;
        glfwGetMonitorPos(monitors[windowNum], &xM, &yM); // We take the second monitor
        const GLFWvidmode * desktopMode = glfwGetVideoMode(monitors[windowNum]);
        settings.width = desktopMode->width;
        settings.height = desktopMode->height;
        settings.setPosition(ofVec2f(xM, yM));
        settings.resizable = false;
        settings.decorated = false;
        return true;
    } else {
        settings.width = DEF_WIDTH; // Default settings if there is only one screen
        settings.height = DEF_HEIGHT;
        settings.setPosition(ofVec2f(DEF_WIDTH*windowNum, 0));
        settings.resizable = false;
        return false;
    }
}

int main( ){
    glfwInit();
    ofGLFWWindowSettings settings;
    
    getNumScreens();
    
    /*
    settings.width = 600;
    settings.height = 600;
    settings.setPosition(ofVec2f(0, 0));
    settings.resizable = false;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    */
    
    setWindowDimensions(settings, 0);
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    /*
    settings.width = 600;
    settings.height = 600;
    settings.setPosition(ofVec2f(600, 0));
    settings.resizable = false;
    shared_ptr<ofAppBaseWindow> secondWindow = ofCreateWindow(settings);
    */
    
    setWindowDimensions(settings, 1);
    shared_ptr<ofAppBaseWindow> secondWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    shared_ptr<SecondApp> secondApp(new SecondApp);
    
    mainApp->secondApp = secondApp;
    
    ofRunApp(secondWindow, secondApp);
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
}

