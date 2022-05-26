#include <QtWidgets/QApplication>
#include <QPlainTextEdit>
#include <QWebEngineView>
#include <QHBoxLayout>

QString example = "<h1>This is heading 1 </h1>\n"
                    "<h2>This is heading 2 </h2>\n"
                    "<h3>This is heading 3 </h3>\n"
                    "<h4>This is heading 4 </h4>\n"
                    "<h5>This is heading 5 </h5>\n"
                    "<h6>This is heading 6 </h6>\n";


class EditorHTML : public QWidget
{
public:
    explicit EditorHTML(QWidget* parent = Q_NULLPTR)
        : QWidget(parent)
    {
        setLayout(new QHBoxLayout);
        setMinimumSize(1000, 600);
        QSizePolicy sizeExpanding(QSizePolicy::Expanding, QSizePolicy::Expanding);

        auto* plainText = new QPlainTextEdit(example);
        plainText->setSizePolicy(sizeExpanding);
        layout()->addWidget(plainText);

        auto* webView = new QWebEngineView;
        webView->setHtml(plainText->toPlainText());
        webView->setSizePolicy(sizeExpanding);
        layout()->addWidget(webView);

        connect(plainText, &QPlainTextEdit::textChanged, [plainText, webView]() 
            {
                webView->setHtml(plainText->toPlainText());
            });
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    EditorHTML edHTML;

    edHTML.show();
    return a.exec();
}

#include <main.moc>
