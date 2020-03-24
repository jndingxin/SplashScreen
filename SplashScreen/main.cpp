#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QScreen>
#include <QDebug>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSize size;
    foreach (QScreen *screen, QGuiApplication::screens())
    {
        size.setWidth(screen->size().width());   //获取屏幕宽度
        size.setHeight(screen->size().height()); //获取屏幕高度
    }

    QPixmap pixmap(":/image/sea.jpg");
    QPixmap scaledPixmap = pixmap.scaled(size);    //把图片按分辨率调整适应屏幕大小
    QSplashScreen *splash = new QSplashScreen(scaledPixmap);


    QFont font;
    QFontInfo fInfo(font);
    font.setPointSize(20);
    splash->setFont(font);
    splash->show();
    splash->showMessage(QStringLiteral("正在加载资源文件，请稍后……"), Qt::AlignHCenter|Qt::AlignBottom, Qt::white);
    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do
    {
         now=QDateTime::currentDateTime();
    } while (n.secsTo(now)<=5);//5为需要延时的秒数 此处为了演示加了5秒的延时

    MainWindow w;
    w.show();

    //splash->hide();
    splash->finish(&w);

    return a.exec();
}
