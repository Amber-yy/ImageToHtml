#include "imagetohtml.h"

#include <QPixmap>
#include <QPainter>
#include <QFile>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>

#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>

#include <QDebug>

struct imageData
{
	QLabel *titleLa;
	QLabel *fillLa;
	QLabel *targetLa;
	QLabel *picLa;
	QLabel *fontSizeLa;
	QLabel *widthLa;

	QLineEdit *titleEdit;
	QLineEdit *fillEdit;
	QLineEdit *fileEdit;
	QLineEdit *picEdit;

	QSpinBox *fontSizeBox;
	QSpinBox *widthBox;

	QPushButton *fileBt;
	QPushButton *picBt;
	QPushButton *startBt;
	QPushButton *closeBt;

	QPoint lastPoint;

	bool isHovered;
	bool isPressed;
};


QString toHex(int r,  int g,  int b)
{
	auto fun = [](int a)->QString
	{
		char s[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
		QString t;
		t += s[a / 16];
		a %= 16;
		t += s[a];
		return t;
	};

	return "\"#" +fun(r) +fun(g)+ fun(b) + "\"";
}

ImageToHtml::ImageToHtml(QWidget *parent): QWidget(parent)
{
	try
	{
		data = std::make_unique<imageData>();
		createSubCom();
		setGeometry();
		connectSignal();
		setMaximumSize(360, 175);
		setMinimumSize(360, 175);
		setAutoFillBackground(false);
		setWindowFlags(Qt::FramelessWindowHint);
		setAttribute(Qt::WA_TranslucentBackground, true);
		setWindowTitle(u8"图像转网页");
	}
	catch (std::bad_alloc &)
	{
		abort();
	}
}

ImageToHtml::~ImageToHtml()
{

}

void ImageToHtml::createSubCom()
{
	data->titleLa = new QLabel(u8"网页标题",this);
	data->fillLa = new QLabel(u8"填充字", this);
	data->targetLa = new QLabel(u8"生成文件", this);
	data->picLa = new QLabel(u8"图片路径", this);
	data->fontSizeLa = new QLabel(u8"字体大小(px)", this);
	data->widthLa = new QLabel(u8"目标网页宽度", this);

	data->titleEdit = new QLineEdit(this);
	data->fillEdit = new QLineEdit(this);
	data->fileEdit = new QLineEdit(this);
	data->picEdit = new QLineEdit(this);

	data->fontSizeBox = new QSpinBox(this);
	data->widthBox = new QSpinBox(this);

	data->fileBt = new QPushButton(u8"选择路径",this);
	data->picBt = new QPushButton(u8"选择图片", this);
	data->startBt = new QPushButton(u8"开始生成", this);
	data->closeBt = new QPushButton(this);

	data->fontSizeBox->setRange(10, 30);
	data->fontSizeBox->setValue(10);

	data->widthBox->setRange(100, 500);
	data->widthBox->setValue(100);

	data->fileEdit->setEnabled(false);
	data->picEdit->setEnabled(false);

	data->isPressed = false;
	data->isHovered = false;

	data->closeBt->installEventFilter(this);
}

void ImageToHtml::connectSignal()
{
	connect(data->fileBt, &QPushButton::clicked, [this]()
	{
		QString s = QFileDialog::getSaveFileName(this, u8"选择生成文件", u8"未命名.html", "*.html");
		if (!s.isEmpty())
		{
			data->fileEdit->setText(s);
		}
	}
	);

	connect(data->picBt, &QPushButton::clicked, [this]()
	{
		QString s = QFileDialog::getOpenFileName(this, u8"选择图片路径", QDir::currentPath(), "*.jpg *.png *.bmp");
		if (!s.isEmpty())
		{
			data->picEdit->setText(s);
		}
	}
	);

	connect(data->closeBt, &QPushButton::clicked, this, &QWidget::close);
	connect(data->startBt, &QPushButton::clicked, this, &ImageToHtml::toHtml);
}

void ImageToHtml::setGeometry()
{

	data->titleLa->setGeometry(10, 20, 50, 25);
	data->fillLa->setGeometry(270, 20, 40, 25);
	data->targetLa->setGeometry(10, 60, 55, 25);
	data->picLa->setGeometry(10, 100, 55, 25);
	data->fontSizeLa->setGeometry(10, 140, 70, 25);
	data->widthLa->setGeometry(130, 140, 80, 25);

	data->titleEdit->setGeometry(70, 20, 160, 25);
	data->fillEdit->setGeometry(310, 20, 30, 25);
	data->fileEdit->setGeometry(70, 60, 160, 25);
	data->picEdit->setGeometry(70, 100, 160, 25);

	data->fontSizeBox->setGeometry(90, 140, 35, 25);
	data->widthBox->setGeometry(210, 140, 40, 25);

	data->fileBt->setGeometry(270, 60, 75, 25);
	data->picBt->setGeometry(270, 100, 75, 25);
	data->startBt->setGeometry(270, 140, 75, 25);

	data->closeBt->setGeometry(345, 5, 10, 10);
}

void ImageToHtml::toHtml()
{

	{
		QFile file(data->picEdit->text());
		if (!file.exists())
		{
			QMessageBox::warning(this, u8"错误", u8"图片不存在");
			return;
		}
	}

	if (data->fileEdit->text().isEmpty())
	{
		QMessageBox::warning(this, u8"错误", u8"请选择生成路径");
		return;
	}

	QChar fill;

	if (data->fillEdit->text().isEmpty())
	{
		fill = QString(u8"萌")[0];
	}
	else
	{
		fill = data->fillEdit->text()[0];
	}

	int width = data->widthBox->value();

	QImage origin(data->picEdit->text());
	QImage temp = origin.scaledToWidth(width);
	int rate = origin.width() / width;
	origin = origin.copy(0, 0, width * rate, temp.height()*rate);

	QFile file(data->fileEdit->text());
	file.open(QIODevice::WriteOnly);

	QString head = "<html>\n<head>\n<meta charset = \"utf-8\">\n"+QString("<title>")+data->titleEdit->text()+"</title>\n<style type = \"text/css\">\nbody\n{\nmargin: 0px; padding: 0px; \nline-height:100%; \nletter-spacing:0px; \ntext-align: center;\n\
"+QString("min-width: ")+QString::number(data->widthBox->value()*data->fontSizeBox->value())+QString("px;\nwidth: auto !important;\nfont-size: ")+QString::number(data->fontSizeBox->value())+"px;\nbackground-color: #000000;\nfont-family: monospace;\n}\n</style>\n</head>\n<body>\n<div>\n";

	file.write(head.toStdString().c_str());

	QString line;

	for (int j = 0; j < temp.height(); ++j)
	{
		line = "\n\n\t";

		for (int i = 0; i < temp.width(); ++i)
		{
			QColor tempColor;

			int rsum = 0, gsum = 0, bsum = 0;

			for (int x = 0; x < rate; ++x)
			{
				for (int y = 0; y < rate; ++y)
				{
					tempColor = origin.pixelColor(rate*i + x, rate*j + y);
					rsum += tempColor.red();
					gsum += tempColor.green();
					bsum += tempColor.blue();
				}
			}

			rsum /= rate*rate;
			gsum /= rate*rate;
			bsum /= rate*rate;

			line += "<font color=";
			line += toHex(rsum, gsum, bsum);
			line += ">"+QString(fill)+"</font>";
		}
		line += "</br>";
		file.write(line.toStdString().c_str());
	}

	QString tail = "\n</div>\n</body>\n</html>";
	file.write(tail.toStdString().c_str());

	file.flush();

	QMessageBox::information(this, u8"完成", u8"html文件保存成功");
}

bool ImageToHtml::eventFilter(QObject * obj, QEvent * e)
{
	if (obj != data->closeBt)
	{
		return false;
	}

	if (e->type() == QEvent::Paint)
	{
		if (data->isHovered)
		{
			QPainter painter(data->closeBt);
			painter.setPen(QPen(QColor(0xFFCC00), 2));
			painter.drawLine(1, 1, 9, 9);
			painter.drawLine(1, 9, 9, 1);
		}
		else
		{
			QPainter painter(data->closeBt);
			painter.setPen(QPen(Qt::white, 2));
			painter.drawLine(1, 1, 9, 9);
			painter.drawLine(1, 9, 9, 1);

		}
		return true;
	}

	if (e->type() == QEvent::HoverEnter)
	{
		data->isHovered = true;
		update();
		return true;
	}

	if (e->type() == QEvent::HoverLeave)
	{
		data->isHovered = false;
		update();
		return true;
	}

	return false;
}

void ImageToHtml::mousePressEvent(QMouseEvent * e)
{
	data->isPressed = true;
	data->lastPoint = e->globalPos();
}

void ImageToHtml::mouseReleaseEvent(QMouseEvent * e)
{
	data->isPressed = false;
}

void ImageToHtml::mouseMoveEvent(QMouseEvent * e)
{
	if (!data->isPressed)
	{
		return;
	}

	QPoint p = e->globalPos();

	int dx = p.x() - data->lastPoint.x();
	int dy = p.y() - data->lastPoint.y();

	move(x() + dx, y() + dy);

	data->lastPoint = p;
}

void ImageToHtml::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(102,204,250, 200));
}
