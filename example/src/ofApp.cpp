#include "ofMain.h"

#include "ofxDataPath.h"

class ofApp : public ofBaseApp
{
public:
	
	ofImage image;

	void setup()
	{
		// on development, loads from src/ folder
		ofxDataPathSetMode(OFX_DATAPATH_RELEASE);
		
		// to deploy. capture all asset path and copy to bin/data folder when app exited
		// ofxDataPathSetMode(OFX_DATAPATH_DEPLOY);
		
		// on release. loads from bin/data folder normally
		// ofxDataPathSetMode(OFX_DATAPATH_RELEASE);

		
		// make sure to use ofxToDataPath
		image.load(ofxToDataPath("imgs/lena.jpg"));
	}

	void update()
	{
		ofSetWindowTitle(ofToString(ofGetFrameRate()));
	}

	void draw()
	{
		image.draw(0, 0);
	}

	void keyPressed(int key)
	{
	}

	void keyReleased(int key)
	{
	}

	void mouseMoved(int x, int y)
	{
	}

	void mouseDragged(int x, int y, int button)
	{
	}

	void mousePressed(int x, int y, int button)
	{
	}

	void mouseReleased(int x, int y, int button)
	{
	}

	void windowResized(int w, int h)
	{
	}
};


int main(int argc, const char** argv)
{
	ofSetupOpenGL(1280, 720, OF_WINDOW);
	ofRunApp(new ofApp);
	return 0;
}