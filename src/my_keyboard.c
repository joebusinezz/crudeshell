#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

struct termios old_termios;

void enable_rawmode() {
    if ( tcgetattr(STDIN_FILENO, &old_termios)==-1 ) { exit(1); };
    struct termios new_termios = old_termios;
    new_termios.c_lflag &= ~(ICANON | IEXTEN | ISIG | ECHO);
    new_termios.c_iflag &= ~(IXON | ICRNL);
    new_termios.c_cc[VMIN] = 0;
    new_termios.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

void disable_rawmode() {
      if ( tcsetattr(STDIN_FILENO, TCSAFLUSH, &old_termios)==-1 ) { exit(1);};
}

int get_keychar() {
    enable_rawmode();
    int read_count = 0;
    int key = '\0';
    
    while ( (read_count = read(STDIN_FILENO, &key, 1) != 1) ) {
        if (read_count == -1) { exit(1);}
    }
    if (key == '\x1b') {
        char esc_seq[3];
        
        if ( read(STDIN_FILENO, &esc_seq[0], 1) !=1 ) { disable_rawmode(); return '\x1b';}
        if ( read(STDIN_FILENO, &esc_seq[1], 1) !=1 ) { disable_rawmode(); return '\x1b';}
        read(STDIN_FILENO, &esc_seq[2], 1);
        disable_rawmode();
        
        if (esc_seq[0] == '[') {
            switch (esc_seq[1]) {
                case 'A': return -8;
                case 'B': return -2;
                case 'C': return -6;
                case 'D': return -4;
                case 'E': return -5;
                case 'F': return -1;
                case 'H': return -7;
                case '5': if ( esc_seq[2] == '~' ) { return -9;};
                case '6': if ( esc_seq[2] == '~' ) { return -3;};
            }
        }
        
        return '\x1b';
    } else {
        disable_rawmode();
        return key;
    }
}
