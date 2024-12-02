#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include "main.moc"

// Define a simple class that emits a signal

// Define uma classe simples que emite um sinal
class Button : public QObject
{
    Q_OBJECT  // Required for signal-slot mechanism. Necessário para mecanismo de slot de sinal.

public:
    void click() {
        emit clicked();  // Emit the signal when the button is clicked. Emite o sinal quando o botão é clicado.
    }

signals:
    void clicked();  // Define a signal called 'clicked'. Defina um sinal chamado 'clicado'.
};

// Define a class that reacts to the signal

// Define uma classe que reage ao sinal
class Handler : public QObject
{
    Q_OBJECT

public slots:
    void onClicked() {
        qDebug() << "Button was clicked!";
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Button button;
    Handler handler;

    // Connect the button's clicked signal to the handler's onClicked slot

    // Conecta o sinal clicado do botão ao slot onClicked do manipulador
    QObject::connect(&button, &Button::clicked, &handler, &Handler::onClicked);

    // Simulate a button click

    //Simula um clique de botão
    button.click();  // This will emit the 'clicked' signal. Isso emitirá o sinal de 'clicado'.

    return a.exec();
}
