/*
 * util-qt.cc
 * Copyright 2017 René Bertin and John Lindgren
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions, and the following disclaimer in the documentation
 *    provided with the distribution.
 *
 * This software is provided "as is" and without any warranty, express or
 * implied. In no event shall the authors be liable for any damages arising from
 * the use of this software.
 */

#include "libaudqt.h"
#include "libaudqt-internal.h"

#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QMenu>
#include <QMimeData>

#include <libaudcore/i18n.h>

namespace audqt {

void show_copy_context_menu (QWidget * parent, const QPoint & global_pos,
 const QString & text_to_copy)
{
    auto menu = new QMenu (parent);
    auto action = new QAction (audqt::get_icon ("edit-copy"), N_("Copy"), menu);

    QObject::connect (action, & QAction::triggered, action, [text_to_copy] () {
        auto data = new QMimeData;
        data->setText (text_to_copy);
        QApplication::clipboard ()->setMimeData (data);
    });

    /* delete the menu as soon as it's closed */
    QObject::connect (menu, & QMenu::aboutToHide, [menu] () {
        menu->deleteLater ();
    });

    menu->addAction (action);
    menu->popup (global_pos);
}

} // namespace audqt