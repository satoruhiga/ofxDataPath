#pragma once

#include "ofUtils.h"

enum ofxDataPathMode
{
	OFX_DATAPATH_DEVELOPMENT,
	OFX_DATAPATH_DEPLOY,
	OFX_DATAPATH_RELEASE
};

void ofxDataPathSetMode(ofxDataPathMode mode);

std::string ofxToDataPath(const std::string& path);