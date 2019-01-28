#include <QCoreApplication>
#include <QString>

#include "htmlparser.h"
#include "htmltag.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString html = QString::fromUtf8(R"~(
                   <!DOCTYPE HTML>
                   <html>
                   <head>
                   <meta name="qrichtext" content="1" />
                   <style type="text/css">
                    p, li { white-space: pre-wrap; }
                    b { color: "red" }
                   </style>
                   </head>
                   <body style=" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;">
                   <p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;">dfg</p>
                    <img src="image.png" />
                    <p id="p1">
                    <b>Sample</b> paragraph متن فارسی
            <img src="image.png" />
                   </p>
                   </body>
                   </html>)~");

    HtmlParser h;
    h.setHtml(html);
    h.parse();

    HtmlTag *p = h.getElementById("p1");
    qDebug() << "-----------";
    qDebug() << p->outterHtml();
    qDebug() << p->innerText();


    return a.exec();
}
