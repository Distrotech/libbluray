/*
 * This file is part of libbluray
 * Copyright (C) 2009-2010  John Stebbins
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef DIR_H_
#define DIR_H_

#include <util/attributes.h>

#define dir_open dir_open_posix

#define dir_close(X) X->close(X)
#define dir_read(X,Y) X->read(X,Y)

// Our dirent struct only contains the parts we care about.
typedef struct
{
    char    d_name[256];
} BD_DIRENT;

typedef struct bd_dir_s BD_DIR_H;
struct bd_dir_s
{
    void* internal;
    void (*close)(BD_DIR_H *dir);
    int (*read)(BD_DIR_H *dir, BD_DIRENT *entry);
};

BD_PRIVATE BD_DIR_H *dir_open_posix(const char* dirname);

#endif /* DIR_H_ */
