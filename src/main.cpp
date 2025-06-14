/*
 * Copyright (C) Robert Lainé & Jeremy Lainé
 * See AUTHORS file for a full list of contributors.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "app.h"

/** @mainpage
 * This is the documentation for Sailcut CAD's code.
 *
 * It is intended mainly for programmers, to learn more about Sailcut CAD
 * please visit https://www.sailcut.org/
*/

/**
 * Sailcut CAD's main routine.
 * it calls CFormmain
 */
int main( int argc, char* argv[] )
{
    int retCode;

    CSailApp app( argc, argv );
    app.readPrefs();

    if (argc > 1) {
        app.open(argv[1]);
    } else {
        app.createSail();
    }

    retCode = app.exec();
    app.writePrefs();

    return retCode;
}

