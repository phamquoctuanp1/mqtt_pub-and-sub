#include <QCoreApplication>
#include <iostream>
#include <mqtt1.h>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    mqtt1 m;
    m.connectHost();
//    m.onGoidien("khong su dung signal");

    m.kichHoat("su dung signal");

    cout<<" hello_world"<<endl;



    return a.exec();
    //return 0;
}
