/**
 * Author: Brendan Bain 251086487
 * Description: header for command class 
 * (class to run linux commands from inside the code)
 * Date: October 2nd, 2021
 **/

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <boost/process.hpp>

class command{
    
    public:
        command(std::string action);
        void execute();
        void setCommandText(std::string replace);
        int getExitCode();
        std::string getCommandText();
        std::string getResultText();
        ~command();

    private:
        std::string commandText, resultText;
        int exitCode;


};


#endif

