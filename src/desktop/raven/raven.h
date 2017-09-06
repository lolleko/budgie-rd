/*
 * This file is part of budgie-rd
 *
 * Copyright © 2017 Budgie Desktop Developers
 *
 * budgie-rd is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#pragma once

#include <QQuickView>

namespace Raven
{
    class Window : public QQuickView
    {
        Q_OBJECT

    public:
        explicit Window();
        void updateGeometry(QRect &rect);

    private slots:
        void handleDismiss();
    };
}