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
        size.setWidth(screen->size().width());   //��ȡ��Ļ���
        size.setHeight(screen->size().height()); //��ȡ��Ļ�߶�
    }

    QPixmap pixmap(":/image/sea.jpg");
    QPixmap scaledPixmap = pixmap.scaled(size);    //��ͼƬ���ֱ��ʵ�����Ӧ��Ļ��С
    QSplashScreen *splash = new QSplashScreen(scaledPixmap);


    QFont font;
    QFontInfo fInfo(font);
    font.setPointSize(20);
    splash->setFont(font);
    splash->show();
    splash->showMessage(QStringLiteral("���ڼ�����Դ�ļ������Ժ󡭡�"), Qt::AlignHCenter|Qt::AlignBottom, Qt::white);
    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do
    {
         now=QDateTime::currentDateTime();
    } while (n.secsTo(now)<=5);//5Ϊ��Ҫ��ʱ������ �˴�Ϊ����ʾ����5�����ʱ

    MainWindow w;
    w.show();

    //splash->hide();
    splash->finish(&w);

    return a.exec();
}
