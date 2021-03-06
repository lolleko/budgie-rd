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

#include <QCoreApplication>
#include <QDir>
#include <QHash>
#include <QProcessEnvironment>
#include <QSharedPointer>

#include "desktop-file.h"

namespace Session
{
    class Manager : public QCoreApplication
    {
        Q_OBJECT

    public:
        explicit Manager(const QString &xdgDesktopName, int &argc, char **argv);

    private:
        QList<QDir> appDirs;
        QString homeDir;
        const QString xdgDesktopName;
        QProcessEnvironment execEnviron;
        QHash<QString, QSharedPointer<Desktop::DesktopFile>> xdgAutostarts;
        Desktop::AutostartPhase currentPhase;
        QHash<Desktop::AutostartPhase,
              QSharedPointer<QHash<QString, QSharedPointer<Desktop::DesktopFile>>>>
            applications;

        /**
         * Quick helper to determine if a given autostart directory actually
         * does exist or not.
         */
        void appendAutostartDirectory(const QString &directory);

        /**
         * Scan the startup directories to find any applications requesting they
         * be automatically started within this session.
         */
        void scanAutostartApps();

        /**
         * Scan specifically for session applications
         */
        void scanSessionApps(const QString &sessionDirectory);

        /**
         * Push the DesktopFile into the internal storage, and take ownership
         * of this item.
         *
         * Any item with an invalid AutostartPhase will be moved back to the
         * Applications cycle.
         */
        void pushAutostart(Desktop::DesktopFile *file);

        /**
         * Attempt to launch the next phase in the start up sequence.
         */
        void launchPhase(Desktop::AutostartPhase phase);
    };
}

/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=4 tabstop=4 expandtab:
 * :indentSize=4:tabSize=4:noTabs=true:
 */
