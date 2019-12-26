#ifndef DEFAULTOPERATIONMENU_H
#define DEFAULTOPERATIONMENU_H

#include <DMenu>
#include <QAction>

DWIDGET_USE_NAMESPACE

/**
 * @brief The DefaultOperationWidget class
 * @brief   右键  默认菜单操作， 搜索、添加书签、第一页、上一页、下一页、最后一页
 */

class DefaultOperationMenu : public DMenu
{
    Q_OBJECT
    Q_DISABLE_COPY(DefaultOperationMenu)

public:
    explicit DefaultOperationMenu(DWidget *parent = nullptr);

public:
    void execMenu(const QPoint &, const int &);

private:
    void initMenu();
    QAction *createAction(const QString &, const char *member);
    void notifyMsgToFrame(const int &, const QString &msgContent = "");

private slots:
    void slotSearchClicked();
    void slotBookMarkClicked();
    void slotFirstPageClicked();
    void slotPrevPageClicked();
    void slotNextPageClicked();
    void slotEndPageClicked();
    void slotExitFullScreenClicked();

private:
    int     m_nRightPageNumber = -1;
    QAction *m_pSearch = nullptr;
    QAction *m_pBookMark = nullptr;
    QAction *m_pFirstPage = nullptr;
    QAction *m_pPrevPage = nullptr;
    QAction *m_pNextPage = nullptr;
    QAction *m_pEndPage = nullptr;
    QAction *m_pExitFullScreen = nullptr;
};

#endif // DEFAULTOPERATIONMENU_H
