#include "BookMarkStateLabel.h"
#include "subjectObserver/ModuleHeader.h"
#include "subjectObserver/MsgHeader.h"
#include "controller/MsgSubject.h"

BookMarkStateLabel::BookMarkStateLabel(DWidget *parent)
    : QLabel (parent)
{
    setFixedSize(QSize(39, 39));

    setMouseTracking(true);
    setObserverName("");

    m_pMsgSubject = MsgSubject::getInstance();
    if (m_pMsgSubject) {
        m_pMsgSubject->addObserver(this);
    }
    m_pNotifySubject = NotifySubject::getInstance();
    if (m_pNotifySubject) {
        m_pNotifySubject->addObserver(this);
    }
}

void BookMarkStateLabel::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bChecked) {
        setToolTip(tr("delete bookmark"));
        setPixmapState(ImageModule::g_checked_state);
    } else {
        setToolTip(tr("add bookmark"));
        setPixmapState(ImageModule::g_hover_state);
    }
    DLabel::mouseMoveEvent(event);
}

void BookMarkStateLabel::mousePressEvent(QMouseEvent *event)
{
    m_bChecked = !m_bChecked;

    if (!m_bChecked) {
        setPixmapState(ImageModule::g_press_state);
        sendMsg(MSG_BOOKMARK_DLTITEM);
    } else {
        setPixmapState(ImageModule::g_checked_state);
        sendMsg(MSG_BOOKMARK_ADDITEM);
    }

    DLabel::mousePressEvent(event);
}

void BookMarkStateLabel::leaveEvent(QEvent *event)
{
    if (m_bChecked) {
        setPixmapState(ImageModule::g_checked_state);
    } else {
        this->clear();
    }

    DLabel::leaveEvent(event);
}

void BookMarkStateLabel::setPixmapState(const QString &state)
{
    QString ssPath = QString(":/resources/image/%1/bookmark.svg").arg(state);
    QPixmap pixmap(ssPath);
    this->setPixmap(pixmap);
}

void BookMarkStateLabel::setMarkState(const bool &bCheck)
{
    m_bChecked = bCheck;

    if (!m_bChecked) {
        this->clear();
    } else {
        setPixmapState(ImageModule::g_checked_state);
    }
}

bool BookMarkStateLabel::bChecked() const
{
    return m_bChecked;
}

int BookMarkStateLabel::dealWithData(const int &msgType, const QString &msgContent)
{
    if (msgType == MSG_BOOKMARK_STATE) {     //  当前页的书签状态
        setMarkState(msgContent.toInt());
        return ConstantMsg::g_effective_res;
    }
    return 0;
}

void BookMarkStateLabel::sendMsg(const int &msgType, const QString &msgContent)
{
    m_pMsgSubject->sendMsg(this, msgType, msgContent);
}

void BookMarkStateLabel::setObserverName(const QString &)
{
    m_strObserverName = "BookMarkStateLabel";
}
