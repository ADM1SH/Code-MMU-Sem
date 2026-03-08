import curses
import random
import time

def matrix(stdscr):
    curses.curs_set(0)
    stdscr.nodelay(True)
    stdscr.timeout(50)
    sh, sw = stdscr.getmaxyx()
    columns = [0] * sw

    while True:
        stdscr.clear()
        for i in range(sw):
            char = chr(random.randint(33, 126))
            stdscr.addstr(columns[i], i, char, curses.color_pair(1))
            columns[i] = (columns[i] + 1) % sh
        stdscr.refresh()
        if stdscr.getch() != -1:
            break

curses.wrapper(matrix)