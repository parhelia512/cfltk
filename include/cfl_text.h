#ifndef __CFL_TEXT_H__
#define __CFL_TEXT_H__

#include "cfl_macros.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DISPLAY_DECLARE(widget)                                                \
    int widget##_text_font(const widget *);                                    \
    void widget##_set_text_font(widget *, int s);                              \
    int widget##_text_size(const widget *);                                    \
    void widget##_set_text_size(widget *, int s);                              \
    unsigned int widget##_text_color(const widget *);                          \
    void widget##_set_text_color(widget *, unsigned int n);                    \
    void widget##_scroll(widget *, int topLineNum, int horizOffset);           \
    void widget##_insert(widget *, const char *text);                          \
    void widget##_set_insert_position(widget *, int newPos);                   \
    int widget##_insert_position(const widget *);                              \
    int widget##_position_to_xy(const widget *self, int pos, int *x, int *y);  \
    int widget##_count_lines(                                                  \
        const widget *, int start, int end, int start_pos_is_line_start        \
    );                                                                         \
    int widget##_move_right(widget *);                                         \
    int widget##_move_left(widget *);                                          \
    int widget##_move_up(widget *);                                            \
    int widget##_move_down(widget *);                                          \
    void widget##_show_cursor(widget *, int boolean);                          \
    void widget##_set_highlight_data(                                          \
        widget *self,                                                          \
        void *sbuff,                                                           \
        unsigned int *color,                                                   \
        int *font,                                                             \
        int *fontsz,                                                           \
        unsigned *attr,                                                        \
        unsigned int *bgcolor,                                                 \
        int sz                                                                 \
    );                                                                         \
    void widget##_set_cursor_style(widget *, int style);                       \
    void widget##_set_cursor_color(widget *, unsigned int color);              \
    void widget##_set_scrollbar_size(widget *, int newSize);                   \
    void widget##_set_scrollbar_align(widget *, int align);                    \
    int widget##_cursor_style(widget *);                                       \
    unsigned int widget##_cursor_color(widget *);                              \
    int widget##_scrollbar_size(widget *);                                     \
    int widget##_scrollbar_align(widget *);                                    \
    int widget##_line_start(const widget *self, int pos);                      \
    int widget##_line_end(                                                     \
        const widget *self, int startPos, int startPosIsLineStart              \
    );                                                                         \
    int widget##_skip_lines(                                                   \
        widget *self, int startPos, int nLines, int startPosIsLineStart        \
    );                                                                         \
    int widget##_rewind_lines(widget *self, int startPos, int nLines);         \
    void widget##_next_word(widget *self);                                     \
    void widget##_previous_word(widget *self);                                 \
    int widget##_word_start(const widget *self, int pos);                      \
    int widget##_word_end(const widget *self, int pos);                        \
    double widget##_x_to_col(const widget *self, double x);                    \
    double widget##_col_to_x(const widget *self, double col);                  \
    void widget##_set_linenumber_width(widget *self, int width);               \
    int widget##_linenumber_width(const widget *self);                         \
    void widget##_set_linenumber_font(widget *self, int val);                  \
    int widget##_linenumber_font(const widget *self);                          \
    void widget##_set_linenumber_size(widget *self, int val);                  \
    int widget##_linenumber_size(const widget *self);                          \
    void widget##_set_linenumber_fgcolor(widget *self, unsigned int val);      \
    unsigned int widget##_linenumber_fgcolor(const widget *self);              \
    void widget##_set_linenumber_bgcolor(widget *self, unsigned int val);      \
    unsigned int widget##_linenumber_bgcolor(const widget *self);              \
    void widget##_set_linenumber_align(widget *self, int val);                 \
    int widget##_linenumber_align(const widget *self);                         \
    int widget##_in_selection(const widget *self, int x, int y);               \
    void widget##_wrap_mode(widget *self, int wrap, int wrap_margin);          \
    int widget##_wrapped_column(const widget *self, int row, int column);      \
    int widget##_wrapped_row(const widget *self, int row);                     \
    void widget##_set_grammar_underline_color(                                 \
        widget *self, unsigned int color                                       \
    );                                                                         \
    unsigned int widget##_grammar_underline_color(const widget *self);         \
    void widget##_set_spelling_underline_color(                                \
        widget *self, unsigned int color                                       \
    );                                                                         \
    unsigned int widget##_spelling_underline_color(const widget *self);        \
    void widget##_set_secondary_selection_color(                               \
        widget *self, unsigned int color                                       \
    );                                                                         \
    unsigned int widget##_secondary_selection_color(const widget *self);       \
    void widget##_show_insert_position(widget *self);                          \
    void widget##_overstrike(widget *self, const char *text);

