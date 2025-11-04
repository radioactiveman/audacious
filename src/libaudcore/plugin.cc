/*
 * plugin.cc
 * Copyright 2005-2013 Ariadne Conill, Yoshiki Yazawa, Eugene Zagidullin, and
 *                     John Lindgren
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

#include "plugin.h"

bool Plugin::init() { return true; }

void Plugin::cleanup() {}

int Plugin::take_message(const char * code, const void * data, int size)
{
    return -1;
}

VFSFileTest TransportPlugin::test_file(const char * filename, VFSFileTest test,
                                       String & error)
{
    return VFSFileTest(0);
}

Index<String> TransportPlugin::read_folder(const char * filename, String & error)
{
    return Index<String>();
}

bool PlaylistPlugin::save(const char * path, VFSFile & file, const char * title,
                          const Index<PlaylistAddItem> & items)
{
    return false;
}

void OutputPlugin::set_info(const char * filename, const Tuple & tuple) {}

bool EffectPlugin::flush(bool force) { return true; }

Index<float> & EffectPlugin::finish(Index<float> & data, bool end_of_playlist)
{
    return process(data);
}

int EffectPlugin::adjust_delay(int delay) { return delay; }

bool InputPlugin::write_tuple(const char * filename, VFSFile & file,
                              const Tuple & tuple)
{
    return false;
}

bool InputPlugin::file_info_box(const char * filename, VFSFile & file)
{
    return false;
}

void * DockablePlugin::get_gtk_widget() { return nullptr; }

void * DockablePlugin::get_qt_widget() { return nullptr; }

void IfacePlugin::startup_notify(const char * id) {}
