/*
 * Copyright (C) 2019 ~ 2020 UOS Technology Co., Ltd.
 *
 * Author:     wangzhxiaun
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "CustomMenu.h"

#include <DFontSizeManager>

#include <QJsonObject>
#include <QJsonDocument>

#include "business/FileDataManager.h"

CustomMenu::CustomMenu(const QString &, DWidget *parent)
    : DMenu(parent)
{
    DFontSizeManager::instance()->bind(this, DFontSizeManager::T6);
}

void CustomMenu::sendMsg(const int &msgType, const QString &msgContent)
{
    notifyMsg(msgType, msgContent);
}

void CustomMenu::notifyMsg(const int &msgType, const QString &msgContent)
{
    dApp->m_pModelService->notifyMsg(msgType, msgContent);
}
