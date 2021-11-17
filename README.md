# CommandExecutor
a GUI that accepts unix commands. Returns the output and exit code, and stores the history and output of the commands in a list. Uses boost and Qt libraries
 

## Dependencies

1. **Install Boost**  
  Official Boost Documentation: https://www.boost.org/doc/  
  This application uses boost libraries. You can download Boost yourself at 
  https://www.boost.org/users/download/

or run

    sudo apt-get install libboost-all-dev
  
  
  
2. **Install Qt5**  
Official Qt Documentation: https://doc.qt.io/  
Qt is a cross-platform application development framework for desktop, 
embedded and mobile. Supported Platforms include Linux, OS X, Windows, VxWorks, 
QNX, Android, iOS, BlackBerry, Sailfish OS and others. Download at https://www.qt.io/download  
  
or run
  
       sudo apt-get install qt5-default

  
  

## Launch the application

Use  
  
    qmake -qt5 CommandGUI.pro

and run the generated executable *CommandGUI*
