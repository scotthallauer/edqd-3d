#include "simExtEDQDRobot.h"
#include "CylinderEDQDRobot.h"
#include "scriptFunctionData.h"
#include <iostream>
#include "simLib.h"

#ifdef _WIN32
    #ifdef QT_COMPIL
        #include <direct.h>
    #else
        #include <shlwapi.h>
        #pragma comment(lib, "Shlwapi.lib")
    #endif
#endif /* _WIN32 */
#if defined (__linux) || defined (__APPLE__)
    #include <unistd.h>
    #define WIN_AFX_MANAGE_STATE
#endif /* __linux || __APPLE__ */

#define CONCAT(x,y,z) x y z
#define strConCat(x,y,z)    CONCAT(x,y,z)

#define PLUGIN_NAME "EDQDRobot"

static LIBRARY simLib;

static std::vector<CylinderEDQDRobot*> allRobots;
static int nextEDQDRobotHandle=0;
static int logConsoleHandle=0;

int getEDQDRobotIndexFromHandle(int EDQDRobotHandle)
{
    for (unsigned int i=0;i<allRobots.size();i++)
    {
        if (allRobots[i]->getHandle()==EDQDRobotHandle)
            return(i);
    }
    return(-1);
}

// --------------------------------------------------------------------------------------
// simExtEDQD_create
// --------------------------------------------------------------------------------------
#define LUA_CREATE_COMMAND "simEDQD.create"

const int inArgs_CREATE[]={
    4,
    sim_script_arg_int32,0,
    sim_script_arg_int32|sim_script_arg_table,2,
    sim_script_arg_int32|sim_script_arg_table,12,
    sim_script_arg_float|sim_script_arg_table,2,
};

