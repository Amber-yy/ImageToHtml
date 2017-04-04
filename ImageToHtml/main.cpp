#include "imagetohtml.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ImageToHtml w;
	w.show();
	return a.exec();
}
