#include "mainwindow.h"
#include "serializer.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QtWidgets>

MainWindow::~MainWindow() {}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    openFile();


    // CENTRAL LAYOUT AND HEADER

    QWidget* centralWidget = new QWidget(this);
    resize(550, 550);

    setCentralWidget(centralWidget);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    centralWidget->setLayout(mainLayout);

    QHBoxLayout* labelLayout = new QHBoxLayout;
    QLabel* label = new QLabel("<h1>Armies</h1>");
    label->setFixedWidth(300);
    //label->setFont(QFont("Arial", 22));
    labelLayout->addWidget(label, Qt::AlignCenter);
    mainLayout->addLayout(labelLayout);


    // MENU

    QMenuBar* menu = new QMenuBar(centralWidget);

    QMenu* fileMenu = new QMenu("File");
    QAction* newFileAction = new QAction("New File", fileMenu);
    QAction* openFileAction = new QAction("Open File", fileMenu);
    QAction* saveFileAction = new QAction("Save File", fileMenu);
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(saveFileAction);

    QMenu* editMenu = new QMenu("Edit");
    QAction* cleanEditAction = new QAction("Clean", editMenu);
    QAction* restoreEditAction = new QAction("Restore Army", editMenu);
    editMenu->addAction(cleanEditAction);
    editMenu->addAction(restoreEditAction);

    menu->addMenu(fileMenu);
    menu->addMenu(editMenu);

    connect(openFileAction, &QAction::triggered, this, &MainWindow::openFile);
    connect(saveFileAction, &QAction::triggered, this, &MainWindow::saveFile);




    // TABLE ARMIES

    armiesTable = new QTableWidget(this);
    armiesTable->setSelectionMode( QAbstractItemView::SingleSelection );
    armiesTable->horizontalHeader()->hide();
    armiesTable->verticalHeader()->hide();
    armiesTable->setColumnCount(2);
    armiesTable->setRowCount((model.getArmies().size()+1)/2);
    for(unsigned i = 0; i < model.getArmies().size(); i++)
        armiesTable->setItem(i/2, i%2, new QTableWidgetItem(QString::fromStdString(model.getArmies()[i]->getName())));
    mainLayout->addWidget(armiesTable);



    // BUTTONS

    QHBoxLayout* buttonBar = new QHBoxLayout;
    QPushButton* addArmyBtn = new QPushButton("+");
    QPushButton* delArmyBtn = new QPushButton("-");
    buttonBar->addWidget(addArmyBtn);
    buttonBar->addWidget(delArmyBtn);
    connect(delArmyBtn, &QPushButton::clicked, [this](){
       int index = 2 * armiesTable->currentRow() + armiesTable->currentColumn();
       if (index < model.getArmies().size()) {
           delete armiesTable->selectedItems()[0];
           model.removeArmy(index);
       }
    });
    mainLayout->addLayout(buttonBar);

}

void MainWindow::openFile() {
    openedFileName = QFileDialog::getOpenFileName(this, "Apri salvataggio", "/home", "Salvataggio armate (*.xml)").toStdString().c_str();
    if(openedFileName == "")  return;
    model.open(openedFileName);
    qDebug() << "Opened file " << openedFileName;
}

void MainWindow::saveFile() {
    model.save(openedFileName);
}
