/**
 * Author: Brendan Bain 251086487
 * Description: implementation for command class 
 * (class to run linux commands from inside the code)
 * Date: October 2nd, 2021
 **/

#include "command.h"
using namespace boost::process;


    /**Function: command
     * Description: constructor for command. Initialize commandText as action and exitCode to 0
     * Parameters: std::string action
     * Return: na
     **/
    command::command(std::string action){
        commandText = action;
        exitCode = 0;
    }

    /**Function: execute
     * Description: executes the commandText in the command object and updates outputText and exitCode
     * Parameters: na
     * Return:na
     **/
    void command::execute(){          //execute commandText and store results in Command object
        try{
            ipstream pipe_stream;
            child c(commandText, std_out > pipe_stream);  //pass in command text to be executed
            std::string line;                           

         while (pipe_stream && std::getline(pipe_stream, line) && !line.empty()){
                resultText = resultText + line + "\n";       //set resultText as output
                exitCode = 0;                               //set exitCode to 0 for success
         }

        c.wait();
        }
        catch (process_error err){
            resultText = err.what();                        //set resultText as the error 
            exitCode = -1;                                 //set exitCode to -1
                
        }
    }

    /**Function: setCommandText
     * Description: sets the commandText to replace
     * Parameters: std::string replace
     * Return: na
     **/    
    void command::setCommandText(std::string replace){
        commandText = replace;
    }

    /**Function: getExitCode
     * Description: returns the exitCode of command object
     * Parameters: na
     * Return: int exitCode
     **/
    int command::getExitCode(){
        return exitCode;
     }

    /**Function: getCommandText
     * Description: returns the commandText of command object
     * Parameters: na
     * Return: std::string commandText
     **/
    std::string command::getCommandText(){
         return commandText;
    }

    /**Function: getResultText
     * Description: returns the resultText of command object
     * Parameters: na
     * Return: std::string resultText
     **/
    std::string command::getResultText(){
        return resultText;
    }

    /**Function: command destructor
     * Description: destroys command object
     * Parameters: na
     * Return: na
     **/
    command::~command(){
    }