typedef void (*Fl_Text_Modify_Cb)(
    int pos,
    int nInserted,
    int nDeleted,
    int nRestyled,
    const char *deletedText,
    void *cbArg
);

typedef struct Fl_Text_Buffer Fl_Text_Buffer;

Fl_Text_Buffer *Fl_Text_Buffer_new(void);

void Fl_Text_Buffer_delete(Fl_Text_Buffer *);

const char *Fl_Text_Buffer_text(Fl_Text_Buffer *self);

void Fl_Text_Buffer_set_text(Fl_Text_Buffer *self, const char *txt);

void Fl_Text_Buffer_append(Fl_Text_Buffer *self, const char *txt);

void Fl_Text_Buffer_append_bytes(Fl_Text_Buffer *self, const char *txt, int len);

void Fl_Text_Buffer_remove(Fl_Text_Buffer *self, int start, int end);

int Fl_Text_Buffer_length(const Fl_Text_Buffer *self);

char *Fl_Text_Buffer_text_range(const Fl_Text_Buffer *self, int start, int end);

void Fl_Text_Buffer_insert(Fl_Text_Buffer *self, int pos, const char *text);

void Fl_Text_Buffer_replace(
    Fl_Text_Buffer *self, int start, int end, const char *text
);

void Fl_Text_Buffer_copy(
    Fl_Text_Buffer *self,
    Fl_Text_Buffer *fromBuf,
    int fromStart,
    int fromEnd,
    int toPos
);

int Fl_Text_Buffer_undo(Fl_Text_Buffer *self, int *cp);

void Fl_Text_Buffer_canUndo(Fl_Text_Buffer *self, char flag);

int Fl_Text_Buffer_can_undo(const Fl_Text_Buffer *self);

int Fl_Text_Buffer_load_file(Fl_Text_Buffer *self, const char *file);

int Fl_Text_Buffer_save_file(Fl_Text_Buffer *self, const char *file);

int Fl_Text_Buffer_tab_distance(const Fl_Text_Buffer *self);

void Fl_Text_Buffer_set_tab_distance(Fl_Text_Buffer *self, int tabDist);

void Fl_Text_Buffer_select(Fl_Text_Buffer *self, int start, int end);

int Fl_Text_Buffer_selected(const Fl_Text_Buffer *self);

void Fl_Text_Buffer_unselect(Fl_Text_Buffer *self);

int Fl_Text_Buffer_selection_position(
    Fl_Text_Buffer *self, int *start, int *end
);

char *Fl_Text_Buffer_selection_text(Fl_Text_Buffer *self);

void Fl_Text_Buffer_remove_selection(Fl_Text_Buffer *self);

void Fl_Text_Buffer_replace_selection(Fl_Text_Buffer *self, const char *text);

void Fl_Text_Buffer_secondary_select(Fl_Text_Buffer *self, int start, int end);

int Fl_Text_Buffer_secondary_selected(Fl_Text_Buffer *self);

void Fl_Text_Buffer_secondary_unselect(Fl_Text_Buffer *self);

int Fl_Text_Buffer_secondary_selection_position(
    Fl_Text_Buffer *self, int *start, int *end
);

char *Fl_Text_Buffer_secondary_selection_text(Fl_Text_Buffer *self);

void Fl_Text_Buffer_remove_secondary_selection(Fl_Text_Buffer *self);

void Fl_Text_Buffer_replace_secondary_selection(
    Fl_Text_Buffer *self, const char *text
);

void Fl_Text_Buffer_highlight(Fl_Text_Buffer *self, int start, int end);

int Fl_Text_Buffer_is_highlighted(Fl_Text_Buffer *self);

void Fl_Text_Buffer_unhighlight(Fl_Text_Buffer *self);

int Fl_Text_Buffer_highlight_position(
    Fl_Text_Buffer *self, int *start, int *end
);

char *Fl_Text_Buffer_highlight_text(Fl_Text_Buffer *self);

char *Fl_Text_Buffer_line_text(const Fl_Text_Buffer *self, int pos);

int Fl_Text_Buffer_line_start(const Fl_Text_Buffer *self, int pos);

