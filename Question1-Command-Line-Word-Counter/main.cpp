#include <QCoreApplication>
#include <QDebug>
#include "processfile.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    bool flagA = false,flagB = false,
        flagC = false, flagD = false;

    if(argc > 1)
    {

    for(int i = 1; i < argc;i++){

         QString argString = argv[i];

        if(argString.contains("-")){

            if(argString.contains("a"))
              flagA = true;
            if(argString.contains("b"))
                flagB = true;
            if(argString.contains("c"))
                flagC = true;
            if(argString.contains("d"))
                flagD = true;
            }
        else if(argString.contains("count"))
            qDebug() << " ";
            else{
                if(!flagA && !flagB && !flagC && !flagD)
                {
                    flagA = true;
                    flagB = true;
                    flagC = true;
                    flagD = true;

                }
                ProcessFile processFile(argString,flagA,flagB,flagC,flagD);
            }


        }

    }
    else
        qDebug() << "No arguments";


    return a.exec();
}
