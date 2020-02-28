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
#include "ModelService.h"

#include "NotifySubject.h"
#include "MsgModel.h"

ModelService::ModelService(QObject *parent)
    : QObject(parent)
{
    m_pSubjectThread = g_NotifySubject::getInstance();
    if (m_pSubjectThread) {
        m_pSubjectThread->startThreadRun();
    }
}

ModelService::~ModelService()
{
    if (m_pSubjectThread) {
        m_pSubjectThread->stopThreadRun();
    }
}

void ModelService::addObserver(IObserver *obs)
{
    if (m_pSubjectThread) {
        m_pSubjectThread->addObserver(obs);
    }
}

void ModelService::removeObserver(IObserver *obs)
{
    if (m_pSubjectThread) {
        m_pSubjectThread->removeObserver(obs);
    }
}

void ModelService::notifyMsg(const int &msgType, const QString &msgContent)
{
    if (m_pSubjectThread) {
        m_pSubjectThread->notifyMsg(msgType, msgContent);
    }
}