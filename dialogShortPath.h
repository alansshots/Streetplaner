#ifndef DIALOGSHORTPATH_H
#define DIALOGSHORTPATH_H

#include <QDialog>

namespace Ui {
class DialogShortPath;
}

class DialogShortPath : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShortPath(QWidget *parent = nullptr);
    ~DialogShortPath();

private:
    Ui::DialogShortPath *ui;
};

#endif // DIALOGSHORTPATH_H