int Fl_Text_Buffer_word_start(const Fl_Text_Buffer *self, int pos);

int Fl_Text_Buffer_word_end(const Fl_Text_Buffer *self, int pos);

int Fl_Text_Buffer_count_lines(
    const Fl_Text_Buffer *self, int startPos, int endPos
);

void Fl_Text_Buffer_add_modify_callback(
    Fl_Text_Buffer *self, Fl_Text_Modify_Cb bufModifiedCB, void *cbArg
);

void Fl_Text_Buffer_remove_modify_callback(
    Fl_Text_Buffer *self, Fl_Text_Modify_Cb bufModifiedCB, void *cbArg
);

void Fl_Text_Buffer_call_modify_callbacks(Fl_Text_Buffer *self);

int Fl_Text_Buffer_search_forward(
    const Fl_Text_Buffer *self,
    int start_pos,
    const char *search_string,
    int *found_pos,
    int match_case
);

int Fl_Text_Buffer_search_backward(
    const Fl_Text_Buffer *self,
    int start_pos,
    const char *search_string,
    int *found_pos,
    int match_case
);

int Fl_Text_Buffer_findchar_forward(
    const Fl_Text_Buffer *self,
    int start_pos,
    unsigned int search_char,
    int *found_pos
);

int Fl_Text_Buffer_findchar_backward(
    const Fl_Text_Buffer *self,
    int start_pos,
    unsigned int search_char,
    int *found_pos
);

int Fl_Text_Buffer_redo(Fl_Text_Buffer *self, int *cp);

int Fl_Text_Buffer_can_redo(const Fl_Text_Buffer *self);

WIDGET_DECLARE(Fl_Text_Display)

void Fl_Text_Display_init(Fl_Text_Display *);

Fl_Text_Buffer *Fl_Text_Display_get_buffer(Fl_Text_Display *);

void Fl_Text_Display_set_buffer(Fl_Text_Display *, Fl_Text_Buffer *);

Fl_Text_Buffer *Fl_Text_Display_get_style_buffer(Fl_Text_Display *);

DISPLAY_DECLARE(Fl_Text_Display)

WIDGET_DECLARE(Fl_Text_Editor)

void Fl_Text_Editor_init(Fl_Text_Editor *);

Fl_Text_Buffer *Fl_Text_Editor_get_buffer(Fl_Text_Editor *);

void Fl_Text_Editor_set_buffer(Fl_Text_Editor *, Fl_Text_Buffer *);

Fl_Text_Buffer *Fl_Text_Editor_get_style_buffer(Fl_Text_Editor *);

DISPLAY_DECLARE(Fl_Text_Editor)

int Fl_Text_Editor_kf_copy(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_cut(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_paste(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_undo(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_redo(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_default(int c, Fl_Text_Editor *e);

int Fl_Text_Editor_kf_ignore(int c, Fl_Text_Editor *e);

int Fl_Text_Editor_kf_backspace(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_enter(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_move(int c, Fl_Text_Editor *e);

int Fl_Text_Editor_kf_shift_move(int c, Fl_Text_Editor *e);

int Fl_Text_Editor_kf_ctrl_move(int c, Fl_Text_Editor *e);

int Fl_Text_Editor_kf_c_s_move(int c, Fl_Text_Editor *e);

int Fl_Text_Editor_kf_meta_move(int c, Fl_Text_Editor *e);

int Fl_Text_Editor_kf_m_s_move(int c, Fl_Text_Editor *e);

int Fl_Text_Editor_kf_home(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_end(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_left(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_up(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_right(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_down(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_page_up(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_page_down(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_insert(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_delete(Fl_Text_Editor *e);

int Fl_Text_Editor_kf_select_all(Fl_Text_Editor *e);

void Fl_Text_Editor_set_insert_mode(Fl_Text_Editor *self, int b);

int Fl_Text_Editor_insert_mode(Fl_Text_Editor *self);

void Fl_Text_Editor_set_tab_nav(Fl_Text_Editor *self, int val);

int Fl_Text_Editor_tab_nav(const Fl_Text_Editor *self);

void Fl_Text_Editor_add_key_binding(
    Fl_Text_Editor *self, int key, int state, int (*kf)(int, Fl_Text_Editor *)
);

void Fl_Text_Editor_remove_key_binding(
    Fl_Text_Editor *self, int key, int state
);

void Fl_delete_stable(void *);

#ifdef __cplusplus
}
#endif
#endif
