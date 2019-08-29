#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include <DObject>
#include <DWidget>
#include <QVBoxLayout>
#include <DLabel>
#include <QFileDialog>
#include <QSettings>
#include "dlinkbutton.h"

#include "header/IThemeObserver.h"
#include "header/ThemeSubject.h"

/**
 *  @brief  支持拖拽
 *  @brief  打开pdf 文件
 */


DWIDGET_USE_NAMESPACE

class HomeWidget : public DWidget, public IThemeObserver
{
    Q_OBJECT
public:
    HomeWidget(DWidget *parent = nullptr);
    ~HomeWidget();

    void setIconPixmap(bool isLoaded);

signals:
    void fileSelected(const QStringList files) const;

private slots:
    void onChooseBtnClicked();

private:
    QVBoxLayout     *m_layout = nullptr;
    QPixmap         m_unloadPixmap;
    QPixmap         m_loadedPixmap;
    DLabel          *m_iconLabel = nullptr;
    DLabel          *m_tipsLabel = nullptr;
    DLabel          *m_splitLine = nullptr;
    DLinkButton     *m_chooseBtn = nullptr;
    QSettings       *m_settings = nullptr;

    ThemeSubject    *m_pThemeSubject = nullptr;

    // IObserver interface
public:
    int update(const QString &);
};

#endif // OPENFILEWIDGET_H
