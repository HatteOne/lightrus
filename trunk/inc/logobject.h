/*******************************************************************************

    Project Lightrus
    
    Класс с сигналами распостранения информационных сообщений
    
    Copyright (C) 2009 Sergey Balyakin

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
*******************************************************************************/

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
