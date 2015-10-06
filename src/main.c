/**
 *	Copyright (C) 2015 Stuart Bassett
 *
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <config.h>
#include <locale.h>
#include "gettext.h"
#define _(string) gettext(string)

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

#include "skeleton.h"

void version(FILE *f) {
	printf("%s\n", PACKAGE_STRING);
}

void help(FILE *f) {
	printf("%s\n\n%s\n\n%s\n%s\n",
PACKAGE_STRING,
"Copyright (C) 2015 Stuart Bassett",
_("usage:"),
_("\
--help, -h           print this text\n\
--version, -v        print the package version")
	);
}

int main(int argc, char **argv)
{
	int c;
	int option_index;
	static struct option long_options[] = {
		{"version", no_argument, 0, 'v'},
		{"help"   , no_argument, 0, 'h'},
		{0        ,0           , 0, 0}
	};

	setlocale(LC_ALL, "");

	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);

	while((c = getopt_long(argc, argv, "hv", long_options, &option_index)) != -1)
	{
		switch(c)
		{
			case 'v':
				version(stdout); exit(EXIT_SUCCESS);
			case 'h':
				help(stdout); exit(EXIT_SUCCESS);
			default:
				help(stderr); exit(EXIT_FAILURE);
		}
	}

	hello_world();
	return EXIT_SUCCESS;
}
