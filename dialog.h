#ifndef DIALOG_H
#define DIALOG_H
#include <vector>
#include <QDialog>
#include "note.h"
#include <QPushButton>
#include <QMessageBox>
#include <QCheckBox>
#include <QCloseEvent>
#include "suspenddia.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
Q_OBJECT

public:
    std::vector<Note*> note_vector;
    std::vector<Note*> note_vector_time;
    static bool isSmaller(Note* a,Note* b);
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void onRefresh();
    void onRefresh1();
    void onRefresh_for_time();

    void closeEvent(QCloseEvent *); // 点击“x”按钮
public slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_toSusbendBtn_clicked();

    void on_pushButton_5_toggled(bool checked);

public:
    Ui::Dialog *ui;

private:
    int nextTime = 0;   // 说明有下一次
        SuspendDia *s;
        QString _text;
};
#endif // DIALOG_H
