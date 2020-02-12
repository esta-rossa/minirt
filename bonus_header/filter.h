#ifndef FT_FILTER_H
# define FT_FILTER_H
# define FILTER_X 9
# define FILTER_Y 9
extern const double g_filter[FILTER_X][FILTER_Y];
void		filter(int *img);
#endif
