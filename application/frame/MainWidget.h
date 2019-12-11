#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "CustomControl/CustomWidget.h"
#include <DSpinner>

/**
 * @brief The MainWidget class
 * @brief   采用　栈式　显示窗口，　当前只显示某一特定窗口
 */

class MainWidget : public CustomWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(MainWidget)

public:
    explicit MainWidget(CustomWidget *parent = nullptr);

signals:
    void sigOpenFileStart();
    void sigOpenFileOk();
    void sigOpenFileFail(const QString &);
    void sigShowTips(const QString &);
    void sigStartFind();
    void sigStopFind();

protected:
    void dragEnterEvent(QDragEnterEvent *event) Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;

private slots:
    void slotOpenFileFail(const QString &);
    void slotOpenFileOk();
    void slotOpenFileStart();
    void slotShowTips(const QString &contant);

private:
    void initConnections();
    DSpinner *m_spinner = nullptr;

    // IObserver interface
public:
    int dealWithData(const int &, const QString &) Q_DECL_OVERRIDE;

    // CustomWidget interface
protected:
    void initWidget() Q_DECL_OVERRIDE;
};

#endif  // MAINSTACKWIDGET_H
