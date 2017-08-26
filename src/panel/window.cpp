/*
 * This file is part of budgie-rd
 *
 * Copyright © 2017 Ikey Doherty <ikey@solus-project.com>
 *
 * budgie-rd is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#include "window.h"
#include <QDebug>

namespace Budgie::Panel
{
    Window::Window()
    {
        qDebug() << "I r have a panel";

        // Push dock bits
        setAttribute(Qt::WA_TranslucentBackground);
        setAttribute(Qt::WA_X11NetWmWindowTypeDock);
        setAttribute(Qt::WA_X11DoNotAcceptFocus);
    }

    void Window::updateGeometry(QRect &rect)
    {
        qDebug() << "Update geom plox.";
    }
}