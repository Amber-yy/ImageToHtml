#ifndef IMAGETOHTML_H
#define IMAGETOHTML_H

#include <QWidget>
#include <memory>

struct imageData;

class ImageToHtml : public QWidget
{
	Q_OBJECT
public:
	ImageToHtml(QWidget *parent = 0);
	~ImageToHtml();
protected:
	void createSubCom();
	void connectSignal();
	void setGeometry();
	void toHtml();
protected:
	virtual bool eventFilter(QObject *obj, QEvent *e) override;
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void mouseReleaseEvent(QMouseEvent *e) override;
	virtual void mouseMoveEvent(QMouseEvent *e) override;
	virtual void  paintEvent(QPaintEvent *e) override;
protected:
	std::unique_ptr<imageData> data;
};

#endif
