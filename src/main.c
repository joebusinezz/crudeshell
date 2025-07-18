// Copyright (C) 2025  joebusinezz
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "crudeshell.h"
#include <stdio.h>

int main(int argc, char **argv) {
    int c = 0;
    
    printf("[ESC] ");
    fflush(stdout);
	while (c!=27) {
        c = get_keychar();
        switch (c) {
            case -1:
                printf("End"); break;
            case -2:
                printf("Down"); break;
            case -3:
                printf("Next"); break;
            case -4:
                printf("Left"); break;
            case -5:
                printf("Wait"); break;
            case -6:
                printf("Right"); break;
            case -7:
                printf("Home"); break;
            case -8:
                printf("Up"); break;
            case -9:
                printf("Previous"); break;
            case 27:
            case 13:
                printf("\n"); break;
            default:
                printf("%c", c); break;
        }
        fflush(stdout);
    }
	return 0;
}
