/*
    Copyright © 2014 by The qTox Project

    This file is part of qTox, a Qt-based graphical interface for Tox.

    qTox is libre software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    qTox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with qTox.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CROPPINGLABEL_H
#define CROPPINGLABEL_H

#include <QLabel>

class QLineEdit;

class CroppingLabel final : public QLabel
{
    Q_OBJECT
public:
    explicit CroppingLabel(QWidget *parent = 0);

    void setEditable(bool editable);
    void setEdlideMode(Qt::TextElideMode elide);

    void setText(const QString& text);
    QString fullText(); ///< Returns the un-cropped text

signals:
    void textChanged(QString newText, QString oldText);
    void clicked();

protected:
    void setElidedText();
    void hideTextEdit(bool acceptText);
    void showTextEdit();
    virtual void resizeEvent(QResizeEvent *ev) final override;
    virtual QSize sizeHint() const final override;
    virtual QSize minimumSizeHint() const final override;
    virtual void mouseReleaseEvent(QMouseEvent *e) final override;
    virtual bool eventFilter(QObject *obj, QEvent *e) final override;

private:
    QString origText;
    QLineEdit* textEdit;
    bool blockPaintEvents;
    bool editable;
    Qt::TextElideMode elideMode;
};

#endif // CROPPINGLABEL_H
