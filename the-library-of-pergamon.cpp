#include <ncurses.h>
#include <string>

using namespace std;

void ListBooks(string *booklist, WINDOW *win, int selected_book);

int main(int argc, char **argv) {

  initscr();
  noecho();
  cbreak();

  // TODO: Make dynamic window sizes.
  // COLS = 189 // LINES = 50 //
  // Favs -> Reading -> Recents | Book View | Pending -> Done -> Uncated

  int leftpane_w = 40, leftpane_h = 25;
  int middlepane_w = 109, middlepane_h = 50;
  int rightpane_w = 40, rightpane_h = 25;

  int inprog_h = leftpane_h, inprog_w = leftpane_w, inprog_y = 1, inprog_x = 0;
  int recent_h = leftpane_h, recent_w = leftpane_w, recent_y = 26, recent_x = 0;
  int bookview_h = middlepane_h, bookview_w = middlepane_w, bookview_y = 1,
      bookview_x = 40;
  int pending_h = rightpane_h, pending_w = rightpane_w, pending_y = 1,
      pending_x = 149;
  int done_h = rightpane_h, done_w = rightpane_w, done_y = 26, done_x = 149;

  // MARK: Windows =
  WINDOW *inprog = newwin(inprog_h, inprog_w, inprog_y, inprog_x);
  box(inprog, 0, 0);
  WINDOW *recent = newwin(recent_h, recent_w, recent_y, recent_x);
  box(recent, 0, 0);
  WINDOW *bookview = newwin(bookview_h, bookview_w, bookview_y, bookview_x);
  box(bookview, 0, 0);
  WINDOW *pending = newwin(pending_h, pending_w, pending_y, pending_x);
  box(pending, 0, 0);
  WINDOW *done = newwin(done_h, done_w, done_y, done_x);
  box(done, 0, 0);

  refresh();

  // MARK: Window Lables =
  mvwprintw(inprog, 0, 2, "Reading List");
  wrefresh(inprog);

  mvwprintw(recent, 0, 2, "Recents");
  wrefresh(recent);

  mvwprintw(bookview, 0, 2, "Book View");
  wrefresh(bookview);

  mvwprintw(pending, 0, 2, "Pending");
  wrefresh(pending);

  mvwprintw(done, 0, 2, "Done");
  wrefresh(done);

  refresh();

  keypad(inprog, true);

  string books[3] = {"Book A", "Book B", "Book C"};
  int selected_book = 0;

  ListBooks(books, inprog, selected_book);

  refresh();

  int selection;

  while ((selection = wgetch(inprog))) {
  }

  endwin();

  return 0;
}

// MARK: ListBooks()
void ListBooks(string *booklist, WINDOW *win, int selected_book) {

  for (int book_order = 0; book_order < 3; book_order++) {

    if (book_order == selected_book) {

      wattron(win, A_REVERSE);
    }
    mvwprintw(win, book_order + 2, 2, "%s", booklist[book_order].c_str());
    wrefresh(win);
    wattroff(win, A_REVERSE);
  }
  wrefresh(win);
}

// TODO: Fix this (KeyMaps).
// MARK: KeyMaps()
/* void KeyMaps(char key) { */

/*   switch (selection) { */

/*   case KEY_UP: */
/*     if (selected_book > 0) { */
/*       --selected_book; */
/*       ListBooks(books, inprog, selected_book); */
/*     } */
/*     break; */
/*   case KEY_DOWN: */
/*     if (selected_book < 2) { */
/*       ++selected_book; */
/*       ListBooks(books, inprog, selected_book); */
/*     } */
/*     break; */
/*   case 10: */
/*     mvwprintw(bookview, 1, 2, "%s", books[selected_book].c_str()); */
/*     wrefresh(bookview); */
/*     break; */
/*   } */
/* } */
