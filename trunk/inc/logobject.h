#ifndef LOGOBJECT_H
#define LOGOBJECT_H

#include <QObject>
#include <QString>
#include <QApplication>

class LogObject : public QObject
{
    Q_OBJECT

signals:
    void SendLogMessage  (const QString& message); // Сигнал лог-сообщения
    void SendInfoMessage (const QString& message); // Сигнал информационного сообщения
    void SendErrorMessage(const QString& message); // Сигнал сообщения об ошибке

public:
    LogObject(QObject* parent = 0) : QObject(parent)
    {
    }

protected:
    void ProcessEvents() { qApp->processEvents(); }

    void DoLog  (const QString& text, bool process_events = true)
    {
        emit SendLogMessage(text);
        if (process_events)
            ProcessEvents();
    }

    void DoInfo (const QString& text, bool process_events = true)
    {
        emit SendInfoMessage(text);
        if (process_events)
            ProcessEvents();
    }

    void DoError(const QString& text, bool process_events = true)
    {
        emit SendErrorMessage(text);
        if (process_events)
            ProcessEvents();
    }
};

#endif // LOGOBJECT_H
