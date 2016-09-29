#include "CaptureWidget.h"
#include <QApplication>

#include "app.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setApplicationName(APP_NAME);
    QApplication::setApplicationVersion(APP_VERSION);
    QApplication::setOrganizationName(COMPANY_NAME);
    QApplication::setOrganizationName(COMPANY_URL);


    CaptureWidget w;
    w.show();

    return a.exec();
}
