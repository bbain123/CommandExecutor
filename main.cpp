/**
* Author: Brendan Bain 251086487
* Description: main for running program
* initializes and launches GUI
* Date: October 2nd, 2021
**/

#include "mainwindow.h"
#include <QApplication>

/**Function: main
* Description: main function that is executed 
* Parameters: int argc, char* argv[]
* Return: int exit code
**/
int main(int argc, char *argv[]) 
{
  QApplication app(argc, argv);
  MainWindow mainWindow;
  mainWindow.show();

  return app.exec();
}