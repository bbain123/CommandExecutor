/**
 * Author: Brendan Bain 251086487
 * Description: header for mainwindow
 * (Uses Qt to build a GUI for running linux commands)
 * Date: October 2nd, 2021
 **/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QListWidget>
#include "command.h"


namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QDialog
{
  Q_OBJECT

public:
  MainWindow();
  ~MainWindow();
 
private:
  void createMenu();
  void createCommandBox();  //for typing the commands in
  void handleEdit();
  void createOutputBox();
  void createStatusBox();
  void createHistoryBox(); 
  void handleClick();
  

  QMenuBar *windowBar;
  QMenu *fileMenu;
  QAction *exitAction;
  QVBoxLayout *mainLayout;
 
 //for createCommandBox
  QLabel *commandLabel;
  QLineEdit *command;
  QGroupBox *commandBox;

//for createOutputBox
  QGroupBox *outputBox;
  QTextEdit *output;

//for createStatusBox
  QLabel *statusLabel;    //to display the word status
  QLabel *status;         //to display the exit status
  QGroupBox *statusBox;

//for createHistoryBox
  QGroupBox *historyBox;
  QListWidget *historyList;
  std::vector<typename::command*> list;
  typename::command *newCommand;

};
#endif // MAINWINDOW_H