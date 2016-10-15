#include "MainWidget.h"
#include <QApplication>
#include "app.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	QApplication::setApplicationName(APP_NAME);
	QApplication::setApplicationVersion(APP_VERSION);
	QApplication::setOrganizationName(COMPANY_NAME);
	QApplication::setOrganizationDomain(COMPANY_URL);

    MainWidget w;
    w.show();
    return a.exec();
}
