#include "writer.h"
#include <QDebug>
#include <QFileDialog>
#include <QTextStream>

Writer::Writer()
     {

}

bool Writer::writeToFile(TransactionList *t)
{

    QString fileName = QFileDialog::getSaveFileName(0,("Save Transaction List"),".",("Text Documents(*.txt)"));

    if(fileName.isEmpty())
        return false;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "Failed to open " << fileName;
        return false;

}
    QTextStream out(&file);


    foreach (Transaction *tr, t->returnList()) {
        out << tr->toString() << "\n";
    }
    return true;
}
