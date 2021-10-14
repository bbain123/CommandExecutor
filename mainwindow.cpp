/**
 * Author: Brendan Bain 251086487
 * Description: implementation for mainwindow
 * (Uses Qt to build a GUI for running linux commands)
 * Date: October 2nd, 2021
 **/

#include "mainwindow.h"
#include "command.h"

/**Function: MainWindow constructor
* Description: initializes all QGroupBoxes and sets them in a QWidget
* Parameters: na
* Return: na
**/
MainWindow::MainWindow(){   //constructor for MainWindow
  createMenu();       //create the widgets I need
  createCommandBox();  
  createOutputBox();
  createStatusBox();
  createHistoryBox();

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->setMenuBar(windowBar); //add the file bar to the window
  mainLayout->addWidget(commandBox);
  mainLayout->addWidget(outputBox);
  mainLayout->addWidget(statusBox);
  mainLayout->addWidget(historyBox);

  setLayout(mainLayout);
  setWindowTitle(tr("3307 Assignment 1"));
}

/**Function: createMenu
* Description: creates the menu bar with file and exit option
* Parameters: na
* Return: na
**/
void MainWindow::createMenu(){
    windowBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);      //create file tab 
    exitAction = fileMenu->addAction(tr("E&xit")); //add exit option under file tab
    windowBar->addMenu(fileMenu);               //add file tab

    connect(exitAction, &QAction::triggered, this, &QDialog::accept); //connect exit option to close program

}

/**Function: createCommandBox
* Description: creates the QGroupBox containing the input command line
* Parameters: na
* Return: na
**/
void MainWindow::createCommandBox(){
  commandBox = new QGroupBox();
  QHBoxLayout *layout = new QHBoxLayout;
  
  commandLabel = new QLabel(tr("Command:"), this); //set label as Command
  command = new QLineEdit();                        //QLineEdit
  connect(command, &QLineEdit::returnPressed, this, &MainWindow::handleEdit);
  
  layout->addWidget(commandLabel);
  layout->addWidget(command);
  commandBox->setLayout(layout);
}

/**Function: handleEdit
* Description: catches the signal when a command is entered. stores the command and updates the history list
* Parameters: na
* Return: na
**/
void MainWindow::handleEdit(){
  //make a new command pointer with the text from the QLineEdit converted to std string
  typename::command *newCommand = new typename::command((command->text()).toStdString());
  
  newCommand->execute(); //set the values of the command output
  list.push_back(newCommand); //store the command 

  std::string temp = std::to_string(historyList->count() + 1) + ". " + 
  (command->text()).toStdString() + " (" +std::to_string(newCommand->getExitCode()) + ")";

  historyList->addItem(tr(temp.c_str()));  //store the command in the QList
 
  output->setPlainText(tr((newCommand->getResultText()).c_str())); //set the output
  status->setText(tr((std::to_string(newCommand->getExitCode())).c_str())); //set the exit code
}
  
/**Function: createOutputBox
* Description: creates the output QGroupBox that contains the output box
* Parameters: na
* Return: na
**/
void MainWindow::createOutputBox(){     
  outputBox = new QGroupBox(tr("Output"));
  output = new QTextEdit;
  output->setReadOnly(true);     //noneditable
  output->ensureCursorVisible(); //can scroll
  output->setLineWrapColumnOrWidth(500);
  output->setLineWrapMode(QTextEdit::FixedPixelWidth); //dont wrap text, give horizontal scroll bar
  
  QHBoxLayout *layout = new QHBoxLayout;
  layout->addWidget(output);
  outputBox->setLayout(layout);  
}

/**Function: createStatusBox
* Description: creates the exit status label
* Parameters: na
* Return: na
**/
void MainWindow::createStatusBox(){
  statusBox = new QGroupBox();
  statusLabel = new QLabel(tr("Exit status: "));
  status = new QLabel(tr("0"));
  
  QHBoxLayout *layout = new QHBoxLayout;
  layout->addWidget(statusLabel);
  layout->addWidget(status);
  statusBox->setLayout(layout);

}

/**Function: createHistoryBox
* Description: creates the history QGroupBox containing the list of previous commands
* Parameters: na
* Return: na
**/
void MainWindow::createHistoryBox(){
  historyBox = new QGroupBox(tr("History"));
  historyList = new QListWidget();
  connect(historyList, &QListWidget::itemSelectionChanged, this, &MainWindow::handleClick);
  
  QHBoxLayout *layout = new QHBoxLayout;
  layout->addWidget(historyList);
  //layout->addWidget(historyList);
  historyBox->setLayout(layout);

}

/**Function: handleClick
* Description: catches the signal set off when someone selects a command from history list. 
* updates the exit status, command, and output accordingly
* Parameters: na
* Return: na
**/
void MainWindow::handleClick(){
  std::string selectedString = (((historyList->selectedItems()).first())->text()).toStdString(); //get the selected item as string
  int position = selectedString.at(0) - '0'; //get the position number
  typename::command *selectedCommand = list.at(position - 1); //get the command at that position

  command->setText(tr((selectedCommand->getCommandText()).c_str())); //update text command
  status->setText(tr((std::to_string(selectedCommand->getExitCode()).c_str())));//update status number
  output->setText(tr((selectedCommand->getResultText()).c_str()));//update output
}

/**Function: MainWindow destructor
* Description: deletes MainWindow objects
* Parameters: na
* Return: na
**/
MainWindow::~MainWindow(){
}