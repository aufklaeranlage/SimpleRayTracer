#include "graphics.h"
#include "tuple.h"

int	main(void) {
	t_scr	s;
	t_tup	red = colr(FPT_ONE, 0, 0);

	if (!scr_init(&s))
		return (1);
	if (!scr_win_new(&s, 960, 540, "test"))
		return (scr_dest(&s), 2);
	if (!scr_img_new(&s))
		return (scr_dest(&s), 3);
	for (int i = 0; i < 540; i++) {
		scr_put_tup(&s, i, i, &red);
	}
	scr_serve(&s);
	mlx_loop(s.cid);
	scr_dest(&s);
	return (0);
}
