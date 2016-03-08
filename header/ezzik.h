#ifndef EZZIK_H
#define EZZIK_H

#include <QWidget>
#include <QVBoxLayout>

namespace Ui {
class EZzik;
}

class EZzik : public QWidget
{
    Q_OBJECT

public:
    explicit EZzik(QWidget *parent = 0);
    ~EZzik();
    void launch();
    void InitPartition();

private:
    Ui::EZzik *ui;
    QVBoxLayout* vLayout;
};

#endif // EZZIK_H
