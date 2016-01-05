#include "ofxDataPath.h"

#include <unordered_set>

static ofxDataPathMode _mode = OFX_DATAPATH_DEVELOPMENT;

static std::string to_src_path(const std::string& path)
{
#if defined TARGET_OSX
	try{
		return std::filesystem::canonical(ofFilePath::join(ofFilePath::getCurrentExeDir(),  "../../../../src/" + path)).string();
	}catch(...){
		return ofFilePath::join(ofFilePath::getCurrentExeDir(),  "../../../../src/" + path);
	}
#else
	try{
		return std::filesystem::canonical(ofFilePath::join(ofFilePath::getCurrentExeDir(),  "../src/" + path)).string();
	}catch(...){
		return ofFilePath::join(ofFilePath::getCurrentExeDir(),  "../src/" + path);
	}
#endif
}

struct PathCorrector
{
	~PathCorrector()
	{
		for (auto& it : paths)
		{
			std::string from = to_src_path(it);
			std::string to = ofToDataPath(it);
			
			ofFilePath::createEnclosingDirectory(to, false, true);
			ofFile::copyFromTo(from, to, false, true);
			
			std::cout << "copy " << ofFilePath::getAbsolutePath(from) << " -> " << ofFilePath::getAbsolutePath(to) << std::endl;
		}
	}
	
	std::unordered_set<std::string> paths;
};

static std::shared_ptr<PathCorrector> corr;

void ofxDataPathSetMode(ofxDataPathMode mode)
{
	_mode = mode;
	
	if (_mode == OFX_DATAPATH_DEPLOY)
	{
		corr = std::make_shared<PathCorrector>();
	}
}

std::string ofxToDataPath(const std::string& path)
{
	switch (_mode) {
		case OFX_DATAPATH_DEVELOPMENT:
		{
			return to_src_path(path);
		} break;
			
		case OFX_DATAPATH_DEPLOY:
		{
			corr->paths.insert(path);
			return to_src_path(path);
		} break;
			
		case OFX_DATAPATH_RELEASE:
		{
			return ofToDataPath(path);
		} break;
		
	}
}