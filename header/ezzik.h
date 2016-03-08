#ifndef EZZIK_H
#define EZZIK_H

#include <QWidget>

namespace Ui {
class EZzik;
}

class EZzik : public QWidget
{
    Q_OBJECT

public:
    explicit EZzik(QWidget *parent = 0);
    ~EZzik();

private:
    Ui::EZzik *ui;
};

#endif // EZZIK_H
