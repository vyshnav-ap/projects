#ifndef mp3_H
#define mp3_H

void mp3tag_reader(const char *filename);
void mp3_view(const char *filename);

void edit_text_frame(const char *filename, const char *frame_id, const char *text);

void mp3_edit_title(const char *text, const char *filename);
void mp3_edit_artist(const char *text, const char *filename);
void mp3_edit_album(const char *text, const char *filename);
void mp3_edit_year(const char *text, const char *filename);
void mp3_edit_comment(const char *text, const char *filename);
void mp3_edit_track(const char *text, const char *filename);
#endif
