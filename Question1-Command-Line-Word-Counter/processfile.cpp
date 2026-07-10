#include "processfile.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QRegularExpression>

ProcessFile::ProcessFile(QString fileName, bool a, bool b, bool c, bool d)
{

        QFile file(":/resources/" + fileName);

        if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){

            qDebug() << "Could not open file:" << fileName;
            return;
        }

        QTextStream in(&file);

        QString content = in.readAll();
        file.close();
        QStringList words;

        content.remove(QRegularExpression("[^\\w\\s-]"));


        words = content.split(" ",Qt::SkipEmptyParts);

        QRegularExpression reg1("\\b[A-Z][A-Za-z]{4,}\\b");
        QRegularExpression reg2("\\b\\w+-\\w+\\b");
        QRegularExpression reg3("\\b(\\w)\\w*\\1\\b");
        QRegularExpression reg4("\\b[^aeiouAEIOU]\\w*\\b");

        qDebug() << QString("***%1***").arg(fileName);

        int countWords = 0;
        int hyphenatedWords = 0;
        int startEndword = 0;
        int vowelWords = 0;

        for(int i = 0; i < words.size();i++){


            QRegularExpressionMatch match1 = reg1.match(words.at(i));
            QRegularExpressionMatch match2 = reg2.match(words.at(i));
            QRegularExpressionMatch match3 = reg3.match(words.at(i));
            QRegularExpressionMatch match4 = reg4.match(words.at(i));

            bool hasMatch1 = match1.hasMatch();
            bool hasMatch2 = match2.hasMatch();
            bool hasMatch3 = match3.hasMatch();
            bool hasMatch4 = match4.hasMatch();

            if(hasMatch1)
                countWords++;
            if(hasMatch2)
                hyphenatedWords++;
            if(hasMatch3)
                startEndword++;
            if(hasMatch4)
                vowelWords++;
        }

        if(a){
            qDebug() << "Number of words longer"
                        " than 4 letters that start "
                        "with a capital letter:" <<countWords;
        }
        if(b){
            qDebug() << "Number of hyphenated words:" << hyphenatedWords;
        }
        if(c){
            qDebug() << "Words that start "
                        "and end on the same character:" << startEndword;
        }
        if(d){
            qDebug() << "Number of words that "
                        "do not start with a vowel:" << vowelWords;
        }
    }

