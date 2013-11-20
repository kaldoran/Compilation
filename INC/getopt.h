/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/*
 * This file was copied from the following newsgroup posting:
 *
 * Newsgroups: mod.std.unix
 * Subject: public domain AT&T getopt source
 * Date: 3 Nov 85 19:34:15 GMT
 *
 * Here's something you've all been waiting for: the AT&T public domain
 * source for getopt(3). It is the code which was given out at the 1985
 * UNIFORUM conference in Dallas. I obtained it by electronic mail
 * directly from AT&T. The people there assure me that it is indeed
 * in the public domain.
 */

int getopt(int argc, char *argv[], char *opts);
