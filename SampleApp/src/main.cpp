#include "SampleApp/ConsoleReader.h"
#include "SampleApp/SampleApplication.h"
#include "SampleApp/SampleApplicationReturnCodes.h"

#include <cstdlib>
#include <string>

<<<<<<< HEAD
#define ALEXA_CLIENT_SDK_CONFIG "/home/root/AVS/build/Integration/Alexa.json"
#define INPUTS_FOLDER           "/home/root/AVS/third-party/snowboy/resources"
#define DEBUG_LEVEL             "NONE"
=======
using namespace alexaClientSDK::sampleApp;

/**
 * Function that evaluates if the SampleApp invocation uses old-style or new-style opt-arg style invocation.
 *
 * @param argc The number of elements in the @c argv array.
 * @param argv An array of @argc elements, containing the program name and all command-line arguments.
 * @return @c true of the invocation uses optarg style argument @c false otherwise.
 */
bool usesOptStyleArgs(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-C") || !strcmp(argv[i], "-K") || !strcmp(argv[i], "-L") ||
            !strcmp(argv[i], "-S") || !strcmp(argv[i], "-G")) 
        {
            return true;
        }
    }
>>>>>>> develop

using namespace alexaClientSDK::sampleApp;

int main(int argc, char* argv[]) {
    std::vector<std::string> configFiles;
<<<<<<< HEAD
    std::string pathToKWDInputFolder = std::string(INPUTS_FOLDER);
    std::string logLevel = std::string(DEBUG_LEVEL);
=======
    std::string pathToKWDInputFolder;
    std::string logLevel;
    float sensitivity = 0.6;
    float gain = 2.0;

    if (usesOptStyleArgs(argc, argv)) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-C") == 0) {
                if (i + 1 == argc) {
                    ConsolePrinter::simplePrint("No config specified for -C option");
                    return SampleAppReturnCode::ERROR;
                }
                configFiles.push_back(std::string(argv[++i]));
                ConsolePrinter::simplePrint("configFile " + std::string(argv[i]));
            } else if (strcmp(argv[i], "-K") == 0) {
                if (i + 1 == argc) {
                    ConsolePrinter::simplePrint("No wakeword input specified for -K option");
                    return SampleAppReturnCode::ERROR;
                }
                pathToKWDInputFolder = std::string(argv[++i]);
            } else if (strcmp(argv[i], "-L") == 0) {
                if (i + 1 == argc) {
                    ConsolePrinter::simplePrint("No debugLevel specified for -L option");
                    return SampleAppReturnCode::ERROR;
                }
                logLevel = std::string(argv[++i]);
            } else if (strcmp(argv[i], "-S") == 0) {
                if (i + 1 == argc) {
                    ConsolePrinter::simplePrint("No wakeword sensitivity specified for -S option");
                    return SampleAppReturnCode::ERROR;
                }
            } else if (strcmp(argv[i], "-G") == 0) {
                if (i + 1 == argc) {
                    ConsolePrinter::simplePrint("No wakeword gain specified for -G option");
                    return SampleAppReturnCode::ERROR;
                }
            }
            else {
                ConsolePrinter::simplePrint(
                    "USAGE: " + std::string(argv[0]) + " -C <config1.json> -C <config2.json> ... -C <configN.json> " +
                    " -K <path_to_inputs_folder> -S <wakeword_sensitivity> -G <wakeword_gain> " + 
                    "-L <log_level>");
                return SampleAppReturnCode::ERROR;
            }
        }
    } else {
#if defined(KWD_KITTAI) || defined(KWD_SENSORY)
        if (argc < 5) {
            ConsolePrinter::simplePrint(
                "USAGE: " + std::string(argv[0]) +
                " <path_to_AlexaClientSDKConfig.json> <path_to_inputs_folder> <sensitivity> <gain> [log_level]");
            return SampleAppReturnCode::ERROR;
        } else {
            pathToKWDInputFolder = std::string(argv[2]);
            sensitivity = std::stof(std::string(argv[3]));
            gain = std::stof(std::string(argv[4]));
            if (6 == argc) {
                logLevel = std::string(argv[5]);
            }
            
        }
#else
        if (argc < 2) {
            ConsolePrinter::simplePrint(
                "USAGE: " + std::string(argv[0]) + " <path_to_AlexaClientSDKConfig.json> [log_level]");
            return SampleAppReturnCode::ERROR;
        }
        if (3 == argc) {
            logLevel = std::string(argv[2]);
        }
#endif
>>>>>>> develop

    configFiles.push_back(std::string(ALEXA_CLIENT_SDK_CONFIG));

    auto consoleReader = std::make_shared<ConsoleReader>();

<<<<<<< HEAD
    std::unique_ptr<SampleApplication> sampleApplication = SampleApplication::create(consoleReader, configFiles, pathToKWDInputFolder, logLevel);
    
    SampleAppReturnCode returnCode = sampleApplication->run();
    
=======
    std::unique_ptr<SampleApplication> sampleApplication;
    SampleAppReturnCode returnCode = SampleAppReturnCode::OK;

    do {
        sampleApplication = SampleApplication::create(consoleReader, configFiles, pathToKWDInputFolder, 
            sensitivity, gain, logLevel);
        if (!sampleApplication) {
            ConsolePrinter::simplePrint("Failed to create to SampleApplication!");
            return SampleAppReturnCode::ERROR;
        }
        returnCode = sampleApplication->run();
        sampleApplication.reset();
    } while (SampleAppReturnCode::RESTART == returnCode);

>>>>>>> develop
    return returnCode;
}
