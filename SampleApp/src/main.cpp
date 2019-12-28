#include "SampleApp/ConsoleReader.h"
#include "SampleApp/SampleApplication.h"
#include "SampleApp/SampleApplicationReturnCodes.h"

#include <cstdlib>
#include <string>

#define ALEXA_CLIENT_SDK_CONFIG "/home/root/AVS/build/Integration/Alexa.json"
#define INPUTS_FOLDER           "/home/root/AVS/third-party/snowboy/resources"
#define DEBUG_LEVEL             "NONE"

using namespace alexaClientSDK::sampleApp;

int main(int argc, char* argv[]) {
    std::vector<std::string> configFiles;
    std::string pathToKWDInputFolder = std::string(INPUTS_FOLDER);
    std::string logLevel = std::string(DEBUG_LEVEL);

    configFiles.push_back(std::string(ALEXA_CLIENT_SDK_CONFIG));

    auto consoleReader = std::make_shared<ConsoleReader>();

    std::unique_ptr<SampleApplication> sampleApplication = SampleApplication::create(consoleReader, configFiles, pathToKWDInputFolder, logLevel);
    
    SampleAppReturnCode returnCode = sampleApplication->run();
    
    return returnCode;
}