void LUA_CREATE_CALLBACK(SScriptCallBack* cb)
{
    CScriptFunctionData D;
    int handle=-1;
    if (D.readDataFromStack(cb->stackID,inArgs_CREATE,inArgs_CREATE[0],LUA_CREATE_COMMAND))
    {
        std::vector<CScriptFunctionDataItem>* inData=D.getInDataPtr();
        handle=nextEDQDRobotHandle++;
        int robotHandle = inData->at(0).int32Data[0];
        std::vector<int> motorHandles;
        motorHandles.push_back(inData->at(1).int32Data[0]);
        motorHandles.push_back(inData->at(1).int32Data[1]);
        std::vector<int> sensorHandles;
        for (unsigned int i=0;i<12;i++)
        {
            sensorHandles.push_back(inData->at(2).int32Data[i]);
        }
        std::vector<float> backRelativeVelocities;
        backRelativeVelocities.push_back(inData->at(3).floatData[0]);
        backRelativeVelocities.push_back(inData->at(3).floatData[1]);
        CylinderEDQDRobot *robot = new CylinderEDQDRobot(handle, robotHandle, motorHandles, sensorHandles, backRelativeVelocities);
        allRobots.push_back(robot);
        simAuxiliaryConsolePrint(logConsoleHandle,"simExtEDQDRobot: CylinderEDQDRobot created.\n");
    }
    D.pushOutData(CScriptFunctionDataItem(handle));
    D.writeDataToStack(cb->stackID);
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
// simExtEDQD_destroy
// --------------------------------------------------------------------------------------
#define LUA_DESTROY_COMMAND "simEDQD.destroy"

const int inArgs_DESTROY[]={
    1,
    sim_script_arg_int32,0,
};

void LUA_DESTROY_CALLBACK(SScriptCallBack* cb)
{
    CScriptFunctionData D;
    bool success=false;
    if (D.readDataFromStack(cb->stackID,inArgs_DESTROY,inArgs_DESTROY[0],LUA_DESTROY_COMMAND))
    {
        std::vector<CScriptFunctionDataItem>* inData=D.getInDataPtr();
        int handle=inData->at(0).int32Data[0];
        int index=getEDQDRobotIndexFromHandle(handle);
        if (index>=0)
        {
            allRobots.erase(allRobots.begin()+index);
            simAuxiliaryConsolePrint(logConsoleHandle,"simExtEDQDRobot: CylinderEDQDRobot destroyed.\n");
            success=true;
        }
        else
            simSetLastError(LUA_DESTROY_COMMAND,"Invalid CylinderEDQDRobot handle.");
    }
    D.pushOutData(CScriptFunctionDataItem(success));
    D.writeDataToStack(cb->stackID);
}
// --------------------------------------------------------------------------------------


// --------------------------------------------------------------------------------------
// simExtEDQD_start
// --------------------------------------------------------------------------------------
#define LUA_START_COMMAND "simEDQD.start"

const int inArgs_START[]={
    1,
    sim_script_arg_int32,0,
};

void LUA_START_CALLBACK(SScriptCallBack* cb)
{
    CScriptFunctionData D;
    bool success=false;
    if (D.readDataFromStack(cb->stackID,inArgs_START,inArgs_START[0],LUA_START_COMMAND))
    {
        std::vector<CScriptFunctionDataItem>* inData=D.getInDataPtr();
        int handle=inData->at(0).int32Data[0];
        int index=getEDQDRobotIndexFromHandle(handle);
        if (index!=-1)
        {
            allRobots[index]->start();
            simAuxiliaryConsolePrint(logConsoleHandle,"simExtEDQDRobot: CylinderEDQDRobot started.\n");
            success=true;
        }
        else
            simSetLastError(LUA_START_COMMAND,"Invalid CylinderEDQDRobot handle.");
    }
    D.pushOutData(CScriptFunctionDataItem(success));
    D.writeDataToStack(cb->stackID);
}
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
// simExtEDQD_stop
// --------------------------------------------------------------------------------------
#define LUA_STOP_COMMAND "simEDQD.stop"

const int inArgs_STOP[]={
    1,
    sim_script_arg_int32,0,
};

void LUA_STOP_CALLBACK(SScriptCallBack* cb)
{
    CScriptFunctionData D;
    bool success=false;
    if (D.readDataFromStack(cb->stackID,inArgs_STOP,inArgs_STOP[0],LUA_STOP_COMMAND))
    {
        std::vector<CScriptFunctionDataItem>* inData=D.getInDataPtr();
        int handle=inData->at(0).int32Data[0];
        int index=getEDQDRobotIndexFromHandle(handle);
        if (index!=-1)
        {
            allRobots[index]->stop();
            allRobots[index]->setTargetVelocityAllMotors(0.0f);
            simAuxiliaryConsolePrint(logConsoleHandle,"simExtEDQDRobot: CylinderEDQDRobot stopped.\n");
            success=true;
        }
        else
            simSetLastError(LUA_STOP_COMMAND,"Invalid CylinderEDQDRobot handle.");
    }
    D.pushOutData(CScriptFunctionDataItem(success));
    D.writeDataToStack(cb->stackID);
}
// --------------------------------------------------------------------------------------


SIM_DLLEXPORT unsigned char simStart(void* reservedPointer,int reservedInt)
{ // This is called just once, at the start of CoppeliaSim.
    // Dynamically load and bind CoppeliaSim functions:
    char curDirAndFile[1024];
#ifdef _WIN32
    #ifdef QT_COMPIL
        _getcwd(curDirAndFile, sizeof(curDirAndFile));
    #else
        GetModuleFileName(NULL,curDirAndFile,1023);
        PathRemoveFileSpec(curDirAndFile);
    #endif
#elif defined (__linux) || defined (__APPLE__)
    getcwd(curDirAndFile, sizeof(curDirAndFile));
#endif

    std::string currentDirAndPath(curDirAndFile);
    std::string temp(currentDirAndPath);

#ifdef _WIN32
    temp+="\\coppeliaSim.dll";
#elif defined (__linux)
    temp+="/libcoppeliaSim.so";
#elif defined (__APPLE__)
    temp+="/libcoppeliaSim.dylib";
#endif /* __linux || __APPLE__ */

    simLib=loadSimLibrary(temp.c_str());
    if (simLib==NULL)
    {
        printf("simExtEDQDRobot: error: could not find or correctly load coppeliaSim.dll. Cannot start the plugin.\n"); // cannot use simAddLog here.
        return(0); // Means error, CoppeliaSim will unload this plugin
    }
    if (getSimProcAddresses(simLib)==0)
    {
        printf("simExtEDQDRobot: error: could not find all required functions in coppeliaSim.dll. Cannot start the plugin.\n"); // cannot use simAddLog here.
        unloadSimLibrary(simLib);
        return(0); // Means error, CoppeliaSim will unload this plugin
    }

    simRegisterScriptVariable("simEDQD","require('simExtEDQDRobot')",0);

    // Register the new functions:
    simRegisterScriptCallbackFunction(strConCat(LUA_CREATE_COMMAND,"@",PLUGIN_NAME),strConCat("number EDQDRobotHandle=",LUA_CREATE_COMMAND,"(table_2 motorJointHandles,number sensorHandle,table_2 backRelativeVelocities)"),LUA_CREATE_CALLBACK);
    simRegisterScriptCallbackFunction(strConCat(LUA_DESTROY_COMMAND,"@",PLUGIN_NAME),strConCat("boolean result=",LUA_DESTROY_COMMAND,"(number EDQDRobotHandle)"),LUA_DESTROY_CALLBACK);
    simRegisterScriptCallbackFunction(strConCat(LUA_START_COMMAND,"@",PLUGIN_NAME),strConCat("boolean result=",LUA_START_COMMAND,"(number EDQDRobotHandle)"),LUA_START_CALLBACK);
    simRegisterScriptCallbackFunction(strConCat(LUA_STOP_COMMAND,"@",PLUGIN_NAME),strConCat("boolean result=",LUA_STOP_COMMAND,"(number EDQDRobotHandle)"),LUA_STOP_CALLBACK);

    // Open console for logging events in the plugin (intended for development)
    logConsoleHandle=simAuxiliaryConsoleOpen("EDQD Plugin Log",20,23,nullptr,nullptr,nullptr,nullptr);

    return(1); // initialization went fine, we return the version number of this plugin (can be queried with simGetModuleName)
    // version 1 was for CoppeliaSim versions after CoppeliaSim 4.1.0
}

SIM_DLLEXPORT void simEnd()
{ // This is called just once, at the end of CoppeliaSim
    unloadSimLibrary(simLib); // release the library
}

SIM_DLLEXPORT void* simMessage(int message,int* auxiliaryData,void* customData,int* replyData)
{ // This is called quite often. Just watch out for messages/events you want to handle
    // This function should not generate any error messages:
    int errorModeSaved;
    simGetIntegerParameter(sim_intparam_error_report_mode,&errorModeSaved);
    simSetIntegerParameter(sim_intparam_error_report_mode,sim_api_errormessage_ignore);

    void* retVal=NULL;

    if (message==sim_message_eventcallback_modulehandle)
    {
        if ( (customData==NULL)||(std::string("EDQDRobot").compare((char*)customData)==0) ) // is the command also meant for EDQDRobot?
        {
            float dt=simGetSimulationTimeStep();
            for (unsigned int i=0;i<allRobots.size();i++)
            {
                allRobots[i]->stepController(dt);
                float x, y, z;
                allRobots[i]->getPosition(&x, &y, &z);
                char buffer[50];
                sprintf(buffer, "simExtEDQDRobot: x=%4.2f, y=%4.2f, z=%4.2f\n", x, y, z);
                simAuxiliaryConsolePrint(logConsoleHandle, buffer);
            }
        }
    }

    if (message==sim_message_eventcallback_simulationended)
    { // simulation ended. Destroy all EDQDRobot instances:
        allRobots.clear();
    }

    simSetIntegerParameter(sim_intparam_error_report_mode,errorModeSaved); // restore previous settings
    return(retVal);
}