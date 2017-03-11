/*
 * playlist-data.h
 * Copyright 2017 John Lindgren
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

#ifndef PLAYLIST_DATA_H
#define PLAYLIST_DATA_H

#include "playlist.h"

struct Entry
{
    Entry (PlaylistAddItem && item);
    ~Entry ();

    void format ();
    void set_tuple (Tuple && new_tuple);

    String filename;
    PluginHandle * decoder;
    Tuple tuple;
    String error;
    int number;
    int length;
    int shuffle_num;
    bool selected, queued;
};

struct PlaylistData
{
    PlaylistData (int id);
    ~PlaylistData ();

    void set_entry_tuple (Entry * entry, Tuple && tuple);
    void number_entries (int at, int length);
    Entry * lookup_entry (int i);

    void set_position (Entry * entry, bool update_shuffle);
    int change_playback ();
    Entry * find_unselected_focus ();

    Playlist::ID * id;
    int number;
    bool modified, scanning, scan_ending;
    String filename, title;
    Index<SmartPtr<Entry>> entries;
    Entry * position, * focus;
    int selected_count;
    int last_shuffle_num;
    Index<Entry *> queued;
    int64_t total_length, selected_length;
    Playlist::Update next_update, last_update;
    int resume_time;
};

#endif // PLAYLIST_DATA_H
